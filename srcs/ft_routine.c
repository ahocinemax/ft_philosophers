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

	args = ft_get_args();
	time = ft_get_time();
	pthread_mutex_lock(args->prompt);
	philo->state = eating;
	philo->meals++;
	ft_putstr_fd("STATEMENT\n", _STD_OUT);
	(void)time;
	if (philo->meals == args->max_meals)
		args->satisfied++;
	pthread_mutex_unlock(args->prompt);
	usleep(args->time_to_eat * 1000);
}

void	ft_take_fork(t_philo *philo)
{
	t_args			*args;
	unsigned long	time;

	args = ft_get_args();
	if (philo->thread_id % 2)
		usleep(100);
	pthread_mutex_lock(philo->left_fork);
	philo->state = taking_fork;
	time = ft_get_time();
	ft_putstr_fd("STATEMENT\n", _STD_OUT);
	(void)time;
	if (philo->left_fork == philo->right_fork)
	{
		usleep(args->time_to_die * 1000 + 500);
		return ;
	}
	pthread_mutex_lock(philo->right_fork);
	time = ft_get_time();
	ft_putstr_fd("STATEMENT\n", _STD_OUT);
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

	args = ft_get_args();
	pthread_mutex_lock(args->prompt);
	time = ft_get_time();
	philo->state = sleeping;
	ft_putstr_fd("STATEMENT\n", _STD_OUT);
	(void)time;
	pthread_mutex_unlock(args->prompt);
	usleep(args->time_to_sleep * 1000);
}

void	ft_think(t_philo *philo)
{
	unsigned long	time;
	t_args			*args;

	args = ft_get_args();
	pthread_mutex_lock(args->prompt);
	time = ft_get_time();
	(void)time;
	philo->state = thinking;
	pthread_mutex_unlock(args->prompt);
}
