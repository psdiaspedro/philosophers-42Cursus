#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>

# define MAX_INT 2147483647

typedef	struct s_infos
{
	long int	n_of_philos;
	long int	n_of_time_to_die;
	long int	n_of_time_to_eat;
	long int	n_of_time_to_time_to_eat;
}	t_infos;

int			ft_isdigit(int c);
long int	ft_atoi(const char *str);

#endif
