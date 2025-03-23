/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbrunsigned.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:03:33 by lduflot           #+#    #+#             */
/*   Updated: 2024/12/05 11:35:43 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbrunsigned(int nb)
{
	unsigned int	n;
	int				count;

	count = 0;
	n = nb;
	if (n <= 9)
		count = count + ft_printchar(n + '0');
	else
	{
		count = count + ft_printnbr(n / 10);
		count = count + ft_printnbr(n % 10);
	}
	return (count);
}
