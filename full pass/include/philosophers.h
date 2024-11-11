/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:13:32 by albealva          #+#    #+#             */
/*   Updated: 2024/11/10 21:57:36 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <limits.h>
# include <stdatomic.h>

enum e_action
{
	DAED,
	EAT,
	FORK,
	SLEEP,
	THINK
};

typedef struct s_data
{
	int				dead;
	int				num_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_must_eat;
	time_t			time_start;
	atomic_int		eat_verify;
	struct s_philo	*philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
	pthread_mutex_t	monitor;
	pthread_mutex_t	eat;
}				t_data;

typedef struct s_philo
{
	int				id;
	int				right_fork;
	int				left_fork;
	int				num_eat;
	t_data			*data;
	pthread_t		thread;
	atomic_long		last_meal;
}				t_philo;

//args.c
int		fr_isgit(int c);
int		ft_is_number(const char *str);
int		ft_check_args(int argc, char **argv);
int		ft_parse(int argc, char **argv, t_data *data);

//exit.c
void	ft_exit(t_data *data);

//monitor.c
void	ft_are_you_dead(t_data *data, int i);
void	ft_monitoring(t_data *data);

//utiles.c
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
void	print(int id, t_data *data, int code);

//philosophers.c
void	*ft_routine(void *philo);
void	ft_init_forks(t_data *data);
void	ft_init_philos(t_data *data);

//tiktak.c
time_t	ft_get_current_time(t_data *data);
void	ft_sleep(t_data *data, time_t end);

#endif