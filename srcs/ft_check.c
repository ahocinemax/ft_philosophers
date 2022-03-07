/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 01:50:19 by ahocine           #+#    #+#             */
/*   Updated: 2022/03/07 01:50:39 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_philosophers.h"

static void	ft_display_error(t_input_error error)
{
	if (error == argc_incorrect)
		ft_putstr_fd("Usage : \
./philo NB_OF_PHILO TIME_TO_DIE TIME_TO_EAT TIME_TO_SLEEP \
[NUMBER_OF_TIMES_EACH_PHILOSOPHER_MUST_EAT]\n", _STD_ERR);
	else if (error == empty_arg)
		ft_putstr_fd("Erreur : Argument vide non permis.\n", _STD_ERR);
	else if (error == non_numerical)
		ft_putstr_fd("Erreur : \
Seuls les entiers positifs sont acceptes. Pas de signe non plus.\n", _STD_ERR);
	else if (error == phil_too_long)
		ft_putstr_fd("Erreur : Choissisez un nombre valide \
de philosophes [0 - 999]\n", 2);
	exit(EXIT_FAILURE);
}

void	ft_check_arg(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc != 5 && argc != 6)
		ft_display_error(argc_incorrect);
	i = 1;
	while (i != argc)
	{
		j = 0;
		if (i != 5 && !argv[i][0])
			ft_display_error(empty_arg);
		printf("arg %d = [%s]\n", i, argv[i]);
		while (argv[i][j])
		{
			if (i == 1 && j > 2)
				ft_display_error(phil_too_long);
			if (j > 3)
			{
				if (i == 5)
					ft_display_error(meals_too_long);
				else
					ft_display_error(time_too_long);
			}
			if (!ft_isdigit(argv[i][j]))
				ft_display_error(non_numerical);
			j++;
		}
		i++;
	}
}
