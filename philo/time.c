/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugusto <paugusto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 19:10:45 by paugusto          #+#    #+#             */
/*   Updated: 2022/01/31 19:35:24 by paugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	msleep(int time_in_ms)
{
	long	start_time;

	start_time = timestamp();
	while ((timestamp() - start_time) < (long)time_in_ms)
		usleep(10);
}

long	timestamp(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

long	elapsed_time(long firststamp)
{
	return (timestamp() - firststamp);
}
