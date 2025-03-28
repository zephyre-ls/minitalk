/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printadress.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:57:21 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/28 10:16:29 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int	ft_print(long long int nb)
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

int	ft_printhexa(unsigned long nb)
{
	int				count;

	count = 0;
	if (nb <= 9)
		count = count + ft_printchar(nb + '0');
	else if (nb >= 10 && nb <= 15)
		count = count + ft_print(nb);
	else if (nb >= 16)
	{
		count = count + ft_printhexa(nb / 16);
		count = count + ft_printhexa(nb % 16);
	}
	return (count);
}

int	ft_printadress(void	*adress)
{
	unsigned long int	p;
	int					count;

	p = (unsigned long)adress;
	count = 0;
	if (adress == NULL)
		count = count + write(1, "(nil)", 5);
	else
	{
		count = count + write(1, "0x", 2);
		count = count + ft_printhexa(p);
	}
	return (count);
}
