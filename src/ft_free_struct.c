/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 20:56:13 by mehill            #+#    #+#             */
/*   Updated: 2021/12/17 16:42:27 by mehill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_free_helper(t_philo *philo)
{
	free(philo->args);
	free(philo->tids);
	free(philo->forks);
	free(philo->eating_now);
	free(philo->eating_now_m);
	free(philo->ate_last);
	free(philo->end_sim);
	free(philo->io_m);
	if (philo->eat_num)
		free(philo->eat_num);
	free(philo->exit_m);
}

void	ft_free_and_exit(t_philo *philo)
{
	t_args	*args;
	int		i;

	args = *philo->args;
	i = 0;
	while (i < philo->p_num + 1)
	{
		if (args[i].n)
			free(args[i].n);
		pthread_mutex_destroy(philo->forks[i]);
		free(philo->forks[i++]);
	}
	pthread_mutex_destroy(philo->eating_now_m);
	pthread_mutex_destroy(philo->exit_m);
	pthread_mutex_destroy(philo->end_sim_m);
	pthread_mutex_destroy(philo->io_m);
	free(args);
	ft_free_helper(philo);
}

void	ft_free_and_exit2(t_philo2 *philo)
{
	int		i;

	i = 0;
	while (i < philo->p_num)
		kill((pid_t)philo->pids[i++], 0);
	sem_unlink("forks_m");
	sem_unlink("exit_m");
	sem_unlink("stream_m");
	sem_close(philo->forks);
	sem_close(philo->exit_m);
	sem_close(philo->io_m);
	free(philo->pids);
	free(philo->ate_last);
	if (philo->eat_num)
		free(philo->eat_num);
}
