/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoye <djoye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 14:29:27 by djoye             #+#    #+#             */
/*   Updated: 2019/12/10 19:45:43 by djoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# define BUFF_SIZE 1

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
    int             id;
    char            *name;
	int			    x;
	int			    y;
    struct s_room   *next;
}                   t_room;

typedef struct	    s_head
{
    int             count_lem;
    int             count_room;
    int             count_route;
    int             count_instr;
    char            *instruction;
    t_room          *first;
    t_room          *start;
    t_room          *end;
    int             **matrix;
    char            **split;
}                   t_head;

typedef struct      s_route
{
    int             lem_id;
    int             level;
    t_room          *room;
    struct s_route  *prev;
    struct s_route  *next;
}                   t_route;

typedef struct      s_routes
{
    int             *step;
    t_route         **start;
}                   t_routes;

t_head              *add_data(t_head *head);
t_room		        *add_room(t_head *head, char *str, int flag);
t_head              *map(t_head *head);
t_head		        *add_connect(t_head *head, char *str);
t_routes	        *route_line(t_head *head);
t_routes		    *route_traffic(t_head *head, t_routes *routes, int i, int c, int flag);
t_routes		    *count_step(t_routes *routes);
t_routes		    *lem_go(t_head *head, t_routes *routes);
void			    print_lem_position(t_routes *routes);
t_head		        *map(t_head *head);
t_head			    *upd_map(t_head *head);

#endif
