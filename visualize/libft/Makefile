# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdoughnu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/09 16:41:58 by sdoughnu          #+#    #+#              #
#    Updated: 2019/04/10 13:48:50 by sdoughnu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = $(wildcard *.c)
OBJ = *.o

all: $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra -I libft.h -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	
clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
