# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lduflot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/23 23:49:38 by lduflot           #+#    #+#              #
#    Updated: 2025/03/31 22:58:25 by lduflot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###############################
##ARGUMENTS/MACRO

CC = cc
CFLAGS = -ggdb -Wall -Wextra -Werror
NAME_SERVER = server
NAME_CLIENT = client

###############################
##SOURCES

FT_PRINTF_DIR = ft_printf
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a
FILES_SERVER = server.c \
								server_utils.c
FILES_CLIENT = client.c \
							 client_utils.c
OBJS_SERVER = $(FILES_SERVER:.c=.o)
OBJS_CLIENT = $(FILES_CLIENT:.c=.o)

###############################
##RULES

all: $(FT_PRINTF_LIB) $(NAME_SERVER) $(NAME_CLIENT)

$(FT_PRINTF_LIB):
	@echo "Compilation de ft_printf..."
	@make -s -C $(FT_PRINTF_DIR)

$(NAME_CLIENT): $(OBJS_CLIENT)
	@echo "./client /PID_SERVEUR /txt"
	@$(CC) $(CFLAGS) $(OBJS_CLIENT) $(FT_PRINTF_LIB) -o $(NAME_CLIENT)

$(NAME_SERVER): $(OBJS_SERVER)
	@echo "./server"
	@$(CC) $(CFLAGS) $(OBJS_SERVER) $(FT_PRINTF_LIB) -o $(NAME_SERVER)



%.o: %.c
	@$(CC) $(CFLAGS) -I$(FT_PRINTF_DIR) -c $< -o $@


clean:
	@echo "Nettoyage des .o"
	@rm -f $(OBJS_SERVER) $(OBJS_CLIENT)
	@make -C $(FT_PRINTF_DIR) clean
fclean: clean
	@echo "Nettoyage des .o et programme"
	@rm -f $(NAME_CLIENT) $(NAME_SERVER)
	@make -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
