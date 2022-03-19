/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 06:37:40 by ahocine           #+#    #+#             */
/*   Updated: 2022/03/07 06:37:42 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_philosophers.h"

t_args	*ft_get_args(void)
{
	static t_args	arg;

	return (&arg);
}

void	ft_init_args(int argc, char *argv[])
{
	t_args	*args;

	args = ft_get_args();
	args->dead = 0;
	args->satisfied = 0;
	args->nb_philo = ft_atoi(argv[1]);
	if (!args->nb_philo)
		ft_display_message(NO_PHILO);
	args->time_to_die = ft_atoi(argv[2]);
	if (!args->time_to_die)
		ft_display_message(NO_MEAL);
	args->time_to_eat = ft_atoi(argv[3]);
	args->time_to_sleep = ft_atoi(argv[4]);
	args->max_meals = 0;
	if (argc == 6)
	{
		if (ft_atoi(argv[5]))
			args->max_meals = ft_atoi(argv[5]);
		else
			ft_display_message(NO_MEAL);
	}
	args->prompt = malloc(sizeof(pthread_mutex_t));
	if (!args->prompt)
		exit(EXIT_FAILURE);
	pthread_mutex_init(args->prompt, NULL);
}

void	ft_destroy_args(void)
{
	t_args	*arg;

	arg = ft_get_args();
	pthread_mutex_destroy(arg->prompt);
	free(arg->prompt);
}
