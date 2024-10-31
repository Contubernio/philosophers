/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:46:04 by albealva          #+#    #+#             */
/*   Updated: 2024/10/28 18:25:29 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_dead(t_args *args, t_philo *philo)
{
	int	i;

	while (!args->max_ate)
	{
		i = -1;
		while (++i < args->philo_count && !args->stop_condition)
		{
			pthread_mutex_lock(&args->meal);
			if ((int)(get_time() - philo[i].last_ate) >= args->time_to_die)
			{
				philo_print("\033[1;31mdied 💀", &philo[i], LOCK);
				args->stop_condition = 1;
			}
			pthread_mutex_unlock(&args->meal);
		}
		if (args->stop_condition)
			break ;
		i = 0;
		pthread_mutex_lock(&args->meal);
		while (args->eat_count_max && i < args->philo_count
			&& philo[i].ate_times >= args->eat_count_max)
			i++;
		args->max_ate = (i == args->philo_count);
		pthread_mutex_unlock(&args->meal);
	}
}
