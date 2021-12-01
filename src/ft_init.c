/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:22:35 by mehill            #+#    #+#             */
/*   Updated: 2021/12/01 19:33:37 by mehill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_init_forks(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->p_num)
	{
		if (pthread_mutex_init(&(philo->forks[i]), NULL) != 0)
			ft_exit("Error : could not init a mutex \n", 2, 1);
		i++;
	}
	if (pthread_mutex_init(philo->eating_now_m, NULL) != 0)
		ft_exit("Error : could not init a mutex !\n", 2, 1);
}

void	ft_init_extra_arg(t_philo *philo, int argc, char **argv)
{
	philo->zero_time = 0;
	philo->zero_time = ft_time_stamp(philo);
	if (argc == 6)
	{
		philo->eat_max = ft_atoi(argv[5]);
		if (philo->eat_max <= 0)
			ft_exit("Error : incorrect arguments (negative values) !\n", 2, 1);
		philo->eat_num = malloc((philo->p_num + 1) * sizeof(int));
		if (philo->eat_num == NULL)
			ft_exit("Error : malloc error could not initiate \
			philo structure!\n", 2, 1);
		memset(philo->eat_num, 0, (philo->p_num + 1) * sizeof(int));
	}
	else
		philo->eat_num = NULL;
}

void	ft_init(t_philo *philo, int argc, char **argv)
{
	philo->p_num = ft_atoi(argv[1]);
	philo->die = ft_atoi(argv[2]);
	philo->eat = ft_atoi(argv[3]);
	philo->sleep = ft_atoi(argv[4]);
	if (philo->p_num <= 0 || philo->die <= 0 || \
	philo->eat <= 0 || philo->eat <= 0 || philo->sleep <= 0)
		ft_exit("Error : incorrect arguments (negative values) !\n", 2, 1);
	ft_init_extra_arg(philo, argc, argv);
	philo->tids = malloc((philo->p_num + 1) * sizeof(pthread_t));
	philo->forks = malloc((philo->p_num + 1) * sizeof(pthread_mutex_t));
	philo->eating_now = malloc(philo->p_num + 1);
	philo->eating_now_m = malloc(sizeof(pthread_mutex_t));
	philo->ate_last = malloc(philo->p_num * sizeof(long));
	if (philo->tids == NULL || philo->forks == NULL || \
	philo->eating_now == NULL || philo->eating_now_m == NULL || \
	philo->ate_last == NULL)
		ft_exit("Error : malloc error could not initiate \
		philo structure !\n", 2, 1);
	memset(philo->eating_now, 0, philo->p_num);
	memset(philo->ate_last, 0, philo->p_num * sizeof(long));
	ft_init_forks(philo);
}
