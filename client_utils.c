/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 21:51:12 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/31 23:01:05 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//Pour convertir le PID via argv
int	ft_atoi(const char *nptr)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
	{
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nbr = nbr * 10 + (nptr[i] - '0');
		i++;
	}
	return (nbr);
}
