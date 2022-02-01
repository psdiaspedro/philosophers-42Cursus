/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugusto <paugusto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 16:24:13 by paugusto          #+#    #+#             */
/*   Updated: 2022/01/31 19:34:49 by paugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_last_meal(t_philo *philo)
{
	long	last;

	pthread_mutex_lock(philo->setup->get_last_meal_locker);
	last = philo->last_meal;
	pthread_mutex_unlock(philo->setup->get_last_meal_locker);
	return (last);
}

int	limited_meals(t_philo *philo)
{
	int	i;
	int	eaten_enough;

	i = 0;
	eaten_enough = 0;
	while (i < philo->setup->n_of_philos)
	{
		if (get_meal(&philo[i]) == philo[i].setup->must_eat)
			eaten_enough++;
		i++;
	}
	if (eaten_enough == philo->setup->n_of_philos)
		return (1);
	return (0);
}

void	*monitor_routine(void *ptr)
{
	t_philo	*philo;
	int		i;
	long	time_now;
	long	time_to_die;

	philo = (t_philo *)ptr;
	time_to_die = philo->setup->time_to_die;
	while (!limited_meals(philo))
	{
		i = 0;
		while (i < philo->setup->n_of_philos)
		{
			time_now = elapsed_time(philo->setup->first_meal);
			if (time_now - get_last_meal(&philo[i]) > time_to_die)
			{
				print(&philo[i], DIED);
				philo_died(&philo[i]);
				return (NULL);
			}
			i++;
		}
		msleep(1);
	}
	return (NULL);
}
