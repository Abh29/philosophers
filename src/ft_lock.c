/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lock.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:56:42 by mehill            #+#    #+#             */
/*   Updated: 2021/12/01 20:13:19 by mehill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_lock_forks(t_args *args)
{
	pthread_mutex_lock(&(args->philo->forks[*args->n]));
	pthread_mutex_lock(&(args->philo->\
	forks[*args->n + 1 % args->philo->p_num]));
	printf("%-10ld %-5d has taken a fork\n", \
	ft_time_stamp(args->philo), *args->n);
}

void	ft_unlock_forks(t_args *args)
{
	pthread_mutex_unlock(&(args->philo->forks[*args->n]));
	pthread_mutex_unlock(&(args->philo->\
	forks[*args->n + 1 % args->philo->p_num]));
}
