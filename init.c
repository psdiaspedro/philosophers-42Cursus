/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugusto <paugusto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:43:48 by paugusto          #+#    #+#             */
/*   Updated: 2022/01/28 22:36:19 by paugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


int	init(t_inf *inf, char **argv)
{
	inf->n_of_philos = ft_atoi(argv[1]);
	inf->time_to_die = ft_atoi(argv[2]);
	inf->time_to_eat = ft_atoi(argv[3]);
	inf->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		inf->must_eat = ft_atoi(argv[5]);
	if (inf->n_of_philos == 0 || inf->time_to_die == 0
		|| inf->time_to_eat == 0 || inf->time_to_sleep == 0)
		return (0);
	if (argv[5] && inf->must_eat == 0)
		return (0);
	return (1);
}

void	init_mutex(t_philo *philos)
{
	pthread_mutex_init(philos->left_fork, NULL);
	pthread_mutex_init(philos->right_fork, NULL);
	pthread_mutex_init(philos->meal_locker, NULL);
	pthread_mutex_init(philos->inf->print_locker, NULL);
}

void	init_philosophers(t_inf *inf, t_philo **philos)
{
	int	i;

	*philos = malloc(sizeof(t_philo) * inf->n_of_philos);
	if(*philos == NULL)
	{
		printf("memory allocation fail\n");
		//sair do philo
	}
	i = 0;
	while (i < inf->n_of_philos)
	{
		(*philos)[i].id = i + 1;
		(*philos)[i].left_fork = i + 1;
		(*philos)[i].right_fork = i;
		i++;
	}
	(*philos)[--i].left_fork = 0;
}
