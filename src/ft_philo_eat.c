/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_eat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:59:56 by mehill            #+#    #+#             */
/*   Updated: 2021/12/10 18:00:27 by mehill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_philo_think(t_args *args)
{
	if (args->philo->end_sim != 0)
		return ;
	printf("%-10ld %-5d is thinking ...\n", \
	ft_time_stamp(args->philo), *args->n);
}

int	ft_can_eat(t_args *args)
{
	int	left;
	int	right;

	left = (*args->n - 1 + args->philo->p_num) % args->philo->p_num;
	right = (*args->n + 1 + args->philo->p_num) % args->philo->p_num;
	return (args->philo->eating_now[left] == 0 && \
	args->philo->eating_now[right] == 0);
}

void	*ft_eat(t_args *args)
{
	args->philo->ate_last[*args->n] = ft_time_stamp(args->philo);
	ft_check_end(args);
	return (NULL);
}

void	ft_philo_eat(t_args *args)
{
	if (!ft_can_eat(args))
	{
		ft_philo_think(args);
		while (!ft_can_eat(args))
		{
			usleep(1000);
			ft_check_end(args);
		}
		if (args->philo->end_sim != 0)
			return ;
	}
	pthread_mutex_lock(args->philo->eating_now_m);
	args->philo->eating_now[*args->n] = 1;
	args->philo->ate_last[*args->n] = ft_time_stamp(args->philo);
	ft_lock_forks(args);
	pthread_mutex_unlock(args->philo->eating_now_m);
	printf("%-10ld %-5d is eating \n", \
	ft_time_stamp(args->philo), *args->n);
	ft_sleep_callback(args->philo->eat, 1, ft_eat, args);
	args->philo->ate_last[*args->n] = ft_time_stamp(args->philo);
	if (args->philo->eat_num)
		args->philo->eat_num[*args->n]++;
	ft_unlock_forks(args);
	args->philo->eating_now[*args->n] = 0;
}
