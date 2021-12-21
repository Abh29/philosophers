/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:22:35 by mehill            #+#    #+#             */
/*   Updated: 2021/12/21 17:21:54 by mehill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_init_forks(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->p_num + 1)
	{
		philo->forks[i] = malloc (sizeof(pthread_mutex_t));
		if (pthread_mutex_init(philo->forks[i], NULL) != 0)
			return (1);
		i++;
	}
	if (pthread_mutex_init(philo->eating_now_m, NULL) != 0)
		return (1);
	if (pthread_mutex_init(philo->exit_m, NULL) != 0)
		return (1);
	if (pthread_mutex_init(philo->io_m, NULL) != 0)
		return (1);
	if (pthread_mutex_init(philo->end_sim_m, NULL) != 0)
		return (1);
	return (0);
}

int	ft_init_extra_arg(t_philo *philo, int argc, char **argv)
{
	philo->zero_time = 0;
	philo->zero_time = ft_time_stamp(philo);
	philo->args = malloc(sizeof(t_args *));
	if (philo->args == NULL)
		return (4);
	if (argc == 6)
	{
		philo->eat_max = ft_atoi(argv[5]);
		if (philo->eat_max <= 0)
			return (2);
		philo->eat_num = malloc((philo->p_num + 1) * sizeof(int));
		if (philo->eat_num == NULL)
			return (3);
		memset(philo->eat_num, 0, (philo->p_num + 1) * sizeof(int));
	}
	else
		philo->eat_num = NULL;
	return (0);
}

int	ft_mem_allocate(t_philo *philo)
{
	philo->tids = malloc((philo->p_num + 1) * sizeof(pthread_t));
	philo->forks = malloc((philo->p_num + 1) * sizeof(pthread_mutex_t *));
	philo->eating_now = malloc(philo->p_num + 1);
	philo->eating_now_m = malloc(sizeof(pthread_mutex_t));
	philo->exit_m = malloc(sizeof(pthread_mutex_t));
	philo->ate_last = malloc(philo->p_num * sizeof(long));
	philo->io_m = malloc(sizeof(pthread_mutex_t));
	philo->end_sim = malloc(sizeof(int));
	philo->end_sim_m = malloc(sizeof(pthread_mutex_t));
	*philo->end_sim = 0;
	if (philo->tids == NULL || philo->forks == NULL || \
	philo->eating_now == NULL || philo->eating_now_m == NULL || \
	philo->ate_last == NULL || philo->exit_m == NULL || philo->io_m == NULL)
		return (3);
	return (0);
}

int	ft_init(t_philo *philo, int argc, char **argv)
{
	int	ret;

	philo->p_num = ft_atoi(argv[1]);
	philo->die = ft_atoi(argv[2]);
	philo->eat = ft_atoi(argv[3]);
	philo->sleep = ft_atoi(argv[4]);
	if (philo->p_num <= 1 || philo->die <= 0 || \
	philo->eat <= 0 || philo->eat <= 0 || philo->sleep <= 0)
		return (2);
	ret = ft_init_extra_arg(philo, argc, argv);
	if (ret != 0)
		return (ret);
	ret = ft_mem_allocate(philo);
	if (ret != 0)
		return (ret);
	memset(philo->eating_now, 0, philo->p_num);
	memset(philo->ate_last, 0, philo->p_num * sizeof(long));
	return (ft_init_forks(philo));
}

int	ft_exit_msg(int err, int fd)
{
	if (err == 1)
		ft_putstr_fd("Error : could not init a mutex \n", fd);
	else if (err == 2)
		ft_putstr_fd("Error : incorrect arguments (negative values) \n", fd);
	else if (err == 3)
		ft_putstr_fd("Error : malloc error could not initiate \
		philo structure \n", fd);
	else if (err == 4)
		ft_putstr_fd("Error : could not allocate memory for args !\n", fd);
	else if (err == 5)
		ft_putstr_fd("Error : could not allocate memory !\n", fd);
	else if (err == 6)
		ft_putstr_fd("Error : could not create a thread !\n", fd);
	else if (err == 7)
		ft_putstr_fd("Error : wrong number of arguments !\n", fd);
	return (err);
}
