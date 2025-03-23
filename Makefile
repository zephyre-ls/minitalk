# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lduflot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/23 23:49:38 by lduflot           #+#    #+#              #
#    Updated: 2025/03/24 00:02:25 by lduflot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###############################
##ARGUMENTS/MACRO

CC = cc
CFLAGS = -ggdb -Wall -Wextra -Werror
NAME = minitalk

###############################
##SOURCES

FT_PRINTF_DIR = ft_printf
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a

FILES = 

OBJS = $(FILES:.c=.o)

###############################
##RULES

all: $(FT_PRINTF_LIB) $(NAME)

$(FT_PRINTF_LIB):
	@echo "Compilation de ft_printf..."
	@make -C $(FT_PRINTF_DIR)

$(NAME): $(OBJS)
	@echo "Lancement du programme"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(FT_PRINTF_LIB)

%.o: %.c
	@$(CC) $(CFLAGS) -I$(FT_PRINTF_DIR) -c $< -o $@

clean:
	@echo "Mr.Larbin nettoie..."
	@rm -f $(OBJS)
	@make -C $(FT_PRINTF_DIR) clean
fclean: clean
	@echo "Mr.Larbin nettoie encore plus..."
	@rm -f $(NAME)
	@make -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

