/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:31:17 by albealva          #+#    #+#             */
/*   Updated: 2024/11/10 21:58:07 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

int	fr_isgit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_is_number(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!fr_isgit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_args(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_is_number(argv[i]))
		{
			printf("\033[1;31mError:\033[0m Argument num %s \
			is not a number\n", argv[i]);
			return (1);
		}
		if (ft_atoi(argv[i]) < 0 && i != 6)
		{
			printf("\033[1;31mError:\033[0m Argument num %s is negative. \
			It must be positive.\n", argv[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_parse(int argc, char **argv, t_data *data)
{
	if (argc < 5 || argc > 6)
	{
		printf("\033[1;31mError:\033[0m     Incorrect number of arguments. \n\
\033[0;33mMandatory:\033[0m Philo Num, Time to Die, Time to Eat, Time to Sleep.\n\
\033[0;32mOptional:\033[0m  Number of times each philosopher must \
eat to end the simulation.\n");
		return (1);
	}
	if (ft_check_args(argc, argv) != 0)
		return (1);
	data->num_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->eat_verify = 0;
	data->dead = 0;
	if (argc == 6)
		data->num_must_eat = ft_atoi(argv[5]);
	else
		data->num_must_eat = -1;
	data->time_start = 0;
	return (0);
}
