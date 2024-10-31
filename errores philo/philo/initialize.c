/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:55:21 by albealva          #+#    #+#             */
/*   Updated: 2024/10/23 18:36:47 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_initialize_mutex(t_args *args)
{
	int	i;

	i = 0;
	while (i < args->philo_count)
	{
		if (pthread_mutex_init(&(args->forks[i]), NULL))
			return (1);
		i++;
	}
	if (pthread_mutex_init(&args->meal, NULL))
		return (1);
	if (pthread_mutex_init(&args->writing, NULL))
		return (1);
	return (0);
}

static int	ft_initialize_philosopher(t_args *args)
{
	int	i;

	i = 0;
	while (i < args->philo_count)
	{
		args->philos[i].ate_times = 0;
		args->philos[i].id = i + 1;
		args->philos[i].pos_str = ft_itoa(i + 1);
		if (!args->philos[i].pos_str)
			break ;
		args->philos[i].ffork = i;
		args->philos[i].sfork = (i + 1) % args->philo_count;
		args->philos[i].args = args;
		i++;
	}
	if (i != args->philo_count)
	{
		while (i >= 0)
		{
			free(args->philos[i].pos_str);
			i--;
		}
		return (1);
	}
	return (0);
}

int	ft_initialize(t_args *args)
{
	args->philos = malloc(sizeof(t_philo) * args->philo_count);
	if (!args->philos)
		return (0);
	args->forks = malloc(sizeof(pthread_mutex_t) * args->philo_count);
	if (!args->forks)
	{
		free(args->philos);
		return (0);
	}
	if (ft_initialize_mutex(args))
	{
		free(args->philos);
		free(args->forks);
		return (0);
	}
	if (ft_initialize_philosopher(args))
	{
		free(args->philos);
		free(args->forks);
		return (0);
	}
	return (1);
}
