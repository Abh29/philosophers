#ifndef PHYLO_H
#define PHYLO_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>

typedef struct timeval t_time;

typedef struct s_philo
{
    pthread_t           *tids;
    pthread_mutex_t     *forks;
    int                 *last_eat_time;
    pthread_mutex_t     *eating_now_m;
    char                *eating_now;
    int                 p_num;
    int                 die;
    int                 sleep;
    int                 eat;
    int                 *eat_num;
    int                 eat_max;
}               t_philo;

typedef struct s_args
{
    t_philo *philo;
    int     n;
}               t_args;




//tools
void    ft_exit(char *msg, int fd, int err);
int     ft_strlen(char *str);
int     ft_atoi(const char *str);
void    ft_sleep_callback(int ms, int max_sleep_ms, void *callback(t_args *args), t_args *args);

#endif
