/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 13:35:13 by quvan-de          #+#    #+#             */
/*   Updated: 2024/08/12 13:55:51 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

struct	s_arg;

typedef struct s_philo
{
	int				philo_id;
	int				total_meals;
	int				total_meals1;
	time_t			last_meal;
	int				philo_count;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	time_t			life_limit;
	int				stop;
	time_t			start_time;
	pthread_mutex_t	lock_print;
	pthread_mutex_t	*l_f;
	pthread_mutex_t	*r_f;
	struct	s_arg	*arg;
}					t_philo;

typedef struct s_arg
{
	int				philo_count;
	int				philo_id;
	time_t			start_time;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	int				dead;
	int				total_meals;
	pthread_mutex_t	*forks;
	pthread_t		*tids;
	pthread_mutex_t	lock_print;
	t_philo			*all_philo;
}					t_arg;

void	taking_forks(t_philo *philo);
void	eating(t_philo *philo);
void	sleeping(t_philo *philo);
void	thinking(t_philo *philo);
long	ft_time(void);
void	ft_usleep(int ms);
int		ft_atoi(const char *str);
int		ft_is_digit(char *str);
int		ft_cnt_of_meals(t_philo *philo);
void	*ft_galina_monitor(void *args);
void	*ft_process(void *args);
void	ft_init_philosophers(t_arg *args);
void	ft_init_mutex(t_arg *args);
void	ft_init_threads(t_arg *args);
void	ft_end_threads(t_arg *args);
int		ft_init_args(t_arg *args, int argc, char **argv);
void	ft_check_args(void);
void	free_all(t_arg *args);
void	unlock_and_destroy_mutex(t_arg *args);

#endif
