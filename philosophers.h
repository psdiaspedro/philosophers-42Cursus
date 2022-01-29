#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>

# define MAX_INT 2147483647
# define FORK 1
# define EAT 2
# define SLEEP 3
# define THINK 4
# define DIE 5

typedef	struct s_inf
{
	int				n_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	long int		first_meal;
	long int		last_meal;
	pthread_mutex_t	*print_locker;
}	t_inf;
typedef struct s_philo
{
	int				id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*meal_locker;
	pthread_t		thread;
	t_inf			*inf;
}	t_philo;

int			ft_isdigit(int c);
int			ft_atoi(const char *str);
void		validate(int argc, char **argv);
int			init(t_inf *infos, char **argv);
void		init_philosophers(t_inf *infos, t_philo **philos);
void		start_diner(t_inf *infos, t_philo *philos);
int			msleep(long int time_in_ms);
long int	timestamp(void);
long int	elapsed_time(long long int start_time);
void		last_meal(t_philo *philo);
void		print(t_philo *philo, int status);

#endif
