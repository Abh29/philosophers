/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 20:30:46 by mehill            #+#    #+#             */
/*   Updated: 2021/12/10 17:30:41 by mehill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_philo_eat2(t_philo2 *philo, int n)
{
	sem_wait(philo->forks);
	ft_check_end2(philo);
	printf("%-10ld %-5d has a fork\n", ft_time_stamp2(philo), n);
	philo->ate_last[n] = ft_time_stamp2(philo);
	if (philo->eat_num)
		philo->eat_num[n]++;
	printf("%-10ld %-5d is eating\n", ft_time_stamp2(philo), n);
	usleep(philo->eat * 1000);
	philo->ate_last[n] = ft_time_stamp2(philo);
	sem_post(philo->forks);
	if (philo->eat_num && philo->eat_num[n] >= philo->eat_max)
	{
		printf("%-10ld %-5d is full\n", ft_time_stamp2(philo), n);
		exit(0);
	}
}
