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
LINK_FLAGS = `sdl2-config --libs`
INK_FLAGS = `sdl2-config --cflags`

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) -o $(NAME) -I $(INC_LIB) $(LINK_FLAGS) -L ../libft/ -lft  $(OBJ)

%.o: src/%.c $(INC)
	$(CC) $(FLAGS) -I $(INC) $(INK_FLAGS) -o $@ -c $<

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
