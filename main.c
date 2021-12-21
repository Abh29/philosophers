/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:01:10 by mehill            #+#    #+#             */
/*   Updated: 2021/12/01 17:01:10 by mehill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo	philo;
	int		err;

	if (argc < 5 || argc > 6)
		return (ft_exit_msg(7, 2));
	err = ft_init(&philo, argc, argv);
	if (err)
		return (ft_exit_msg(err, 2));
	err = ft_create_philo_threads(&philo);
	if (err)
		return (ft_exit_msg(err, 2));
	ft_join_threads(&philo);
	ft_free_and_exit(&philo);
	return (0);
}
