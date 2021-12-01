/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_end.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:15:01 by mehill            #+#    #+#             */
/*   Updated: 2021/12/01 20:08:58 by mehill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_philo_die(t_args *args, int n)
{
	int	i;

	printf("%ld philosopher %d is dead ! last ate %ld\n", \
	ft_time_stamp(args->philo), n, args->philo->ate_last[n]);
	i = 0;
	while (i < args->philo->p_num)
		pthread_detach(args->philo->tids[i++]);
	ft_exit("Worning : a philosopher is dead !\n", 1, 0);
	return ;
}

void	ft_philo_full(t_args *args)
{
	int	i;

	i = 0;
	while (i < args->philo->p_num)
		pthread_detach(args->philo->tids[i++]);
	ft_exit("Worning : a philosophers are full !\n", 1, 0);
	return ;
}

//FIXME: free memory upon dead or full event 
void	*ft_check_end(t_args *args)
{
	int		i;
	long	now;
	int		full;

	i = 0;
	full = 0;
	now = ft_time_stamp(args->philo);
	while (i < args->philo->p_num)
	{
		if (now - args->philo->ate_last[i] > args->philo->die)
			ft_philo_die(args, i);
		if (args->philo->eat_num && args->philo->eat_num[i] >= \
		args->philo->eat_max)
			full++;
		i++;
	}
	if (full >= args->philo->p_num)
		ft_philo_full(args);
	return (NULL);
}
