/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugusto <paugusto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 22:05:27 by paugusto          #+#    #+#             */
/*   Updated: 2022/01/29 17:46:34 by paugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	havent_eaten(t_philo *philo)
{
	int	i;
	int	have_eaten;

	i = 0;
	have_eaten = 0;
	while (i < philo->setup->n_of_philos)
	{
		if (philo[i].meals == philo[i].setup->must_eat)
			have_eaten++;
		i++;
	}
	if (have_eaten == philo->setup->n_of_philos)
		return (0);
	return (1);
}

void	last_meal(t_philo *philo)
{
	pthread_mutex_lock(philo->meal_locker);
	philo->last_meal = elapsed_time(philo->setup->first_meal);
	pthread_mutex_unlock(philo->meal_locker);
}

void	print(t_philo *philo, char *status)
{
	long int	time_now;
	pthread_mutex_lock(philo->setup->print_locker);
	time_now = elapsed_time(philo->setup->first_meal);
	printf("%5ld %3d %s", time_now, philo->id, status);
	pthread_mutex_unlock(philo->setup->print_locker);
}
