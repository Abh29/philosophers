/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_eat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:59:56 by mehill            #+#    #+#             */
/*   Updated: 2021/12/13 13:44:31 by mehill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_philo_think(t_args *args)
{
	if (args->philo->end_sim != 0)
		return ;
	ft_print_thstatus(args, "is thinking");
}

int	ft_can_eat(t_args *args)
{
	int	left;
	int	right;

	if (*args->philo->end_sim != 0)
		return (0);
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

void	ft_update_eating_status(t_args *args, int status)
{
	pthread_mutex_lock(args->philo->eating_now_m);
	args->philo->eating_now[*args->n] = status;
	pthread_mutex_unlock(args->philo->eating_now_m);
}

void	ft_philo_eat(t_args *args)
{
	while (ft_can_eat(args) == 0)
		if (*args->philo->end_sim != 0)
			return ;
	ft_update_eating_status(args, 1);
	if (ft_can_eat(args))
	{
		ft_lock_forks(args);
		ft_print_thstatus(args, "is eating");
		ft_sleep_callback(args->philo->eat, 5, ft_eat, args);
		ft_unlock_forks(args);
		args->philo->ate_last[*args->n] = ft_time_stamp(args->philo);
		if (args->philo->eat_num)
		args->philo->eat_num[*args->n]++;
	}
	ft_update_eating_status(args, 0);
	usleep(1000);
}
