/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 18:53:30 by albealva          #+#    #+#             */
/*   Updated: 2024/10/28 18:25:45 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->args->forks[philo->ffork]);
	philo_print("\033[0mhas taken a fork 🍴", philo, UNLOCK);
	pthread_mutex_lock(&philo->args->forks[philo->sfork]);
	philo_print("\033[0mhas taken a fork 🍴", philo, UNLOCK);
	pthread_mutex_lock(&philo->args->meal);
	philo_print("\033[1;90mis eating 🍽️", philo, UNLOCK);
	philo->last_ate = get_time();
	pthread_mutex_unlock(&philo->args->meal);
	new_sleep(philo->args->time_to_eat, philo->args);
	pthread_mutex_lock(&philo->args->meal);
	philo->ate_times++;
	pthread_mutex_unlock(&philo->args->meal);
	pthread_mutex_unlock(&philo->args->forks[philo->sfork]);
	pthread_mutex_unlock(&philo->args->forks[philo->ffork]);
}
