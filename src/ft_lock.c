/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lock.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:56:42 by mehill            #+#    #+#             */
/*   Updated: 2021/12/13 13:43:24 by mehill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_lock_forks(t_args *args)
{
	pthread_mutex_lock(args->philo->forks[*args->n]);
	ft_print_thstatus(args, "has taken a fork");
	pthread_mutex_lock(args->philo->\
	forks[*args->n + 1 % args->philo->p_num]);
	ft_print_thstatus(args, "has taken a fork");
}

void	ft_unlock_forks(t_args *args)
{
	pthread_mutex_unlock(args->philo->forks[*args->n]);
	pthread_mutex_unlock(args->philo->\
	forks[*args->n + 1 % args->philo->p_num]);
}
