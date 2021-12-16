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

	if (argc < 5 || argc > 6)
		ft_exit("Error : wrong number of arguments !\n", 2, 1);
	ft_init(&philo, argc, argv);
	ft_create_philo_threads(&philo);
	ft_join_threads(&philo);
	ft_free_and_exit(&philo);
	return (0);
}
