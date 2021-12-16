/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:13:21 by mehill            #+#    #+#             */
/*   Updated: 2021/12/01 16:13:21 by mehill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_strlen(char *str)
{
	int	out;

	out = 0;
	while (*str++)
		out++;
	return (out);
}

void	ft_exit(char *msg, int fd, int err)
{
	write(fd, msg, ft_strlen(msg));
	exit(err);
}

void	ft_putstr_fd(char *str, int fd)
{
	write(fd, str, ft_strlen(str));
}

void	ft_sleep_callback(int ms, int max_sleep_ms, \
void *callback(t_args *args), t_args *args)
{
	callback(args);
	while (ms > 0)
	{
		if (*args->philo->end_sim != 0)
			return ;
		if (ms > max_sleep_ms)
			usleep(max_sleep_ms * 1000);
		else
			usleep(ms * 1000);
		callback(args);
		ms -= max_sleep_ms;
	}
}

long	ft_time_stamp(t_philo *philo)
{
	t_time	tp;

	gettimeofday(&tp, NULL);
	return (tp.tv_sec * 1000 + tp.tv_usec / 1000 - philo->zero_time);
}
