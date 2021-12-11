/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:13:21 by mehill            #+#    #+#             */
/*   Updated: 2021/12/10 17:23:27 by mehill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_sleep_callback2(int ms, int max_sleep_ms, \
		void *callback(void *args), void *args)
{
	t_philo2	*philo;

	philo = (t_philo2 *)args;
	callback(args);
	while (ms > 0)
	{
		if (philo->end_sim != 0)
			exit(0);
		if (ms > max_sleep_ms)
			usleep(max_sleep_ms * 1000);
		else
			usleep(ms * 1000);
		callback(args);
		ms -= max_sleep_ms;
	}
}

long	ft_time_stamp2(t_philo2 *philo)
{
	t_time	tp;

	gettimeofday(&tp, NULL);
	return (tp.tv_sec * 1000 + tp.tv_usec / 1000 - philo->zero_time);
}
