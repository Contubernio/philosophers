/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 18:51:47 by albealva          #+#    #+#             */
/*   Updated: 2024/10/23 19:00:34 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define UNLOCK 1
# define LOCK 0

# define ERR_USAGE \
	"\033[1;31mUsage: ./philosophers <# philosophers> <time to die> <time to eat>\
 <time to sleep> [# times each philo must eat to finish the sim]\n"

struct	s_args;

typedef struct s_philo
{
	int				id;
	int				ate_times;
	int				ffork;
	int				sfork;
	char			*pos_str;
	unsigned long	last_ate;
	struct s_args	*args;
	pthread_t		thread_id;
}					t_philo;

typedef struct s_args
{
	int				philo_count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eat_count_max;
	int				stop_condition;
	int				max_ate;
	unsigned long	start_time;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	meal;
	pthread_mutex_t	writing;
}					t_args;

// initialice.c
int					ft_initialize(t_args *args);
// print.c
void				philo_print(char *msg, t_philo *philo, int unlock);
int					ft_return_error(char *msg);
// eat.c
void				philo_eat(t_philo *philo);
// dead.c
void				philo_dead(t_args *args, t_philo *philo);
// tasks.c
int					start_threads(t_args *args);
// utils_itoa.c
int					ft_atoi(const char *nptr);
char				*ft_itoa(int n);
// utils.c
int					ft_strlen(char *str);
int					ft_isint(const char *nptr);
unsigned long		get_time(void);
void				new_sleep(unsigned long end, t_args *args);
// checks.c
int					ft_check_params(t_args *args, int argc, char *argv[]);

#endif
