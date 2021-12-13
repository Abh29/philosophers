/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 20:30:46 by mehill            #+#    #+#             */
/*   Updated: 2021/12/13 12:32:45 by mehill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_philo_eat2(t_philo2 *philo, int n)
{
	sem_wait(philo->forks);
	ft_check_end2(philo);
	ft_print_status(philo, n, "has a fork");
	philo->ate_last[n] = ft_time_stamp2(philo);
	if (philo->eat_num)
		philo->eat_num[n]++;
	ft_print_status(philo, n, "is eating");
	usleep(philo->eat * 1000);
	philo->ate_last[n] = ft_time_stamp2(philo);
	sem_post(philo->forks);
	if (philo->eat_num && philo->eat_num[n] >= philo->eat_max)
	{
		ft_print_status(philo, n, "is full");
		exit(0);
	}
}
