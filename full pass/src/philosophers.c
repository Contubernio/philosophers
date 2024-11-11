/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:59:48 by albealva          #+#    #+#             */
/*   Updated: 2024/11/10 22:01:51 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

void	eat(t_philo *philo, int id)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(&data->fork[philo->left_fork]);
	print(philo->id, data, FORK);
	if (data->num_philos == 1)
	{
		ft_sleep(data, data->time_to_die);
		printf("%u %d %s\n", (unsigned int)(ft_get_current_time(data)), id, \
		"\033[0;31mdied\033[0m");
		data->dead = 1;
		pthread_mutex_unlock(&data->fork[philo->left_fork]);
		return ;
	}
	pthread_mutex_lock(&data->fork[philo->right_fork]);
	print(philo->id, data, FORK);
	print(philo->id, data, EAT);
	data->philo[id - 1].num_eat++;
	ft_sleep(data, data->time_to_eat);
	pthread_mutex_unlock(&data->fork[philo->left_fork]);
	pthread_mutex_unlock(&data->fork[philo->right_fork]);
}

void	*ft_routine(void *arg)
{
	t_data	*data;
	t_philo	*philo;

	philo = (t_philo *)arg;
	data = philo->data;
	if (philo->id % 2 == 0)
		ft_sleep(data, data->time_to_eat / 2);
	while (data->dead != 1 || data->eat_verify >= data->num_philos)
	{
		eat(philo, philo->id);
		if (philo->num_eat == data->num_must_eat)
			data->eat_verify++;
		print(philo->id, data, SLEEP);
		ft_sleep(data, data->time_to_sleep);
		print(philo->id, data, THINK);
		if (data->eat_verify == data->num_philos)
			return (NULL);
	}
	return (NULL);
}

void	ft_init_forks(t_data *data)
{
	int	i;

	i = -1;
	data->fork = ft_calloc(data->num_philos, sizeof(pthread_mutex_t));
	if (!data->fork)
	{
		perror("Error: allocating memory for forks");
		exit(EXIT_FAILURE);
	}
	while (++i < data->num_philos)
	{
		if (pthread_mutex_init(&data->fork[i], NULL))
			return (ft_exit(data));
	}
	if (pthread_mutex_init(&(data->print), NULL))
		return (ft_exit(data));
	if (pthread_mutex_init(&(data->monitor), NULL))
		return (ft_exit(data));
	if (pthread_mutex_init(&(data->eat), NULL))
		return (ft_exit(data));
	data->dead = 0;
}

void	ft_init_philos(t_data *data)
{
	int	i;

	i = -1;
	data->philo = ft_calloc(data->num_philos, sizeof(t_philo));
	if (!data->philo)
	{
		perror("Error: allocating memory for philosophers");
		exit(EXIT_FAILURE);
	}
	while (++i < data->num_philos)
	{
		data->philo[i].id = i + 1;
		data->philo[i].last_meal = 0;
		data->philo[i].num_eat = 0;
		data->philo[i].left_fork = i;
		if (data->num_philos > 1)
			data->philo[i].right_fork = (i + 1) % data->num_philos;
		data->philo[i].data = data;
	}
	data->time_start = ft_get_current_time(data);
	return ;
}
