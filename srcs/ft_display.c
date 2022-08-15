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

void	ft_display_message(int code)
{
	if (code == NO_MEAL)
		ft_putstr_fd("Pas de repas pour cette fois. Repassez plus tard.\n", \
		_STD_ERR);
	else if (code == NO_PHILO)
		ft_putstr_fd("Personne à l'horizon. Repassez plus tard.\n", _STD_ERR);
	else if (code == THREAD_ERR)
		ft_putstr_fd("Initialisation des threads echouee. Reessayez.\n", \
		_STD_ERR);
	else if (code == NO_TIME)
		ft_putstr_fd("Meme pas commence que c'est deja fini... Il nous faut\
 plus de temps !\n",	_STD_ERR);
	if (code == NO_MEAL || code == NO_PHILO || code == THREAD_ERR || \
		code == NO_TIME)
		exit(EXIT_FAILURE);
	if (code == HEADER)
		ft_putstr_fd("\
._____________________________________.\n\
|    ms    |  id  |                   |\n\
|_____________________________________|\n", _STD_OUT);
	else if (code == FOOTER)
		ft_putstr_fd("\
|_____________________________________|\n", _STD_OUT);
}

void	ft_display_error(t_input_error error)
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
de philosophes [0 - 999]\n", _STD_ERR);
	else if (error == meals_too_long)
		ft_putstr_fd("Erreur : NUMBER_OF_TIMES_EACH_PHILOSOPHER_MUST_EAT \
doit etre entre [0 - 99]\n", _STD_ERR);
	else if (error == time_too_long)
		ft_putstr_fd("Reessayez avec des durees plus courtes.\n", _STD_ERR);

	else
		ft_putstr_fd("Erreur : TIME_TO_DIE, TIME_TO_EAT, TIME_TO_SLEEP \
doivent etre entre [0 - 9999]\n", _STD_ERR);
	exit(EXIT_FAILURE);
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