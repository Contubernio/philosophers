/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiktak.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 19:23:44 by albealva          #+#    #+#             */
/*   Updated: 2024/11/10 20:20:54 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

time_t	ft_get_current_time(t_data *data)
{
	static struct timeval	time;

	gettimeofday(&time, NULL);
	return (((time.tv_sec * 1000) + (time.tv_usec / 1000)) - data->time_start);
}

void	ft_sleep(t_data *data, time_t end)
{
	time_t	start;

	start = ft_get_current_time(data) + end;
	while (data->dead != 1)
	{
		if (ft_get_current_time(data) >= start)
			break ;
		usleep(200);
	}
}
