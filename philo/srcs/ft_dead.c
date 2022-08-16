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
	pthread_mutex_lock(philo->global_access);
	pthread_mutex_unlock(philo->global_access);
	pthread_mutex_destroy(philo->global_access);
	free(philo->global_access);
}

void	*ft_dead_timer(void *ptr)
{
	unsigned long	time;
	t_philo			*philo;
	t_args			*arg;
	unsigned long	last_meal_tmp;

	philo = (t_philo *)ptr;
	arg = ft_get_args();
	last_meal_tmp = 0;
	pthread_mutex_lock(arg->display);
	while (!arg->dead && (!arg->max_meals || arg->satisfied != arg->nb_philo))
	{
		pthread_mutex_unlock(arg->display);
		time = ft_get_time();
		usleep((arg->time_to_die - time + last_meal_tmp) * 1000);
		time = ft_get_time();
		pthread_mutex_lock(philo->global_access);
		last_meal_tmp = philo->last_meal;
		if (time - last_meal_tmp >= arg->time_to_die)
		{
			philo->state = dead;
			ft_display_routine(dead, philo->thread_id + 1, time);
			pthread_mutex_lock(arg->display);
			arg->dead++;
			pthread_mutex_unlock(arg->display);
		}
		pthread_mutex_unlock(philo->global_access);
		pthread_mutex_lock(arg->display);
	}
	pthread_mutex_unlock(arg->display);
	return (NULL);
}
