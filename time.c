/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugusto <paugusto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 19:10:45 by paugusto          #+#    #+#             */
/*   Updated: 2022/01/28 22:31:14 by paugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

//funcoes feitas pelo Paulo

void	msleep(long int time_in_ms)
{
	long int	start_time;

	while ((timestamp() - start_time) < time_in_ms)
		usleep(time_in_ms/10)
}

long int	timestamp(void)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000) ;
}

long int	elapsed_time(long int start_time)
{
	return ((timestamp() - start_time));
}

