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
# include <fcntl.h>
# include <sys/stat.h>
# include <semaphore.h>
# include <signal.h>
# include <sys/wait.h>

typedef struct timeval	t_time;

# define MAX_THREAD_NUMBER  250

typedef struct s_philo
{
	pthread_t			*tids;
	pthread_mutex_t		**forks;
	pthread_mutex_t		*eating_now_m;
	pthread_mutex_t		*io_m;
	char				*eating_now;
	long				*ate_last;
	void				**args;
	int					p_num;
	int					die;
	int					sleep;
	int					eat;
	int					*eat_num;
	int					eat_max;
	long				zero_time;
	pthread_mutex_t		*exit_m;
	pthread_mutex_t		*end_sim_m;
	int					*end_sim;
}				t_philo;

typedef struct s_args
{
	t_philo	*philo;
	int		*n;
}			t_args;

typedef struct s_philo2
{
	int					p_num;
	int					die;
	int					sleep;
	int					eat;
	int					*eat_num;
	int					eat_max;
	int					*pids;
	sem_t				*forks;
	long				zero_time;
	long				*ate_last;
	sem_t				*exit_m;
	int					end_sim;
	int					ith;
	sem_t				*io_m;
}				t_philo2;

//tools
void	ft_exit(char *msg, int fd, int err);
int		ft_strlen(char *str);
void	ft_putstr_fd(char *str, int fd);
int		ft_atoi(const char *str);
void	ft_sleep_callback(int ms, int max_sleep_ms, \
		void *callback(t_args *args), t_args *args);
void	ft_sleep_callback2(int ms, int max_sleep_ms, \
		void *callback(void *args), void *args);
void	*ft_check_end(t_args *args);
long	ft_time_stamp(t_philo *philo);
long	ft_time_stamp2(t_philo2 *philo);
void	ft_free_and_exit(t_philo *philo);
void	ft_free_and_exit2(t_philo2 *philo);
int		ft_exit_msg(int err, int fd);

void	ft_lock_forks(t_args *args);
void	ft_unlock_forks(t_args *args);

int		ft_init(t_philo *philo, int argc, char **argv);
void	ft_philo_eat(t_args *args);
void	ft_philo_die(t_args *args, int n);
void	ft_philo_think(t_args *args);
void	ft_philo_sleep(t_args *args);
void	ft_philo_full(t_args *args);
int		ft_create_philo_threads(t_philo *philo);
void	ft_join_threads(t_philo *philo);
void	ft_print_thstatus(t_args *args, char *msg);

//bonus
void	ft_init_bonus(t_philo2 *philo, int argc, char **argv);
void	ft_create_philo_procs(t_philo2 *philo);
void	ft_philo_sleep2(t_philo2 *philo, int n);
void	ft_philo_eat2(t_philo2 *philo, int n);
void	*ft_check_end2(void *vphilo);
void	ft_wait_procs(t_philo2 *philo);
void	ft_print_status(t_philo2 *philo, int n, char *msg);

#endif
