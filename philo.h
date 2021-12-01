/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehill <mehill@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:25:10 by mehill            #+#    #+#             */
/*   Updated: 2021/12/01 16:25:10 by mehill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct timeval	t_time;

typedef struct s_philo
{
	pthread_t			*tids;
	pthread_mutex_t		*forks;
	int					*last_eat_time;
	pthread_mutex_t		*eating_now_m;
	char				*eating_now;
	long				*ate_last;
	int					p_num;
	int					die;
	int					sleep;
	int					eat;
	int					*eat_num;
	int					eat_max;
	long				zero_time;
}				t_philo;

typedef struct s_args
{
	t_philo	*philo;
	int		*n;
}			t_args;

//tools
void	ft_exit(char *msg, int fd, int err);
int		ft_strlen(char *str);
int		ft_atoi(const char *str);
void	ft_sleep_callback(int ms, int max_sleep_ms, \
		void *callback(t_args *args), t_args *args);
void	*ft_check_end(t_args *args);
long	ft_time_stamp(t_philo *philo);

void	ft_lock_forks(t_args *args);
void	ft_unlock_forks(t_args *args);

void	ft_init(t_philo *philo, int argc, char **argv);
void	ft_philo_eat(t_args *args);
void	ft_philo_die(t_args *args, int n);
void	ft_philo_think(t_args *args);
void	ft_philo_sleep(t_args *args);
void	ft_philo_full(t_args *args);
void	ft_create_philo_threads(t_philo *philo);
void	ft_join_threads(t_philo *philo);

#endif
