/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:37:20 by ahocine           #+#    #+#             */
/*   Updated: 2022/05/31 16:37:21 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_philosophers.h"

static void	start_routine(t_philo *philo)
{
	pthread_t	tid;
	t_args		*arg;

	arg = ft_get_args();
	pthread_create(&tid, NULL, &ft_dead_timer, philo);
	pthread_detach(tid);
	while (!arg->dead && (!arg->max_meals || arg->satisfied < arg->nb_philo))
	{
		ft_take_fork(philo);
		ft_eat(philo);
		ft_drop_fork(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
}

static void	init_philo(t_philo *philo)
{
	pthread_mutex_t	**forks;
	t_args			*args;

	args = ft_get_args();
	philo->state = thinking;
	philo->last_meal = 0;
	philo->meals = 0;
	forks = ft_get_forks();
	// printf("Philo %d initialized.\n", philo->thread_id);
	philo->right_fork = &(*forks)[philo->thread_id];
	if (!philo->thread_id)
		philo->left_fork = &(*forks)[args->nb_philo - 1];
	else
		philo->left_fork = &(*forks)[philo->thread_id - 1];
}

static void	*create_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	init_philo(philo);
	start_routine(philo);
	return (NULL);
}

static void	ft_play(t_philo *philos)
{
	unsigned long	i;
	t_args			*args;

	args = ft_get_args();
	i = 0;
	while (i < args->nb_philo)
	{
		philos[i].thread_id = i;
		if (pthread_create(&philos[i].tid, NULL, create_philo, &philos[i]))
			break ;
		i++;
	}
	if (i != args->nb_philo)
	{
		ft_display_message(THREAD_ERR);
		args->dead = 1;
	}
	while (--i)
		if (pthread_join(philos[i].tid, NULL))
			return ;
	if (pthread_join(philos[0].tid, NULL))
		return ;
}

void	ft_play_rules(void)
{
	t_philo	*philos;
	t_args	*args;

	args = ft_get_args();
	philos = malloc(sizeof(t_philo) * args->nb_philo);
	if (!philos)
		return ;
	ft_display_message(HEADER);
	ft_play(philos);
	free(philos);
	ft_display_message(FOOTER);
}
