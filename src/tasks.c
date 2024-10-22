/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tasks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:03:02 by albealva          #+#    #+#             */
/*   Updated: 2024/10/22 16:15:43 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	*cycle_of_life(void *params)
{
	t_philo	*philo;
	t_args	*args;

	philo = (t_philo *)params;
	args = philo->args;
	if (philo->id % 2 && args->philo_count > 1)
		new_sleep(args->time_to_eat / 50, args);
	while (!args->stop_condition && !args->max_ate)
	{
		philo_eat(philo);
		philo_print("\033[1;32mis sleeping 😴", philo, UNLOCK);
		new_sleep(args->time_to_sleep, args);
		philo_print("\033[38;5;208mis thinking 🤔", philo, UNLOCK);
	}
	return (NULL);
}

static void	exit_threads(t_args *args)
{
	int	i;

	if (args->philo_count == 1)
		pthread_detach(args->philos[0].thread_id);
	else
	{
		i = -1;
		while (++i < args->philo_count)
			pthread_join(args->philos[i].thread_id, NULL);
	}
	i = -1;
	while (++i < args->philo_count)
		pthread_mutex_destroy(&args->forks[i]);
	pthread_mutex_destroy(&args->meal);
	pthread_mutex_destroy(&args->writing);
	i = -1;
	while (++i < args->philo_count)
		free(args->philos[i].pos_str);
	free(args->philos);
	free(args->forks);
}

int	start_threads(t_args *args)
{
	int	i;

	i = -1;
	args->start_time = get_time();
	while (++i < args->philo_count)
	{
		args->philos[i].last_ate = get_time();
		if (pthread_create(&args->philos[i].thread_id,
				NULL, cycle_of_life, &(args->philos[i])))
			return (0);
	}
	philo_dead(args, args->philos);
	pthread_mutex_unlock(&args->writing);
	exit_threads(args);
	return (1);
}