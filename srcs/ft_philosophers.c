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

int	main(int argc, char *argv[])
{
	ft_check_arg(argc, argv);
	ft_init_args(argc, argv);
	ft_init_forks();
	ft_init_time_base();
	ft_play_rules();
	ft_destroy_forks();
	ft_destroy_args();
	return (0);
}
