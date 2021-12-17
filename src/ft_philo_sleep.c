/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_sleep.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:57:43 by mehill            #+#    #+#             */
/*   Updated: 2021/12/17 15:47:47 by mehill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_philo_sleep(t_args *args)
{
	t_time	tp;

	if (*args->philo->end_sim != 0)
		return ;
	gettimeofday(&tp, NULL);
	ft_print_thstatus(args, "is sleeping");
	ft_sleep_callback(args->philo->sleep, 5, ft_check_end, args);
	ft_print_thstatus(args, "is thinking");
	usleep(100);
}
