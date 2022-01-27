#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>

# define MAX_INT 2147483647

typedef struct s_philo
{
	int	id;
	int	left_fork;
	int	right_fork;
	pthread_t	thread;
}	t_philo;

typedef	struct s_infos
{
	int			n_of_philos;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			must_eat;
}	t_infos;

int		ft_isdigit(int c);
int		ft_atoi(const char *str);
void	validate(int argc, char **argv);
int		init(t_infos *infos, int argc, char **argv);
void	init_philosophers(t_infos *infos, t_philo **philos);
void	start_diner(t_infos *infos, t_philo *philos);

#endif
