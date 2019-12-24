/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdoughnu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 18:14:23 by sdoughnu          #+#    #+#             */
/*   Updated: 2019/12/20 18:14:25 by sdoughnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in_viz.h"

t_stack     *where_room(t_path *pat, char *str, char c)
{
    int i;

    i = 0;
    while (i <= pat->now)
    {
        if (!(strcmp_name(pat->arr[i], str, c)))
            return (pat->arr[i]);
        i++;
    }
    return (NULL);
}

t_stack     *copy(t_stack *from)
{
    t_stack *new;

    if (!(new = (t_stack*)malloc(sizeof(t_stack))))
        return (NULL);
    new->i = from->i;
    new->name = from->name;
    new->x = from->x;
    new->y = from->y;
    new->next = NULL;
    return (new);
}

int         new_in_first(t_stack **yes, t_stack *new)
{
    t_stack *buf;

    if (!*yes)
        *yes = new;
    else
    {
        buf = (*yes)->next;
        (*yes)->next = new;
        new->next = buf;
    }
    return (1);

}

int         ox_eeee(t_path *pat, char *str)
{
    t_stack *one;
    t_stack *two;

    if (!(one = where_room(pat, str, '-')))
        return (0);
    while (*str && *str != '-')
        str++;
    if (*str == '-')
        str++;
    if (!(two = where_room(pat, str, '\n')))
        return (0);
   new_in_first(&one, copy(two));
   new_in_first(&two, copy(one));
//   printf("%s - ", one->name);
//    printf("%s\n", two->name);
    printf("connect %s - %s\n", one->name, one->next->name);
    return (1);
}