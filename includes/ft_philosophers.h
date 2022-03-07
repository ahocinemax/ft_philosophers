/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosophers.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 01:51:56 by ahocine           #+#    #+#             */
/*   Updated: 2022/03/07 01:54:06 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PHILOSOPHERS_H
# define FT_PHILOSOPHERS_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# define _STD_OUT	1
# define _STD_ERR	2

typedef enum e_input_error
{
	argc_incorrect,
	meals_too_long,
	non_numerical,
	phil_too_long,
	time_too_long,
	empty_arg
}			t_input_error;

void	ft_check_arg(int argc, char **argv);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
int		ft_isdigit(int c);

#endif
