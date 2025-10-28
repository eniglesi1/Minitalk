# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eiglesia <eiglesia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/10 13:08:14 by eniglesi          #+#    #+#              #
#    Updated: 2025/10/28 13:58:53 by eiglesia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_C = 	srcs/cliente.c
SRC_S = 	srcs/servidor.c

OBJ_C = $(SRC_C:.c=.o)
OBJ_S = $(SRC_S:.c=.o)

LIB = ./includes/printf/libftprintf.a

NAME_S = server
NAME_C = client
FLAGS = -Wall -Wextra -Werror

all: $(NAME_S) $(NAME_C)

%.o: %.c
	$(CC) -c $(FLAGS) $< -o $@

$(NAME_S): $(OBJ_S)
	@make -s -C ./includes/printf
	cc $(FLAGS) $(OBJ_S) $(LIB) -o $(NAME_S)

$(NAME_C): $(OBJ_C)
	@make -s -C ./includes/printf
	cc $(FLAGS) $(OBJ_C) $(LIB) -o $(NAME_C)

clean:
	/bin/rm -f $(OBJ_S) $(OBJ_C)
	@make clean -s -C ./includes/printf

fclean: clean
	/bin/rm -f $(NAME_C) $(NAME_S)
	@make fclean -s -C ./includes/printf
	
re: fclean all

