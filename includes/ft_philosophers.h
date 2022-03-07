/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosophers.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 01:51:56 by ahocine           #+#    #+#             */
/*   Updated: 2022/03/07 01:54:06 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PHILOSOPHERS_H
# define FT_PHILOSOPHERS_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>

# define _STD_OUT	1
# define _STD_ERR	2

# define NO_PHILO	1
# define NO_MEAL	2
# define THREAD_ERR	3
# define HEADER		4
# define FOOTER		5

typedef enum e_input_error
{
	argc_incorrect,
	meals_too_long,
	non_numerical,
	phil_too_long,
	time_too_long,
	empty_arg
}			t_input_error;

typedef enum e_state
{
	thinking,
	eating,
	taking_fork,
	sleeping,
	dead,
	undefined,
}			t_state;

typedef struct s_philo
{
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	unsigned long	last_meal;
	int				thread_id;
	t_state			state;
	unsigned long	meals;
	pthread_t		*tid;
}			t_philo;

typedef struct s_args
{
	unsigned long	nb_philo;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	unsigned long	max_meals;
	unsigned long	satisfied;
	int				dead;
	pthread_mutex_t	*prompt;
}			t_args;

void			ft_init_args(int argc, char **argv);
void			ft_check_arg(int argc, char **argv);
void			ft_putstr_fd(char *s, int fd);
void			ft_display_message(int code);
void			ft_take_fork(t_philo *philo);
void			ft_drop_fork(t_philo *philo);
void			*ft_dead_timer(void *ptr);
void			ft_think(t_philo *philo);
void			ft_sleep(t_philo *philo);
void			ft_init_time_base(void);
int				ft_atoi(const char *nb);
void			ft_eat(t_philo *philo);
void			ft_destroy_forks(void);
void			ft_destroy_args(void);
pthread_mutex_t	**ft_get_forks(void);
void			ft_init_forks(void);
void			ft_play_rules(void);
t_args			*ft_get_args(void);
unsigned long	ft_get_time(void);
int				ft_isdigit(int c);

#endif
