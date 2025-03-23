/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexamaj.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:54:11 by lduflot           #+#    #+#             */
/*   Updated: 2024/12/05 13:32:53 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*long long int	ft_complement2(long long int n);

void	ft_printbinaire(long long int n)
{
	if (n > 1)
	{
		ft_printbinaire(n / 2);
	}
	ft_printhexamaj(n % 2 + '0');
}

long long int ft_complement2(long long int n)
{
	unsigned long long int nb = (long long int)n;
	
	if (nb > 1)
	{
		ft_complement2(nb / 2);
	}
	ft_printchar(nb % 2 + '0');

	if (nb == 0)
		nb = 1;
	else if (nb == 1)
		nb = 0;
	return (nb);
}

long long int	ft_addone(long long int n)
{
	n = n + 1;
	return (n);
}
*/
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
/*
#include <stdio.h>

int	main(void)
{
	//int test1 = -255;
	long long int test = -255;
	int test2 = 255;

	ft_printhexamaj(test);
	printf("\ntest neg:%llX\n", (long long int)test);
	printf("test pos:%X\n", test2);
	return (0);
}*/
