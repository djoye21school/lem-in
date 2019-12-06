# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdoughnu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/06 10:56:43 by sdoughnu          #+#    #+#              #
#    Updated: 2019/12/06 10:56:44 by sdoughnu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = visu

SRC =  main_viz.c

INC = 	./include
OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror -c
CC = gcc
INC_LIB = ../libft/

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) -o $(NAME) -I $(INC_LIB) -L ../libft/ -lft -L ./lib/ -l SDL2-2.0.0 $(OBJ)

%.o: src/%.c
	$(CC) $(FLAGS) -I $(INC) -o $@ -c $<

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
