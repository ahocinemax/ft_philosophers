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
	t_args			*arg;

	philo = (t_philo *)ptr;
	arg = ft_get_args();
	pthread_mutex_lock(arg->display);
	while (!arg->dead && (!arg->max_meals || arg->satisfied != arg->nb_philo))
	{
		pthread_mutex_unlock(arg->display);
		time = ft_get_time();
		usleep((arg->time_to_die - time - philo->last_meal) * 1000);
		time = ft_get_time();
		pthread_mutex_trylock(arg->display);
		if (time - philo->last_meal >= arg->time_to_die)
		{
			philo->state = dead;
			ft_display_routine(dead, philo->thread_id, time);
			arg->dead++;
		}
	}
	pthread_mutex_unlock(arg->display);
	return (NULL);
}
