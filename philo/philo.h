/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugusto <paugusto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 11:04:12 by paugusto          #+#    #+#             */
/*   Updated: 2022/02/01 11:05:18 by paugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define MAX_INT 	2147483647
# define TAKEN_FORK	"has taken a fork"
# define EATING		"is eating"
# define SLEEPING	"is sleeping"
# define THINKING	"is thinking"
# define DIED		"died"

typedef struct s_setup
{
	int				n_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				one_philo;
	int				philo_died;
	long			first_meal;
	pthread_mutex_t	*print_locker;
	pthread_mutex_t	*get_last_meal_locker;
	pthread_mutex_t	*died_locker;
	pthread_mutex_t	*sum_meals_locker;
	pthread_mutex_t	*get_meals_locker;
	pthread_mutex_t	*is_philo_died_locker;
	pthread_mutex_t	*last_meal_locker;
}	t_setup;

typedef struct s_philo
{
	int				id;
	int				meals;
	long			last_meal;
	pthread_t		thread;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	t_setup			*setup;
}	t_philo;

void	*monitor_routine(void *ptr);
void	validate(int argc, char **argv);
void	init(t_setup *set, t_philo **phi, pthread_mutex_t **forks, char **argv);
void	msleep(int time_in_ms);
void	print(t_philo *philo, char *status);
void	start_dinner(t_philo *philo, int n_of_philos);
void	philo_died(t_philo *philo);
long	ft_atol(const char *nptr);
long	timestamp(void);
long	elapsed_time(long firststamp);
int		ft_isdigit(int c);
int		ft_atoi(const char *nptr);
int		get_meal(t_philo *philo);
int		philo_is_dead(t_philo *philo);
void	free_mutex(t_setup *setup);
void	free_forks_destroy_mutex(t_setup *setup, pthread_mutex_t *forks);
void	free_philo(t_philo *philo, t_setup *setup, pthread_mutex_t *forks);
void	free_finish(t_philo *philo, t_setup *setup, pthread_mutex_t *forks);

#endif
