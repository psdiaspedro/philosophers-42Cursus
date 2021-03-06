/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugusto <paugusto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:24:47 by paugusto          #+#    #+#             */
/*   Updated: 2022/02/01 11:02:16 by paugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_arguments(int argc, char **argv)
{
	int	count;
	int	i;
	int	j;

	count = 1;
	while (count < argc)
	{
		i = 1;
		while (argv[i])
		{
			j = 0;
			while (argv[i][j])
			{
				if (!ft_isdigit(argv[i][j]) || ft_atol(argv[i]) == 0
					|| ft_atol(argv[i]) > MAX_INT)
				{
					printf("syntax error\n");
					exit(EXIT_FAILURE);
				}
				j++;
			}
			i++;
		}
		count++;
	}
}

void	validate(int argc, char **argv)
{
	check_arguments(argc, argv);
	if (argc < 5 || argc > 6)
	{
		printf("wrong syntax, please try again\n");
		exit(EXIT_FAILURE);
	}
}
