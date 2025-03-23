/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:51:40 by lduflot           #+#    #+#             */
/*   Updated: 2024/12/05 11:35:01 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr(int nb)
{
	long long	n;
	int			count;

	count = 0;
	n = nb;
	if (n < 0)
	{
		count = count + ft_printchar('-');
		n = -n;
	}
	if (n >= 0 && n <= 9)
		count = count + ft_printchar(n + '0');
	else
	{
		count = count + ft_printnbr(n / 10);
		count = count + ft_printnbr(n % 10);
	}
	return (count);
}
