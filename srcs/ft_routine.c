/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 10:31:37 by ahocine           #+#    #+#             */
/*   Updated: 2022/03/07 10:31:41 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_philosophers.h"

void	ft_eat(t_philo *philo)
{
	t_args			*args;
	unsigned long	time;
	unsigned int	tto_eat;

	args = ft_get_args();
	time = ft_get_time();
	tto_eat = args->time_to_eat;
	philo->state = eating;
	philo->meals++;
<<<<<<< HEAD
	philo->last_meal = time;
	pthread_mutex_lock(args->display);
=======
>>>>>>> parent of f035007... A
	ft_display_routine(eating, philo->thread_id + 1, time);
	(void)time;
	if (philo->meals == args->max_meals)
		args->satisfied++;
	pthread_mutex_unlock(args->display);
	usleep(tto_eat * 1000);
}

void	ft_take_fork(t_philo *philo)
{
	t_args			*args;
	unsigned long	time;

	args = ft_get_args();
	if (philo->thread_id % 2)
		usleep(1000);
	philo->state = taking_fork;
	time = ft_get_time();
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(args->display);
	ft_display_routine(taking_fork, philo->thread_id + 1, time);
	pthread_mutex_unlock(args->display);
	if (philo->left_fork == philo->right_fork)
	{
		usleep(args->time_to_die * 1000 + 500);
		return ;
	}
	pthread_mutex_lock(philo->right_fork);
	time = ft_get_time();
	ft_display_routine(taking_fork, philo->thread_id + 1, time);
}

void	ft_drop_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->right_fork);
	if (philo->left_fork == philo->right_fork)
		return ;
	pthread_mutex_unlock(philo->left_fork);
}

void	ft_sleep(t_philo *philo)
{
	unsigned long	time;
	t_args			*args;
	unsigned int	tto_sleep;

	args = ft_get_args();
	time = ft_get_time();
	philo->state = sleeping;
	pthread_mutex_lock(args->display);
	ft_display_routine(sleeping, philo->thread_id + 1, time);
	tto_sleep = args->time_to_sleep;
	pthread_mutex_unlock(args->display);
	usleep(tto_sleep * 1000);
}

void	ft_think(t_philo *philo)
{
	unsigned long	time;
	t_args			*args;

	time = ft_get_time();
	args = ft_get_args();
	pthread_mutex_lock(args->display);
	ft_display_routine(thinking, philo->thread_id + 1, time);
	pthread_mutex_unlock(args->display);
	philo->state = thinking;
}
