/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:53:11 by lduflot           #+#    #+#             */
/*   Updated: 2024/12/05 13:09:40 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include "ft_printf.h"

int		ft_printf(const char *type, ...);
int		ft_printhexamaj(int nb);
int		ft_printadress(void *adress);
int		ft_printhexaminus(int nb);
int		ft_printnbr(int nb);
int		ft_printchar(char c);
int		ft_printstr(char *str);
int		ft_printnbrunsigned(int nb);

#endif
