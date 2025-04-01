/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 21:50:22 by lduflot           #+#    #+#             */
/*   Updated: 2025/04/01 09:48:07 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*tmps;
	char		*tmpd;
	size_t		i;

	tmpd = dest;
	tmps = src;
	i = 0;
	if (src == NULL && dest == NULL)
		return (0);
	while (i < n)
	{
		tmpd[i] = tmps[i];
		i++;
	}
	return ((char *)dest);
}
