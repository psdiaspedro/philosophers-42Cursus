/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugusto <paugusto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:50:57 by paugusto          #+#    #+#             */
/*   Updated: 2022/01/30 14:12:00 by paugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	sleeping(t_philo *philo)
{
	print(philo, SLEEPING);
	msleep(philo->setup->time_to_sleep);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(philo->right_fork);
	print(philo, TAKEN_FORK);
	print(philo, TAKEN_FORK);
	print(philo, EATING);
	last_meal(philo);
	msleep(philo->setup->time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_lock(philo->sum_meal_locker);
	philo->meals++;
	pthread_mutex_unlock(philo->sum_meal_locker);
}

void	*monitor_routine(void *ptr)
{
	t_philo		*philo;
	long int	now;
	int			i;

	philo = (t_philo *)ptr;
	i = 0;
	while (havent_eaten(philo))
	{
		i = 0;
		while (i < philo->setup->n_of_philos)
		{
			now = elapsed_time(philo->setup->first_meal);
			if ((now - philo_last_meal(&philo[i])) > philo->setup->time_to_die)
			{
				pthread_mutex_lock(philo[i].finish_dinner_locker);
				philo[i].setup->is_dinner_finished = 1;
				pthread_mutex_unlock(philo[i].finish_dinner_locker);
				print(philo, DIED);
				return (NULL);
			}
		}
		msleep(1);
	}
	return (NULL);
}

void	*philos_routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;

	//criar uma rotina caso seja apenas 1 philo
	if (philo->id % 2 == 0)
		msleep(5);
	while (&have_finished)
	{
		eat(philo);
		sleeping(philo);
		print(philo, THINKING);
		usleep(500);
	}
	return (NULL);
}

void	start_diner(t_philo *philos)
{
	pthread_t	monitor;
	int			i;

	i = 0;
	philos->setup->first_meal = timestamp();
	while (i < philos->setup->n_of_philos)
		pthread_create(&philos[i].thread, NULL, &philos_routine, &philos[i]); //falta proteger
	pthread_create(&monitor, NULL, &monitor_routine, philos);//falta proteger
	i = 0;
	while (i < philos->setup->n_of_philos)
		pthread_join(philos[i].thread, NULL); //falta proteger
	pthread_join(monitor, NULL); //falta proteger
}
