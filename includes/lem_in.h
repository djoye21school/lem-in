/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoye <djoye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 14:29:27 by djoye             #+#    #+#             */
/*   Updated: 2019/12/23 17:13:02 by djoye            ###   ########.fr       */
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

typedef struct	    s_room
{
    int             level;
    int             lem_id;
    int             visit;
    char            *name;
	int			    x;
	int			    y;
    struct s_room   *follow;
    struct s_room   **link;
    struct s_room   *next;
    struct s_room   *prev;
    struct s_room   *queue;
}                   t_room;

typedef struct      s_routes
{
    int             *step;
    t_room          **start;
}                   t_routes;

typedef struct      s_head
{
    int             count_lem;
    int             count_room;
    int             count_route;
    char            *instruction;
    t_room          *first;
    t_room          *start;
    t_room          *end;
    t_room          *q_stack;
    t_room          *q_last;
    char            **split;
    t_routes        *routes;
}                   t_head;

t_head		    	*read_file(t_head *head, int fd);
t_head              *add_data(t_head *head);
int				    find_chr(char *str, int i, char c);
t_room		        *add_room(t_head *head, char *str);
t_room		        *room_param(t_room *room, char *str, char *x, char *y);
int				    check_replay(t_head *head, char *str, int x, int y);
t_head			    *add_connect(t_head *head, char *str);
t_room			    *find_room(t_head *head, char *buf);
t_room			    *connect(t_head *head, t_room *first, t_room *second);


t_head			    *algo(t_head *head);
int			    	check_end(t_head *head);

t_head		        *add_queue(t_head *head);
t_room			    *pop_queue(t_head *head);

t_head			    *route(t_head *head);
t_head 			    *clear_room_attribute(t_head *head);
t_routes		    *count_step(t_routes *routes);

t_routes		    *lem_go(t_head *head, t_routes *routes);

void		        print_stack(t_head *head);

t_head              *map(t_head *head);
t_routes	        *route_line(t_head *head);
t_routes		    *route_traffic(t_head *head, t_routes *routes, int i, int c, int flag);
void			    print_lem_position(t_routes *routes);
t_head		        *map(t_head *head);
int 			    upd_map(t_head *head);
int				    min_val(t_head *head, int l, int c);
int				    recurse(t_head *head, int l, int c, int i, int flag);

#endif