/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:22:35 by mehill            #+#    #+#             */
/*   Updated: 2021/12/03 20:55:16 by mehill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_init_extra_arg_bonus(t_philo2 *philo, int argc, char **argv)
{
	philo->end_sim = 0;
	philo->zero_time = 0;
	philo->zero_time = ft_time_stamp2(philo);
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
}

void	ft_init_bonus(t_philo2 *philo, int argc, char **argv)
{
	philo->p_num = ft_atoi(argv[1]);
	philo->die = ft_atoi(argv[2]);
	philo->eat = ft_atoi(argv[3]);
	philo->sleep = ft_atoi(argv[4]);
	if (philo->p_num <= 1 || philo->p_num > 32767 * 2 || philo->die <= 0 || \
	philo->eat <= 0 || philo->eat <= 0 || philo->sleep <= 0)
		ft_exit("Error : incorrect arguments (negative values) !\n", 2, 1);
	ft_init_extra_arg_bonus(philo, argc, argv);
	philo->pids = malloc(philo->p_num * sizeof(int));
	philo->ate_last = malloc(philo->p_num * sizeof(long));
	if (!philo->pids || !philo->pids || !philo->ate_last || !philo->ate_last)
		ft_exit("Error : could not initiate philo structure !\n", 2, 1);
	philo->forks = sem_open("forks", O_CREAT, 0775, philo->p_num / 2);
	philo->forks = sem_open("exit_m", O_CREAT, 0775, 1);
	if (philo->forks == SEM_FAILED || philo->exit_m == SEM_FAILED)
		ft_exit("Error : could not create a semaphore !\n", 2, 1);
	memset(philo->pids, 0, philo->p_num * sizeof(int));
}
