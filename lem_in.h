/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoye <djoye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 14:29:27 by djoye             #+#    #+#             */
/*   Updated: 2019/11/29 18:02:09 by djoye            ###   ########.fr       */
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

typedef struct	s_head
{
    int         count_lem;
    int         count_room;
    int         count_route;
    int         count_instr;
    char        *instruction;
    t_room      *first;
    t_room      *start;
    t_room      *end;
    char        **matrix;
    char        **split;
}               t_head;

t_head          *add_head(t_head *head);
t_head		    *map(t_head *head);

#endif
