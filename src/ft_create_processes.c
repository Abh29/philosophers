/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_processes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:41:10 by mehill            #+#    #+#             */
/*   Updated: 2021/12/10 17:20:03 by mehill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*ft_philosopher_proc(t_philo2 *philo, int n)
{
	philo->ate_last[n] = ft_time_stamp2(philo);
	while (philo->end_sim == 0)
	{
		ft_philo_eat2(philo, n);
		ft_philo_sleep2(philo, n);
	}
	return (NULL);
}

void	ft_wait_procs(t_philo2 *philo)
{
	//int	i;
	//int	status;

	//i = 0;
	//status = 0;
	(void) philo;
	//while (i < philo->p_num)
	//	waitpid((pid_t)philo->pids[i++], &status, 0);
	while (wait(NULL) > 0);
}

void	ft_create_philo_procs(t_philo2 *philo)
{
	int		i;

	i = 0;
	while (i < philo->p_num)
	{
		philo->pids[i] = fork();
		if (philo->pids[i] < 0)
			ft_exit("Error : fork error !\n", 2, 1);
		if (philo->pids[i] == 0)
		{
			philo->ith = i;
			ft_philosopher_proc(philo, i);
			exit(0);
		}
		i++;
	}
}
