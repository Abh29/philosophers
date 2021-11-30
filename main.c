#include "philo.h"

void    print_time_of_day()
{
     t_time  tp;

    gettimeofday(&tp, NULL);
    printf("it has been %ld.%ld sec since 01/01/1970\n", tp.tv_sec, tp.tv_usec);
}

void    ft_init_forks(t_philo *philo)
{
    int i;

    i = 0;
    while (i < philo->p_num)
    {
        if (pthread_mutex_init(&(philo->forks[i]), NULL) != 0)
            ft_exit("Error : could not init a mutex \n", 2, 1);
        i++;
    }
    philo->forks[i] = NULL;
    if (pthread_mutex_init(philo->eating_now_m, NULL) != 0)
        ft_exit("Error : could not init a mutex !\n", 2, 1);
}

void    ft_init(t_philo *philo, int argc, char **argv)
{
    philo->p_num = ft_atoi(argv[1]);
    philo->die = ft_atoi(argv[2]);
    philo->eat = ft_atoi(argv[3]);
    philo->sleep = ft_atoi(argv[4]);
    if (philo->p_num <= 0 || philo->die <= 0 || philo->eat <= 0 || philo->eat <= 0 || philo->sleep <= 0)
        ft_exit("Error : incorrect arguments (negative values) !\n", 2, 1);
    if (argc == 6)
    {
       philo->eat_max = ft_atoi(argv[5]);
       if (philo->eat_max <= 0)
            ft_exit("Error : incorrect arguments (negative values) !\n", 2, 1);
        philo->eat_num = malloc((philo->p_num + 1) * sizeof(int));
        if (philo->eat_num == NULL)
            ft_exit("Error : malloc error could not initiate philo structure!\n", 2, 1);
        memset(philo->eat_num, 0, (philo->p_num + 1) * sizeof(int));
    }
    else
        philo->eat_num = NULL;
    philo->tids = malloc((philo->p_num + 1) * sizeof(pthread_t));
    philo->forks = malloc((philo->p_num + 1) * sizeof(pthread_mutex_t));
    philo->eating_now = malloc(philo->p_num + 1);
    philo->eating_now_m = malloc(sizeof(pthread_mutex_t));
    if (philo->tids == NULL || philo->forks == NULL || philo->eating_now == NULL || philo->eating_now_m == NULL)
        ft_exit("Error : malloc error could not initiate philo structure !\n", 2, 1);
    memset(philo->eating_now, 0, philo->p_num);
    ft_init_forks(philo);
}

void    *ft_check_end(t_args *args)
{
    return (NULL);
}

void    ft_philo_sleep(t_args *args)
{
    t_time  tp;

    gettimeofday(&tp, NULL);
    printf("%d philosopher %d is sleeping ...\n", tp.tv_sec , args->n);
    ft_sleep_callback(args->philo->sleep, 5, ft_check_end, args);
}

void    ft_philo_die(t_args *args);
void    ft_philo_think(t_args *args)
{
    t_time  tp;

    gettimeofday(&tp, NULL);
    printf("%f philosopher %d is thinking ...\n", tp.tv_sec * 1000 + tp.tv_usec * 1000, args->n);
    ft_sleep_callback(args->philo->eat, 5, ft_check_end, args);
}

int     ft_can_eat(t_args *args)
{
    int left;
    int right;

    left = (args->n - 1 + args->philo->p_num) % args->philo->p_num;
    right =(args->n + 1 + args->philo->p_num) % args->philo->p_num;
    return (args->philo->eating_now[left] == 0 && args->philo->eating_now[right] == 0);
}

void    ft_lock_forks(t_args *args)
{
    pthread_mutex_lock(&(args->philo->forks[args->n]));
    pthread_mutex_lock(&(args->philo->forks[args->n + 1 % args->philo->p_num]));
}

void    ft_unlock_forks(t_args *args)
{
    pthread_mutex_unlock(&(args->philo->forks[args->n]));
    pthread_mutex_unlock(&(args->philo->forks[args->n + 1 % args->philo->p_num]));
}

void    ft_philo_eat(t_args *args)
{
    //check if someone is eating
    t_time  tp;

    pthread_mutex_lock(args->philo->eating_now_m);
    if (ft_can_eat(args))
    {
        args->philo->eating_now[args->n] = 1;
        args->philo->eat_num[args->n]++;
    }
    ft_lock_forks(args);
    pthread_mutex_unlock(args->philo->eating_now_m);
    gettimeofday(&tp, NULL);
    printf("%f philosopher %d is eating ...\n", tp.tv_sec * 1000 + tp.tv_usec / 1000, args->n);
    ft_sleep_callback(args->philo->eat, 5, ft_check_end, args);
    ft_unlock_forks(args);
    args->philo->eating_now[args->n] = 0;
    //free forks
}

void    *ft_philosopher_thread(void *vrgs)
{
    t_args *args;
    int i = 0;

    args = (t_args *)vrgs;
    if (args->n != 1)
        usleep(1000);
    printf("thread %d has been created \n", args->n);
    while (i++ < 10)
    {
        ft_philo_eat(args);
        ft_philo_sleep(args);
        ft_philo_think(args);
        usleep(1000);
    }
    pthread_exit(NULL);
    return (NULL);
}

// args ??
void    ft_create_philo_threads(t_philo *philo)
{
    int     i;
    t_args  args[philo->p_num + 1];

    i = 0;
    while (i < philo->p_num)
    {
        args[i].philo = philo;
        args[i].n = i;
        pthread_create(&(philo->tids[i]), NULL, ft_philosopher_thread, &args[i]);
        if (philo->tids[i] < 0)
            ft_exit("Error : could not create a thread !\n", 2, 1);
        pthread_join(philo->tids[i], NULL);
        i++;
    }
}


int main(int argc, char **argv)
{
    t_philo philo;
    if (argc < 5 || argc > 6)
        ft_exit("Error : wrong number of arguments !\n", 2, 1);
    ft_init(&philo, argc, argv);
    ft_create_philo_threads(&philo);
    print_time_of_day();
    return 0;
}
