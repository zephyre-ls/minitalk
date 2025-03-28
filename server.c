/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 10:14:28 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/28 10:40:40 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//PID = Process IDentifier
//Code unique attributé a tous processus lors de son demarrage
// commande "ps" = liste PID
// 
pid_t	pid;
pid = getpid();


int	main(int argc, char **argv)
{
	if(argc == 1)
	{


	}
	else
		ft_printf("%s\n", "Erreur, un seul arguments attendu");
}
