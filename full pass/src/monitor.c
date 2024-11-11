/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:49:59 by albealva          #+#    #+#             */
/*   Updated: 2024/11/10 20:14:09 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

void	ft_are_you_dead(t_data *data, int i)
{
	if (ft_get_current_time(data) - data->philo[i].last_meal > \
	data->time_to_die)
	{
		pthread_mutex_lock(&data->monitor);
		if (data->dead == 0)
		{
			printf("\033[38;5;196m%u %d \033[1;31mdied 💀\033[0m\n", \
			(unsigned int)(ft_get_current_time(data) - \
			data->philo[i].last_meal), data->philo[i].id);
			data->dead = 1;
		}
		pthread_mutex_unlock(&data->monitor);
		pthread_mutex_unlock(&data->eat);
		return ;
	}
}

void	ft_monitoring(t_data *data)
{
	int	i;

	while (data->dead != 1 && data->eat_verify <= data->num_philos)
	{
		i = -1;
		while (++i < data->num_philos)
		{
			pthread_mutex_lock(&data->eat);
			if (data->eat_verify == data->num_philos)
			{
				pthread_mutex_unlock(&data->eat);
				return ;
			}
			ft_are_you_dead(data, i);
			pthread_mutex_unlock(&data->eat);
		}
	}
	return ;
}
