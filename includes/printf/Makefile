# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eiglesia <eiglesia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/10 18:41:58 by eniglesi          #+#    #+#              #
#    Updated: 2025/10/28 13:54:52 by eiglesia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 	ft_printf.c
OBJS = $(SRC:.c=.o)
LIB = ./libft/libft.a
HEADERS = libft.h
NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror 

all: $(NAME)

%.o: %.c
	$(CC) -c $(FLAGS) $< -o $@

$(NAME): $(OBJS) ft_printf.h
	@make -s -C ./libft
	ar -crs $(NAME) $(OBJS) $(LIB) ./libft/*.o

clean:
	/bin/rm -f $(OBJS)
	@make clean -s -C ./libft

fclean: clean
	/bin/rm -f $(NAME)
	@make fclean -s -C ./libft
	
re: fclean all
