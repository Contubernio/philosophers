/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:45:30 by albealva          #+#    #+#             */
/*   Updated: 2024/11/10 21:53:16 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

void	ft_exit(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_philos)
	{
		if (i == 0)
		{
			pthread_mutex_destroy(&data->print);
			pthread_mutex_destroy(&data->monitor);
			pthread_mutex_destroy(&data->eat);
		}
		if (&data->fork[i])
			pthread_mutex_destroy(&data->fork[i]);
	}
	if (data->fork)
		free(data->fork);
	if (data->fork)
		free(data->philo);
}
