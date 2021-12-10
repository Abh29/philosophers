/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_end.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:15:01 by mehill            #+#    #+#             */
/*   Updated: 2021/12/10 18:04:25 by mehill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_philo_die(t_args *args, int n)
{
	if (args->philo->end_sim != 0)
		return ;
	pthread_mutex_lock(args->philo->exit_m);
	if (args->philo->end_sim != 0)
		return ;
	args->philo->end_sim = 1;
	usleep(1000);
	printf("%-10ld %-5d died ! last ate %ld\n", \
	ft_time_stamp(args->philo), n, args->philo->ate_last[n]);
	exit(0);
	pthread_mutex_unlock(args->philo->exit_m);
	return ;
}

void	ft_philo_full(t_args *args)
{
	pthread_mutex_lock(args->philo->exit_m);
	if (args->philo->end_sim != 0)
		return ;
	args->philo->end_sim = 2;
	printf("Worning : philosophers are full !\n");
	pthread_mutex_unlock(args->philo->exit_m);
	return ;
}

void	*ft_check_end(t_args *args)
{
	int		i;
	long	now;
	int		full;

	i = 0;
	full = 0;
	now = ft_time_stamp(args->philo);
	while (i < args->philo->p_num)
	{
		if (args->philo->end_sim != 0)
			return (NULL);
		else if (now - args->philo->ate_last[i] > args->philo->die)
			ft_philo_die(args, i);
		else if (args->philo->eat_num && args->philo->eat_num[i] >= \
		args->philo->eat_max)
			full++;
		i++;
	}
	if (full >= args->philo->p_num)
		ft_philo_full(args);
	return (NULL);
}
