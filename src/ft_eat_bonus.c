/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 20:30:46 by mehill            #+#    #+#             */
/*   Updated: 2021/12/03 21:25:54 by mehill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_philo_eat2(t_philo2 *philo, int n)
{
	sem_wait(philo->forks);
	printf("%-10ld %-5d is eating\n", ft_time_stamp2(philo), n);
	philo->ate_last[n] = ft_time_stamp2(philo);
	if (philo->eat_num)
		philo->eat_num[n]++;
	ft_sleep_callback2(philo->eat, 5, ft_check_end2, philo);
	philo->ate_last[n] = ft_time_stamp2(philo);
	sem_post(philo->forks);
	if (philo->eat_num && philo->eat_num[n] >= philo->eat_max)
	{
		printf("%-10ld %-5d is full\n", ft_time_stamp2(philo), n);
		exit(0);
	}
}
