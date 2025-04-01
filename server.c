/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 10:14:28 by lduflot           #+#    #+#             */
/*   Updated: 2025/04/01 09:57:00 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	* But du serveur :
	* Reception signaux client;
	* Traduit les donnes binaires en caractères;
	* Affiche le messqge reçu
	* Affichage rapide (time ./client < 1 seconde)
	* Bonus : Informe le client de la bonne réception
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*
 *Structure SIGACTION
 * sa_handler : ft a exe qd le signal arrive
 * sa_mask : bloque les signaux temporairement pendant l'exe 
 * sa_flag : optionnel, modif cpt par defaut du signal =
 * SA_RESTART(reprendre une fonction interrompue;
 * SA_SIGINFO(info supplementaire sur le signal);
*/

//Reception des signaux
// Signum = numero du signal
// Ecrire signal non conventionnel car nom de la fonction signal, peut porter a confusion

//Current = "actuel" donc = char acnnuel

static char	*string = NULL;
void	handle_signal(int signum)
{
	static int	size = 0;
	static unsigned char	current_char = 0; //stock le char bit par bit
	static int	bit_index = 0; // compte nbr de bit reçu
	char	*new_string;
	
	if (signum == SIGUSR1)
		current_char = (current_char << 1) | 1; //add 1 
	else
		current_char = (current_char << 1); // add 0
	bit_index++;

	//si reception de 8 bits = caractere complet
	if (bit_index == 8)
	{
		if (current_char == '\0')
		{
			ft_printf("%s\n", string);
			free(string);
			string = NULL;
			size = 0;
		}
		else
		{
			new_string = malloc(size + 2); //permet de stock current_char et \0
			if (!new_string)
			{
				free(string);
				string = NULL;
				return ;
			}
			if (string)
			{
				ft_memcpy(new_string, string, size);
				free(string);
			}
			new_string[size] = current_char;
			new_string[size + 1] = '\0';
			string = new_string;
			size++;
		}
		bit_index = 0; 
		current_char = 0;
	}
}

void	free_memory(int signum)
{
	(void)signum;

	if(string)
	{
		free(string);
		string = NULL;
	}
	exit (0);
}

//
/*void	mask_signal(int signum)
{
}*/


/* 
difference sleep/usleep
-temps et sleep renvoie 0 usleep rien
sleep(seconde) = endort le processus temps donne 
usleep = (microseconde)*/


/*
	* Le processus possède un id unique = PID
	* pid_t getpid() = id du processus
	* pid_t getpgrp() = id groupe de processus
	* pid_t getppid() = id du père du processus
*/

/*
	* struct sigaction (directement dans signal.h);
	* conventionnement on la defini en sa;
*/

/*
	* Utilisation d'une boucle infini pour que le serveur ne se ferme pas"
*/
int	main(void)
{
	struct sigaction sa;
	pid_t pid;

	pid = getpid();
	ft_printf("PID serveur : %d\n", pid);
	sa.sa_handler = handle_signal;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	sa.sa_handler = free_memory;
	sigaction(SIGINT, &sa, NULL);
	while(1)
		pause();
	return(0);
}
