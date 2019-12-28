/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoye <djoye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 14:29:27 by djoye             #+#    #+#             */
/*   Updated: 2019/12/28 11:58:27 by djoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# define BUFF_SIZE 1000000

# include "./libft/libft.h"
# include <string.h>
# include <ctype.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdio.h>

typedef struct		s_room
{
	int				level;
	int				lem_id;
	int				visit;
	char			*name;
	int				x;
	int				y;
	struct s_room	*follow;
	struct s_room	**link;
	struct s_room	*next;
	struct s_room	*prev;
	struct s_room	*queue;
}					t_room;

typedef struct		s_head
{
	int				count_lem;
	int				count_room;
	int				count_route;
	char			*instruction;
	t_room			*first;
	t_room			*start;
	t_room			*end;
	t_room			*q_stack;
	t_room			*q_last;
	char			**split;
	int				*step;
	t_room			**routes;
	t_room			**last_ant;
}					t_head;

t_head				*read_file(t_head *head, int fd);
int					check_instruction(char *str);
t_head				*add_data(t_head *head);
int					find_chr(char *str, int i, char c);
t_room				*add_room(t_head *head, char *str);
t_room				*room_param(t_room *room, char *str, char *x, char *y);
int					max_int(char *str);
int					check_replay(t_head *head, char *str, int x, int y);
t_head				*add_connect(t_head *head, char *str);
t_room				*find_room(t_head *head, char *buf);
t_room				*connect(t_head *head, t_room *first, t_room *second);
int					check_start_end(t_head *head, int fd);
t_head				*create_routes(t_head *head);
t_head				*algo(t_head *head);
int					check_end(t_head *head);
t_room				*add_queue(t_head *head);
t_room				*pop_queue(t_head *head);
t_head				*route(t_head *head);
t_head				*clear_room_attribute(t_head *head);
t_head				*count_step(t_head *head);
int					if_free_route(t_head *head);
t_head				*lem_go(t_head *head);
int					go_to(t_head *head, int c, int flag);
int					use_route(t_head *head, int c);
int					print_lem(int nb, char *str, int flag);

#endif
