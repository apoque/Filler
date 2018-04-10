# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apoque <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/15 15:03:55 by apoque            #+#    #+#              #
#    Updated: 2018/04/03 20:44:16 by apoque           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Werror -Wextra -Wall

NAME = apoque.filler

INC = filler.h

SRC =	main.c\
		filler.c\
		algo.c\
		algo2.c\
		algo3.c\

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) libft/*.c libft/Makefile
	make -C libft
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) libft/libft.a

clean :
	cd libft ; make clean ; cd ..
	rm -rf $(OBJ)

fclean : clean
	cd libft ; make fclean ; cd ..
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
