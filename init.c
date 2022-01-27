/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugusto <paugusto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:43:48 by paugusto          #+#    #+#             */
/*   Updated: 2022/01/27 17:41:19 by paugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


int	init(t_infos *infos, int argc, char **argv)
{
	infos->n_of_philos = ft_atoi(argv[1]);
	infos->time_to_die = ft_atoi(argv[2]);
	infos->time_to_eat = ft_atoi(argv[3]);
	infos->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		infos->must_eat = ft_atoi(argv[5]);
	if (infos->n_of_philos == 0 || infos->time_to_die == 0
		|| infos->time_to_eat == 0 || infos->time_to_sleep == 0)
		return (0);
	if (argv[5] && infos->must_eat == 0)
		return (0);
	return (1);
}

void	init_philosophers(t_infos *infos, t_philo **philos)
{
	int	i;

	*philos = malloc(sizeof(t_philo) * infos->n_of_philos);
	if(*philos == NULL)
	{
		printf("memory allocation fail\n");
		//sair do philo
	}
	i = 0;
	while (i < infos->n_of_philos)
	{
		(*philos)[i].id = i + 1;
		(*philos)[i].left_fork = i + 1;
		(*philos)[i].right_fork = i;
		i++;
	}
	(*philos)[--i].left_fork = 0;
}
