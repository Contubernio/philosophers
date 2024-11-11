/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 19:33:10 by albealva          #+#    #+#             */
/*   Updated: 2024/11/10 20:21:41 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

void	ft_join_thread(t_data *data)
{
	int	i;

	i = -1;
	while (data->philo && ++i < data->num_philos)
		pthread_join(data->philo[i].thread, NULL);
}

int	main(int argc, char **argv)
{
	t_data		data;
	int			i;

	if (ft_parse(argc, argv, &data) != 0)
		return (1);
	ft_init_philos(&data);
	ft_init_forks(&data);
	i = -1;
	while (++i < data.num_philos)
	{
		if (pthread_create(&data.philo[i].thread, NULL, \
		ft_routine, (void *)&data.philo[i]))
			return (ft_exit(&data), 1);
	}
	ft_sleep(&data, 10);
	ft_monitoring(&data);
	ft_join_thread(&data);
	return (ft_exit(&data), 0);
}
