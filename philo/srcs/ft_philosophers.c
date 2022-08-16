/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosophers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 01:50:51 by ahocine           #+#    #+#             */
/*   Updated: 2022/03/07 01:51:09 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_philosophers.h"

static int	ft_check_param(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc != 5 && argc != 6)
		return (ft_display_error(argc_incorrect));
	i = 1;
	while (i != argc)
	{
		j = 0;
		if (i != 5 && !argv[i][0])
			ft_display_error(empty_arg);
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (ft_display_error(non_numerical));
			if (i == 1 && j > 2)
				return (ft_display_error(phil_too_long));
			if (i == 5 && j > 2)
				return (ft_display_error(meals_too_long));
			if (j > 3)
				return (ft_display_error(time_too_long));
			j++;
		}
		i++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	if (!ft_check_param(argc, argv))
		return (1);
	if (!ft_init_args(argc, argv))
		return (1);
	if (!ft_init_forks())
		return (1);
	ft_init_time_base();
	ft_play_rules();
	ft_destroy_forks();
	ft_destroy_args();
	return (0);
}
