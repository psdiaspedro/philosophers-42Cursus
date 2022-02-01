/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugusto <paugusto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:50:57 by paugusto          #+#    #+#             */
/*   Updated: 2022/02/01 11:01:11 by paugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*solo_dinner(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	print(philo, TAKEN_FORK);
	pthread_mutex_unlock(philo->right_fork);
	return (NULL);
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(philo->left_fork);
	if (philo_is_dead(philo))
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
	}
	print(philo, TAKEN_FORK);
	print(philo, TAKEN_FORK);
	print(philo, EATING);
	pthread_mutex_lock(philo->setup->last_meal_locker);
	philo->last_meal = elapsed_time(philo->setup->first_meal);
	pthread_mutex_unlock(philo->setup->last_meal_locker);
	msleep(philo->setup->time_to_eat);
	pthread_mutex_lock(philo->setup->sum_meals_locker);
	philo->meals++;
	pthread_mutex_unlock(philo->setup->sum_meals_locker);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	*philos_routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->id % 2 == 0)
		msleep(5);
	if (philo->setup->one_philo)
		return (solo_dinner(philo));
	while (!philo_is_dead(philo))
	{
		eating(philo);
		if (get_meal(philo) == philo->setup->must_eat)
			return (NULL);
		print(philo, SLEEPING);
		msleep(philo->setup->time_to_sleep);
		print(philo, THINKING);
	}
	return (NULL);
}

void	start_dinner(t_philo *philo, int n_of_philos)
{
	pthread_t	monitor;
	int			i;

	i = 0;
	philo->setup->first_meal = timestamp();
	while (i < n_of_philos)
	{
		pthread_create(&philo[i].thread, NULL, &philos_routine, &philo[i]);
		i++;
	}
	pthread_create(&monitor, NULL, &monitor_routine, philo);
	i = 0;
	while (i < philo->setup->n_of_philos)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
	pthread_join(monitor, NULL);
}
