/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 19:28:59 by albealva          #+#    #+#             */
/*   Updated: 2024/11/10 21:58:38 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*b;
	size_t	s;
	size_t	verif;

	verif = count * size;
	if (size != verif / count)
		return (0);
	s = (count * size);
	b = malloc(count * size);
	if (b != NULL)
	{
		ft_bzero(b, s);
		return (b);
	}
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				neg;
	long int		result;

	i = 0;
	neg = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
		if (result * neg < INT_MIN)
			return (0);
		if (result * neg > INT_MAX)
			return (-1);
	}
	return ((int)result * neg);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*a;
	size_t			i;

	a = s;
	i = 0;
	while (i < n)
	{
		a[i] = 0;
		i++;
	}
}

void	print(int id, t_data *data, int code)
{
	if (code == EAT)
	{
		pthread_mutex_lock(&data->eat);
		data->philo[id - 1].last_meal = ft_get_current_time(data);
		pthread_mutex_unlock(&data->eat);
	}
	pthread_mutex_lock(&data->print);
	if (code == EAT && !data->dead)
	{
		if (data->philo[id].num_eat == \
		data->num_must_eat)
			data->eat_verify++;
		printf("\033[38;5;214m%ld %d \033[38;5;46m%s\033[0m\n", \
		ft_get_current_time(data), id, "is eating 🍝 ");
	}
	if (code == FORK && !data->dead)
		printf("\033[38;5;214m%ld %d \033[38;5;22m%s\033[0m\n", \
		ft_get_current_time(data), id, "has taken a fork 🍴");
	if (code == SLEEP && !data->dead)
		printf("\033[38;5;214m%ld %d \033[38;5;33m%s\033[0m\n", \
		ft_get_current_time(data), id, "is sleeping 😴 💤 ");
	if (code == THINK && !data->dead)
		printf("\033[38;5;214m%ld %d \033[38;5;198m%s\033[0m\n", \
				ft_get_current_time(data), id, "is thinking 💭");
	pthread_mutex_unlock(&data->print);
}
