/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:37:05 by ahocine           #+#    #+#             */
/*   Updated: 2022/05/31 16:37:06 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_philosophers.h"

static unsigned long	*ft_get_time_base(void)
{
	static unsigned long	time = 0;

	return (&time);
}

void	ft_init_time_base(void)
{
	struct timeval	time;
	unsigned long	*base;

	gettimeofday(&time, NULL);
	base = ft_get_time_base();
	*base = ((1000000 * time.tv_sec + time.tv_usec) / 1000);
}

unsigned long	ft_get_time(void)
{
	unsigned long	*base;
	struct timeval	time;

	base = ft_get_time_base();
	gettimeofday(&time, NULL);
	return (((1000000 * time.tv_sec + time.tv_usec) / 1000) - *base);
}
