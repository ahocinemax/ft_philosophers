/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dead.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 10:35:22 by ahocine           #+#    #+#             */
/*   Updated: 2022/03/07 10:35:24 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_philosophers.h"

void	ft_destroy_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->state_access);
	pthread_mutex_unlock(philo->state_access);
	pthread_mutex_destroy(philo->state_access);
	free(philo->state_access);
}

static void	ft_main_loop(void *ptr)
{
	unsigned int	time;
	t_philo			*philo;
	t_args			*args;
	unsigned long	last_meal_tmp;

	args = ft_get_args();
	philo = (t_philo *)ptr;
	time = ft_get_time();
	pthread_mutex_lock(philo->state_access);
	last_meal_tmp = philo->last_meal;
	pthread_mutex_unlock(philo->state_access);
	usleep((args->time_to_die - time + last_meal_tmp) * 1000);
	time = ft_get_time();
	pthread_mutex_lock(philo->state_access);
	last_meal_tmp = philo->last_meal;
	if (time - last_meal_tmp >= args->time_to_die)
	{
		philo->state = dead;
		ft_display_routine(dead, philo->thread_id + 1, time);
		pthread_mutex_lock(args->check_arg);
		args->dead++;
		pthread_mutex_unlock(args->check_arg);
	}
	pthread_mutex_unlock(philo->state_access);
}

void	*ft_dead_timer(void *ptr)
{
	t_args			*arg;

	arg = ft_get_args();
	pthread_mutex_lock(arg->check_arg);
	while (!arg->dead && (!arg->max_meals || arg->satisfied != arg->nb_philo))
	{
		pthread_mutex_unlock(arg->check_arg);
		ft_main_loop(ptr);
		pthread_mutex_lock(arg->check_arg);
	}
	pthread_mutex_unlock(arg->check_arg);
	return (NULL);
}
