/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 20:32:30 by mehill            #+#    #+#             */
/*   Updated: 2021/12/10 17:40:09 by mehill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_philo_sleep2(t_philo2 *philo, int n)
{
	if (philo->end_sim != 0)
		return ;
	printf("%-10ld %-5d is sleeping\n", ft_time_stamp2(philo), n);
	ft_sleep_callback2(philo->sleep, 5, ft_check_end2, philo);
	printf("%-10ld %-5d is thinking\n", ft_time_stamp2(philo), n);
}
