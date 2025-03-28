/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexamaj.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:54:11 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/28 10:16:07 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printletter(long long int nb)
{
	if (nb == 10)
		return (ft_printchar('A'));
	if (nb == 11)
		return (ft_printchar('B'));
	if (nb == 12)
		return (ft_printchar('C'));
	if (nb == 13)
		return (ft_printchar('D'));
	if (nb == 14)
		return (ft_printchar('E'));
	if (nb == 15)
		return (ft_printchar('F'));
	return (0);
}

int	ft_printhexamaj(int nb)
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
		count = count + ft_printletter(n);
	else if (n >= 16)
	{
		count = count + ft_printhexamaj(n / 16);
		count = count + ft_printhexamaj(n % 16);
	}
	return (count);
}
