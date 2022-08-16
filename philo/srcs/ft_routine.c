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
	unsigned long	time;
	t_args			*args;

	args = ft_get_args();
	time = ft_get_time();
	pthread_mutex_lock(philo->global_access);
	philo->meals++;
	philo->last_meal = time;
	philo->state = eating;
	pthread_mutex_unlock(philo->global_access);
	ft_display_routine(eating, philo->thread_id + 1, time);
	pthread_mutex_lock(args->display);
	if (philo->meals == args->max_meals)
		args->satisfied++;
	pthread_mutex_unlock(args->display);
	usleep(args->time_to_eat * 1000);
}

void	ft_take_fork(t_philo *philo)
{
	unsigned long	time;
	t_args			*args;

	args = ft_get_args();
	if (philo->thread_id % 2)
		usleep(400);
	if (philo->thread_id % 2)
		pthread_mutex_lock(philo->right_fork);
	else
		pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(philo->global_access);
	philo->state = taking_fork;
	pthread_mutex_unlock(philo->global_access);
	time = ft_get_time();
	ft_display_routine(taking_fork, philo->thread_id + 1, time);
	if (philo->left_fork == philo->right_fork)
		return ((void)usleep(args->time_to_die * 1000 + 500));
	if (philo->thread_id % 2)
		pthread_mutex_lock(philo->left_fork);
	else
		pthread_mutex_lock(philo->right_fork);
	time = ft_get_time();
	ft_display_routine(taking_fork, philo->thread_id + 1, time);
}

void	ft_drop_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	if (philo->left_fork == philo->right_fork)
		return ;
	pthread_mutex_unlock(philo->right_fork);
}

void	ft_sleep(t_philo *philo)
{
	unsigned long	time;
	t_args			*args;

	args = ft_get_args();
	time = ft_get_time();
	ft_display_routine(sleeping, philo->thread_id + 1, time);
	pthread_mutex_lock(philo->global_access);
	philo->state = sleeping;
	pthread_mutex_unlock(philo->global_access);
	usleep(args->time_to_sleep * 1000);
}

void	ft_think(t_philo *philo)
{
	unsigned long	time;

	time = ft_get_time();
	ft_display_routine(thinking, philo->thread_id + 1, time);
	pthread_mutex_lock(philo->global_access);
	philo->state = thinking;
	pthread_mutex_unlock(philo->global_access);
}
