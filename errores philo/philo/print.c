/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 19:59:08 by albealva          #+#    #+#             */
/*   Updated: 2024/10/23 19:06:46 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_print(char *msg, t_philo *philo, int is_unlock)
{
	char	*timestamp;

	timestamp = ft_itoa(get_time() - philo->args->start_time);
	pthread_mutex_lock(&philo->args->writing);
	if (!philo->args->stop_condition && !philo->args->max_ate)
		printf("\033[38;5;117m%s \033[38;5;46m%s %s\n",
			timestamp, philo->pos_str, msg);
	if (is_unlock)
		pthread_mutex_unlock(&philo->args->writing);
	free(timestamp);
}

int	ft_return_error(char *message)
{
	write(2, message, ft_strlen(message));
	return (0);
}
