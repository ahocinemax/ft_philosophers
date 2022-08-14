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

void	*ft_dead_timer(void *ptr)
{
	unsigned long	time;
	t_philo			*philo;
	t_args			*args;
	unsigned int	lastMeal;
	unsigned int	tto_die;

	philo = (t_philo *)ptr;
	args = ft_get_args();
	lastMeal = philo->last_meal;
	tto_die = args->time_to_die;
	pthread_mutex_lock(args->display);
	while (!args->dead && (!args->max_meals || \
		args->satisfied != args->nb_philo))
	{
		pthread_mutex_unlock(args->display);
		time = ft_get_time();
		usleep((tto_die - time - lastMeal) * 1000);
		time = ft_get_time();
		pthread_mutex_lock(args->display);
		if (time - lastMeal >= tto_die)
		{
			philo->state = dead;
			ft_display_routine(dead, philo->thread_id + 1, time);
			args->dead++;
		}
	}
	pthread_mutex_unlock(args->display);
	return (NULL);
}
