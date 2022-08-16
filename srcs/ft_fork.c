/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 06:07:40 by ahocine           #+#    #+#             */
/*   Updated: 2022/04/11 06:08:59 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_philosophers.h"

pthread_mutex_t	**ft_get_forks(void)
{
	static pthread_mutex_t	*forks = 0;

	return (&forks);
}

int	ft_init_forks(void)
{
	pthread_mutex_t	**forks;
	t_args			*args;
	unsigned long	i;

	args = ft_get_args();
	forks = ft_get_forks();
	*forks = (pthread_mutex_t *)malloc(args->nb_philo \
		* sizeof(pthread_mutex_t));
	if (!*forks)
	{
		ft_destroy_args();
		write(1, "FORKS KO\n", 9);
		return (0);
	}
	i = -1;
	while (++i < args->nb_philo)
	{
		if (pthread_mutex_init(&(*forks)[i], NULL))
		{
			ft_destroy_forks();
			return (0);
		}
	}
	write(1, "FORKS OK\n", 9);
	return (1);
}

void	ft_destroy_forks(void)
{
	pthread_mutex_t	**forks;
	t_args			*args;
	unsigned long	i;

	forks = ft_get_forks();
	args = ft_get_args();
	i = 0;
	while (i < args->nb_philo && forks[i])
		pthread_mutex_destroy(&(*forks)[i++]);
	free(*forks);
}
