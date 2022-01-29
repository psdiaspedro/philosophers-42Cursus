/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diner_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugusto <paugusto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 22:05:27 by paugusto          #+#    #+#             */
/*   Updated: 2022/01/28 22:35:49 by paugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	last_meal(t_philo *philo)
{
	pthread_mutex_lock(philo->meal_locker);
	philo->inf->last_meal = elapsed_time(philo->inf->first_meal);
	pthread_mutex_unlock(philo->meal_locker);
}

void	print(t_philo *philo, int status)
{
	long int	time_now;

	pthread_mutex_lock(philo->inf->print_locker);
	time_now = elapsed_time(philo->inf->first_meal);
	if (status == FORK)
		printf("%5ld %3d has taken a fork", time_now, philo->id);
	else if (status == EAT)
		printf("%5ld %3d is eating", time_now, philo->id);
	else if (status == SLEEP)
		printf("%5ld %3d is sleeping", time_now, philo->id);
	else if (status == THINK)
		printf("%5ld %3d is thinking", time_now, philo->id);
	else if (status == DIED)
		printf("%5ld %3d died", time_now, philo->id);
	pthread_mutex_unlock(philo->inf->print_locker);
}
