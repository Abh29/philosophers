/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_sleep.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:57:43 by mehill            #+#    #+#             */
/*   Updated: 2021/12/13 13:44:24 by mehill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_philo_sleep(t_args *args)
{
	t_time	tp;

	gettimeofday(&tp, NULL);
	if (*args->philo->end_sim != 0)
		return ;
	ft_print_thstatus(args, "is sleeping");
	ft_sleep_callback(args->philo->sleep, 5, ft_check_end, args);
	ft_print_thstatus(args, "is thinking");
}
