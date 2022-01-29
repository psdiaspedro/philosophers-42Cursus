/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diner.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugusto <paugusto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:50:57 by paugusto          #+#    #+#             */
/*   Updated: 2022/01/28 23:17:58 by paugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void think(t_philo *philo)
{
	print(philo, THINK);
	usleep(500);
}

void	sleep(t_philo *philo)
{
	print(philo, SLEEP);
	msleep(philo->inf->time_to_sleep);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(philo->right_fork);
	print(philo, FORK);
	print(philo, FORK);
	print(philo, EAT);
	last_meal(philo);
	msleep(philo->inf->time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	*routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	eat(philo);
	sleep(philo);
	think(philo);
	return (NULL);
}

void	start_diner(t_inf *inf, t_philo *philos)
{
	int	i;

	i = 0;

	inf->first_meal = timestamp();
	while (i < inf->n_of_philos)
		pthread_create(&philos[i].thread, NULL, &routine, &philos[i]);
	i = 0;
	while (i < inf->n_of_philos)
		pthread_join(philos[i].thread, NULL);
}
