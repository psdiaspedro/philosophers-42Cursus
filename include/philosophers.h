#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>

# define TAKEN_FORK	"has taken a fork"
# define EATING		"is eating"
# define SLEEPING	"is sleeping"
# define THINKING	"is thinking"
# define DIED		"died"
# define MAX_INT 	2147483647
typedef	struct s_setup
{
	int				n_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				alone_philo;
	int				is_dinner_finished;
	long int		first_meal;
	pthread_mutex_t	*print_locker;
}	t_setup;
typedef struct s_philo
{
	int				id;
	int				meals;
	long int		last_meal;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*meal_locker;
	pthread_mutex_t	*sum_meal_locker;
	pthread_mutex_t	*last_meal_locker;
	pthread_mutex_t	*finish_dinner_locker;
	pthread_t		thread;
	t_setup			*setup;
}	t_philo;

int			ft_isdigit(int c);
int			ft_atoi(const char *str);
void		validate(int argc, char **argv);
int			init(t_setup *setup, char **argv);
void		init_forks(t_setup *setup, pthread_mutex_t **forks);
void		init_philosophers(t_setup *setup, t_philo **philos, pthread_mutex_t **forks);
void		start_diner(t_philo *philos);
void		msleep(long int time_in_ms);
long int	timestamp(void);
long int	elapsed_time(long int start_time);
void		last_meal(t_philo *philo);
void		print(t_philo *philo, char *status);
int			havent_eaten(t_philo *philo);
void		destroy_forks(t_philo *philos, t_setup *setup, pthread_mutex_t *forks);
int			have_finished(t_philo *philo);
void		free_n_destroy_philo(t_philo *philos, t_setup *setup, pthread_mutex_t *forks);
int			philo_last_meal(t_philo *philo);

#endif
