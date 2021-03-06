/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_threads.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:41:10 by mehill            #+#    #+#             */
/*   Updated: 2021/12/21 17:19:49 by mehill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*ft_philosopher_thread(void *vrgs)
{
	t_args	*args;

	args = (t_args *)vrgs;
	while (*args->philo->end_sim == 0)
	{
		ft_philo_eat(args);
		ft_philo_sleep(args);
	}
	return (NULL);
}

void	ft_join_threads(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->p_num)
		pthread_join(philo->tids[i++], NULL);
}

int	ft_create_philo_threads(t_philo *philo)
{
	int		i;
	t_args	*args;

	args = malloc((philo->p_num + 1) * sizeof(t_args));
	if (args == NULL)
		return (5);
	*philo->args = args;
	args[philo->p_num].n = malloc(sizeof(int));
	i = 0;
	while (i < philo->p_num)
	{
		args[i].philo = philo;
		args[i].n = malloc(sizeof(int));
		*(args[i].n) = i;
		if (pthread_create(&(philo->tids[i]), NULL, \
		ft_philosopher_thread, &args[i]) != 0)
			return (6);
		i++;
	}
	return (0);
}
