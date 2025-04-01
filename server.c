/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 10:14:28 by lduflot           #+#    #+#             */
/*   Updated: 2025/04/01 13:57:23 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	* But du serveur :
	* Reception signaux client;
	* Traduit les donnes binaires en caractères;
	* Affiche le messqge reçu;
	* Affichage rapide (time ./client < 1 seconde);
	* Variable globale : simplifie ma gestion de mémoire,
	* evite l'ajout de pointeur de pointeur.
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

char	*g_string = NULL;

/*
 * bit_index compteur de bit recu
 * << 1 | 1 = add 1
 * << 1 = add 0
 */
void	add_bit(int signum, unsigned char *current_char, int *bit_index)
{
	if (signum == SIGUSR1)
		*current_char = (*current_char << 1) | 1;
	else
		*current_char = (*current_char << 1);
	(*bit_index)++;
}

/*
 * Current = "actuel";
 * bit_index=8 = 1 octet = Caractere complet;
 * malloc size+2 = stock current_c et \0;
 */
void	add_in_string(unsigned char current_char, int *size, int signum)
{
	char	*new_string;

	new_string = malloc(*size + 2);
	if (!new_string)
		return (free_memory(signum));
	if (g_string)
	{
		ft_memcpy(new_string, g_string, *size);
		free(g_string);
	}
	new_string[*size] = current_char;
	new_string[*size + 1] = '\0';
	g_string = new_string;
	(*size)++;
}

/*
 *Structure SIGACTION
 * sa_handler : ft a exe qd le signal arrive
 * sa_mask : bloque les signaux temporairement pendant l'exe
 * sa_flag : optionnel, modif cpt par defaut du signal =
 * SA_RESTART(reprendre une fonction interrompue;
 * SA_SIGINFO(info supplementaire sur le signal);
 * Main: initialise à sigemptyset = evite erreur valgrind.
*/
void	handle_signal(int signum)
{
	static int				size = 0;
	static int				bit_index = 0;
	static unsigned char	current_char = 0;

	add_bit(signum, &current_char, &bit_index);
	if (bit_index == 8)
	{
		if (current_char == '\0')
		{
			ft_printf("%s\n", g_string);
			free(g_string);
			g_string = NULL;
			size = 0;
		}
		else
		{
			add_in_string(current_char, &size, signum);
		}
		bit_index = 0;
		current_char = 0;
	}
}

void	free_memory(int signum)
{
	(void)signum;
	if (g_string)
	{
		free(g_string);
		g_string = NULL;
	}
	exit (0);
}

/*
	* Le processus possède un id unique = PID
	* pid_t getpid() = id du processus
	* pid_t getpgrp() = id groupe de processus
	* pid_t getppid() = id du père du processus
	* Boucle infini : permet de laisser le serveur ouvert;
*/
int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;
	int					i;

	pid = getpid();
	ft_printf("PID serveur : %d\n", pid);
	sa.sa_handler = handle_signal;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	sa.sa_handler = free_memory;
	sigaction(SIGINT, &sa, NULL);
	i = 1;
	while (++i)
		i--;
	return (0);
}
