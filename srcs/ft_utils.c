/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 05:50:26 by ahocine           #+#    #+#             */
/*   Updated: 2022/04/11 05:59:27 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_philosophers.h"

int	ft_atoi(const char *nb)
{
	long	i;
	long	res;
	long	neg;

	i = 0;
	res = 0;
	neg = 1;
	while ((nb[i] >= 9 && nb[i] <= 13) || nb[i] == ' ')
		i++;
	if (nb[i] == '+' || nb[i] == '-')
	{
		if (nb[i] == '-')
			neg = -1;
		i++;
	}
	while (ft_isdigit(nb[i]))
	{
		res = res * 10 + nb[i] - '0';
		i++;
	}
	return ((int)res * (int)neg);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		while (*s)
			ft_putchar_fd(*s++, fd);
}

void	ft_display_routine(t_state stt, unsigned long tid, unsigned long time)
{
	t_args				*args;
	static const char	*str[] = \
	{
		"| %8ld    %03ld   \e[33mis thinking.      \e[0m|\n",
		"| %8ld    %03ld   \e[34mhas taken a fork. \e[0m|\n",
		"| %8ld    %03ld   \e[32mis eating.        \e[0m|\n",
		"| %8ld    %03ld   \e[35mis sleeping.      \e[0m|\n",
		"| %8ld    %03ld   \e[31mdied.             \e[0m|\n",
		NULL
	};

	args = ft_get_args();
	// pthread_mutex_lock(args->display);
	if (args->dead || (args->max_meals && args->satisfied >= args->nb_philo))
		return ;
	if (time > 99999999)
	{
		args->dead++;
		ft_putstr_fd("| End of simulation. Time is over. |\n", _STD_OUT);
		return ;
	}
	// pthread_mutex_unlock(args->display);
	printf(str[stt], time, tid);
}
