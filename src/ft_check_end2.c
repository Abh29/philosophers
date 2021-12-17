/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_end2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 20:31:50 by mehill            #+#    #+#             */
/*   Updated: 2021/12/17 16:47:23 by mehill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_philo_die2(t_philo2 *philo, int n)
{
	if (philo->end_sim != 0)
		exit(0);
	sem_wait(philo->exit_m);
	philo->end_sim = 1;
	sem_wait(philo->io_m);
	printf("%-10ld %-5d %s\n", ft_time_stamp2(philo), n, "died !");
	printf("last ate at %ld\n", philo->ate_last[n]);
	kill(0, SIGINT);
	sem_post(philo->io_m);
	sem_post(philo->exit_m);
	exit(0);
}

void	ft_philo_full2(t_philo2 *philo)
{
	if (philo->end_sim != 0)
		return ;
	sem_wait(philo->exit_m);
	if (philo->end_sim != 0)
		return ;
	philo->end_sim = 2;
	printf("Worning : philosophers are full !\n");
	sem_post(philo->exit_m);
	return ;
}

void	*ft_check_end2(void *vphilo)
{
	long		now;
	int			i;
	t_philo2	*philo;

	if (vphilo == NULL)
		exit(1);
	philo = (t_philo2 *)vphilo;
	now = ft_time_stamp2(philo);
	i = philo->ith;
	if (philo->end_sim != 0)
		exit(0);
	else if (philo->ate_last[i] && now - philo->ate_last[i] > philo->die)
		ft_philo_die2(philo, i);
	return (NULL);
}
