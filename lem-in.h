/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoye <djoye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 14:29:27 by djoye             #+#    #+#             */
/*   Updated: 2019/11/28 18:34:37 by djoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE 1

# include <string.h>
# include <ctype.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdio.h>

typedef struct	s_room
{
    int         id;
    char        *name;
	int			x;
	int			y;
}               t_room;

typedef struct	s_head
{
    int         count_lem;
    int         count_room;
    int         count_route;
    char        *instruction;
    t_room      *start;
    t_room      *end;
    char        **matrix;
    char        **split;
}               t_head;

char            *ft_strjoin(char const *s1, char const *s2);
int             ft_strequ(char const *s1, char const *s2);
t_head          *add_head(t_head *head);
t_head		    *map(t_head *head);
char		    **ft_strsplit(char const *s, char c);
char	        *ft_strchr(const char *s, int c);
char	        *ft_strsub(char const *s, unsigned int start, size_t len);
size_t	        ft_strlen(const char *s);
int		        ft_atoi(const char *str);

#endif
