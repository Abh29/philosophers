/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:37:12 by mehill            #+#    #+#             */
/*   Updated: 2021/12/03 21:00:33 by mehill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo2	philo;

	if (argc < 5 || argc > 6)
		ft_exit("Error : wrong number of arguments !\n", 2, 1);
	ft_init_bonus(&philo, argc, argv);
	printf("%d  %d  %d  %d \n", philo.p_num, philo.eat, philo.die, philo.sleep);
	getchar();
	ft_create_philo_procs(&philo);
	ft_wait_procs(&philo);
	ft_free_and_exit2(&philo);
	printf("buy !");
	getchar();
	return (0);
}
