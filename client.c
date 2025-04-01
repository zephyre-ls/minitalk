/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 10:13:49 by lduflot           #+#    #+#             */
/*   Updated: 2025/04/01 14:11:36 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	* But du client :
	* Entrer le PID du serveur (id.processus cible);
	* Traduit les caractères du message en ascii puis binaire
	* 1 char = 1 octet = 8 bit
	* Envoi chaque bit au serveur à l'aide de :
	* 	SIGURS1 = 1
	* 	SIGURS2 = 0
	* Affichage rapide (time ./client < 1 seconde)
	* Possibilite de renvoyer un message sans relancer serveur.
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*
 * Send_signal =
 * i = compteur qui va parcourir les 8 bits d'1 octet;
 * Boucle = Decremente pour parcourir les bits du plus significatif
 * au plus faible
 * c >> i = Decalage des bits vers la droite pour amener le bit
 * a la pos du bit de poids faible
 * %2==0 = savoir si bit de poids faible = 0 ou 1;
 * usleep (choix de usleep car sleep=seconde, usleep=microseconde);
 * usleep permet d'éviter d'envoyer les signaux trop rapidement;
 * permet au serveur de traiter chaque bit sans les oublier.
 * Kill = fonct° qui permet de send un signal a un processus avec PID
 */
void	translate_ascii_bit(int pid, unsigned char c)
{
	int	i;
	int	bit;

	i = 8;
	while (i > 0)
	{
		i--;
		bit = c >> i & 1;
		if (bit == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
	}
}

void	send_string(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		translate_ascii_bit(pid, str[i]);
		i++;
	}
	translate_ascii_bit(pid, str[i]);
}

/*
	* 0 = signal sans effet
	* Permet de voir si le process existe et si on peut
	* lui envoyer un signal.
	*/
void	check_pid(pid_t pid)
{
	if (kill(pid, 0) == -1)
	{
		ft_printf("%s Erreur/ Pid invalid\n");
		exit (EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		check_pid(pid);
		if (!pid)
		{
			ft_printf("%s Erreur/ PID invalid\n");
			exit(EXIT_FAILURE);
		}
		send_string(pid, argv[2]);
	}
	else
		ft_printf("%s", "Erreur/ [PID] [message] \n");
	return (0);
}
