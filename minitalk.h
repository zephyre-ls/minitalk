/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 00:11:05 by lduflot           #+#    #+#             */
/*   Updated: 2025/04/01 14:04:51 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "ft_printf/ft_printf.h"
# include <unistd.h>
# include <signal.h>
# include <sys/types.h>
# include <stdlib.h>
# include <stdio.h>

//client
void	send_string(int pid, char *str);
void	translate_ascii_bit(int pid, unsigned char c);
void	check_pid(pid_t pid);

//server
void	handle_signal(int signum);
void	add_bit(int signum, unsigned char *current_char, int *bit_index);
void	add_in_string(unsigned char current_char, int *size, int signum);
void	free_memory(int signum);

//utils
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		ft_atoi(const char *nptr);

#endif
