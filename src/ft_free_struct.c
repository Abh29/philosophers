/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 20:56:13 by mehill            #+#    #+#             */
/*   Updated: 2021/12/01 21:24:10 by mehill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

//FIXME: exit from one thread only !
void	ft_free_and_exit(t_args *args)
{
	t_philo	*philo;
	int		i;

	philo = args->philo;
	i = 0;
	ft_putstr_fd("exiting ...\n", 1);
	while (i < philo->p_num)
	{
		if (args[i].n)
			free(args[i].n);
		pthread_mutex_destroy(&(philo->forks[i]));
		i++;
	}
	//free(*(philo->args));
	pthread_mutex_destroy(philo->eating_now_m);
	//free(philo->args);
	//free(philo->tids);
	//free(philo->forks);
	//free(philo->eating_now);
	//free(philo->eating_now_m);
	//free(philo->ate_last);
	//if (philo->eat_num)
	//	free(philo->eat_num);
	ft_exit("buy !", 1, 0);
}
