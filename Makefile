# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djoye <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/28 17:11:11 by djoye             #+#    #+#              #
#    Updated: 2019/12/28 17:12:20 by djoye            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	lem-in
FLAGS		=	-Wall -Wextra -Werror
VISU		=	visu
LIBDIR		=	./libft
LIBLINK		=	-L $(LIBDIR) -lft
LIB 		=	$(LIBDIR)/libft.a
LIB_VISU	=	-L ~/.brew/lib -lSDL2 -lSDL2_ttf -lSDL2_image

INCLUDES	= 	-I ./includes
INCLUDE		=	./includes
INCLUDES_VISU	=	-I ~/.brew/include/SDL2/ -D_THREAD_SAFE

OBJDIR		= 	objs

OBJDIR_ALGO	=	objs/algo
OBJDIR_VISU	=	objs/visu

SRCDIR_ALGO	=	srcs/algo
SRCDIR_VISU	=	srcs/visu

SRC_ALGO	=	main.c algo.c add_data.c check.c add_room.c lem_go.c
SRC_VISU	=	

OBJS_ALGO	=	$(addprefix $(OBJDIR_ALGO)/, $(SRC_ALGO:.c=.o))
OBJS_VISU	=	$(addprefix $(OBJDIR_VISU)/, $(SRC_VISU:.c=.o))

all: directory $(NAME)

$(NAME): $(OBJDIR_ALGO) $(LIB) $(OBJS_ALGO) $(INCLUDE)
	gcc $(FLAGS) -o $@ $(OBJS_ALGO) $(LIBLINK)

$(VISU): $(OBJDIR_VISU) $(LIB) $(OBJS_VISU) $(INCLUDE)
	gcc $(FLAGS) -o $@ $(OBJS_VISU) $(LIBLINK) $(LIB_VISU)

$(LIB):
	make -C $(LIBDIR)

$(OBJDIR_ALGO)/%.o: $(SRCDIR_ALGO)/%.c
	gcc $(FLAGS) -c $^ -o $@ $(INCLUDES)

$(OBJDIR_VISU)/%.o: $(SRCDIR_VISU)/%.c
	gcc $(FLAGS) -c $^ -o $@ $(INCLUDES) $(INCLUDES_VISU)

directory: $(OBJDIR) $(OBJDIR_ALGO) $(OBJDIR_VISU)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR_ALGO):
	mkdir -p $(OBJDIR_ALGO)

$(OBJDIR_VISU):
	mkdir -p $(OBJDIR_VISU)

clean:
	rm -rf $(OBJDIR)
	make -C $(LIBDIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(VISU)
	make -C $(LIBDIR) fclean

re: fclean all

.PHONY: clean all re fclean directory
