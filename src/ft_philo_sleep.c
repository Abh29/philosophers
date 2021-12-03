/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_sleep.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:57:43 by mehill            #+#    #+#             */
/*   Updated: 2021/12/03 16:59:09 by mehill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_philo_sleep(t_args *args)
{
	t_time	tp;

	gettimeofday(&tp, NULL);
	if (args->philo->end_sim != 0)
		return ;
	printf("%-10ld %-5d is sleeping ...\n", \
	ft_time_stamp(args->philo), *args->n);
	ft_sleep_callback(args->philo->sleep, 5, ft_check_end, args);
}
