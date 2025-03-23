/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 00:11:05 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/24 00:18:02 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "ft_printf/ft_printf.h"
# include <unistd.h>
# include <signal.h>
# include <sys/types.h>
# include <stdlib.h>


/* Fonctions ok
// Write ft_printf signql
// ◦ write
◦ ft_printf et tout équivalent que VOUS avez codé
◦ signal
◦ sigemptyset
◦ sigaddset
◦ sigaction
◦ kill
◦ getpid
◦ malloc
◦ free
◦ pause
◦ sleep
◦ usleep
◦ exit 
OK pour utiliser une variable globale par programme (1 client, 1 serveur)


Vous devez réaliser un programme de communication sous la forme d’un client et
d’un serveur.
• Le serveur doit être lancé en premier et doit, après le lancement, afficher son PID.
• Le client prend deux paramètres :
◦ Le PID du serveur.
◦ Une chaîne de caractères à transmettre.
• Le client doit communiquer au serveur la chaîne passée en paramètre.
Une fois la chaîne entièrement reçue, le serveur doit l’afficher.
• Le serveur doit être capable d’afficher la chaîne rapidement. Par rapidement, on
entend que si vous pensez que c’est trop long, alors c’est sûrement trop long.
1 seconde pour afficher 100 caractères, c’est COLOSSAL !
• Votre serveur doit pouvoir recevoir des chaînes de plusieurs clients à la suite sans
nécessiter d’être relancé.
• La communication entre vos programmes doit se faire uniquement à l’aide de
signaux UNIX.
• Vous ne pouvez utiliser que les deux signaux suivants : SIGUSR1 et SIGUSR2.

*/

#endif
