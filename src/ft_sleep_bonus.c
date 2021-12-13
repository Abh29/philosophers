/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 20:32:30 by mehill            #+#    #+#             */
/*   Updated: 2021/12/13 12:31:18 by mehill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_philo_sleep2(t_philo2 *philo, int n)
{
	if (philo->end_sim != 0)
		return ;
	ft_print_status(philo, n, "is sleeping");
	ft_sleep_callback2(philo->sleep, 5, ft_check_end2, philo);
	ft_print_status(philo, n, "is thinking");
}
