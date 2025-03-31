/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexaminus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:52:40 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/28 10:17:24 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//////////////////////////////////////////////////////////////////////////////
//En hexadecimal il y a 16 chiffres, 0 a 9 puis de 10 a 15 
//avantage= format compact, abreger ecriture binaire, facilite manipulation
//10=A 11=B 12=C 13=D 14=E 15=F 16=10 17=11
//nb / 16 = quotient entier
//nb - (quotient entier * 16) = reste 
//ex = 75/16 = 4 ; 75 -(4*16) = 11 = 4B (car b = 11)
/////////////////////////////////////////////////////////////////////////////

#include "ft_printf.h"

int	ft_printlettre(long long int nb)
{
	if (nb == 10)
		return (ft_printchar('a'));
	if (nb == 11)
		return (ft_printchar('b'));
	if (nb == 12)
		return (ft_printchar('c'));
	if (nb == 13)
		return (ft_printchar('d'));
	if (nb == 14)
		return (ft_printchar('e'));
	if (nb == 15)
		return (ft_printchar('f'));
	return (0);
}

int	ft_printhexaminus(int nb)
{
	int				count;
	unsigned int	n;

	count = 0;
	if (nb < 0)
		n = (unsigned int) nb;
	else
		n = (unsigned int) nb;
	if (n == 0)
	{
		write(1, "0", 1);
		count = 1;
		return (count);
	}
	if (n > 0 && n <= 9)
		count = count + ft_printchar(n + '0');
	else if (n >= 10 && n <= 15)
		count = count + ft_printlettre(n);
	else if (n >= 16)
	{
		count = count + ft_printhexaminus(n / 16);
		count = count + ft_printhexaminus(n % 16);
	}
	return (count);
}
