#include "../philo.h"

int     ft_strlen(char *str)
{
    int out;

    out = 0;
    while (*str++)
        out++;
    return (out);
}

void    ft_exit(char *msg, int fd, int err)
{
    write(fd, msg, ft_strlen(msg));
    exit(err);
}

void    ft_putstr_fd(char *str, int fd)
{
    write(fd, str, ft_strlen(str));
}

void    ft_sleep_callback(int ms, int max_sleep_ms, void *callback(t_args *args), t_args *args)
{
    callback(args);
    while (ms > 0)
    {
        if (ms > max_sleep_ms)
            usleep(max_sleep_ms);
        else
            usleep(ms);
        callback(args);
        ms -= max_sleep_ms;
    }
}
