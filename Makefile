# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/01 18:47:45 by fgarzi-c          #+#    #+#              #
#    Updated: 2023/03/04 01:55:08 by fgarzi-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lib_minitalk.a
NAME_S = server
NAME_C = client
NAME_FT_PF = ./ft_printf/libftprintf.a
SRCS = server.c client.c ft_atoi.c
SERVER = server.c
CLIENT = client.c
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(%.c)
	@$(CC) $(CFLAGS) -c $(SRCS)
	@make -C ./ft_printf
	@ar rcs $(NAME) $(OBJS)
	@$(CC) $(CFLAGS) $(NAME) $(SERVER) $(NAME_FT_PF) -o $(NAME_S)
	@$(CC) $(CFLAGS) $(NAME) $(CLIENT) $(NAME_FT_PF) -o $(NAME_C)

%.c: %.o
	@$(CC) $(CFLAGS) -o $<

clean:
	@rm -f $(OBJS)
	@make clean -C ./ft_printf
	
fclean: clean
	@rm -f $(NAME) $(NAME_C) $(NAME_S)
	@make fclean -C ./ft_printf
	
re: fclean all

.PHONY: all clean fclean re
