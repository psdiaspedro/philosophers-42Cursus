/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugusto <paugusto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 22:05:27 by paugusto          #+#    #+#             */
/*   Updated: 2022/02/01 11:01:34 by paugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print(t_philo *philo, char *status)
{
	long int	time_now;

	pthread_mutex_lock(philo->setup->print_locker);
	time_now = elapsed_time(philo->setup->first_meal);
	if (!philo->setup->philo_died)
		printf("%5ld %3d %s\n", time_now, philo->id, status);
	pthread_mutex_unlock(philo->setup->print_locker);
}

void	philo_died(t_philo *philo)
{
	pthread_mutex_lock(philo->setup->died_locker);
	philo->setup->philo_died = 1;
	pthread_mutex_unlock(philo->setup->died_locker);
}

int	get_meal(t_philo *philo)
{
	int	meals;

	pthread_mutex_lock(philo->setup->get_meals_locker);
	meals = philo->meals;
	pthread_mutex_unlock(philo->setup->get_meals_locker);
	return (meals);
}

int	philo_is_dead(t_philo *philo)
{
	int	dinner_is_over;

	pthread_mutex_lock(philo->setup->is_philo_died_locker);
	dinner_is_over = 0;
	if (philo->setup->philo_died)
		dinner_is_over = philo->setup->philo_died;
	pthread_mutex_unlock(philo->setup->is_philo_died_locker);
	return (dinner_is_over);
}

void	finish_dinner(t_philo *philo)
{
	pthread_mutex_lock(philo->setup->died_locker);
	philo->setup->philo_died = 1;
	pthread_mutex_unlock(philo->setup->died_locker);
}
