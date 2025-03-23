# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lduflot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/29 15:18:44 by lduflot           #+#    #+#              #
#    Updated: 2025/03/24 00:10:23 by lduflot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###############################
##ARGUMENTS/MACRO

MAKEFLAGS += -s ##rend silencieu le make
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

###############################
##SOURCES

FILES =	ft_printf.c \
		ft_printadress.c \
		ft_printhexamaj.c \
		ft_printhexaminus.c \
		ft_printnbr.c \
		ft_printchar.c \
		ft_printstr.c \
		ft_printnbrunsigned.c

OBJS = $(FILES:.c=.o)

###############################
##RULES

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Compilation de ft_printf"
	@ar rcs $(NAME) $(OBJS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
clean:
	@rm -f $(OBJS)
fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
