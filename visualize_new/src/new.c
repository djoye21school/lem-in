/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdoughnu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:07:07 by sdoughnu          #+#    #+#             */
/*   Updated: 2019/12/13 16:08:13 by sdoughnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in_viz.h"

t_stack		*new_stack(char *st, int iter)
{
	t_stack *a;

	if (!(a = (t_stack*)malloc(sizeof(t_stack))))
		return (NULL);
	a->name = st;
	a->i = iter;
	a->x = 1;
	a->y = 1;
	return (a);
}

int			add_pat(t_stack *new, t_path *pat)
{
	t_stack **aaa;
	int r;

	r = 0;
	if (pat->now == pat->size - 1)
	{
		if (!(aaa = ft_memalloc(sizeof(t_stack *) + (pat->size + 15))))
			return (1);
		while (r <= pat->now)
		{
			aaa[r] = pat->arr[r];
			r++;
		}
		free(pat->arr);
		pat->arr = aaa;
		pat->size = pat->size + 15;
	}
	(pat->now) += 1;
	pat->arr[pat->now] = new;
	return (0);
}

char 		*ft_strcut(char *str, char d)
{
	char *s;
	int i;

	while (str[i] && str[i] != d)
		i++;
	if (!(s = (char*)malloc(sizeof(char) * i)))
		return (NULL);
	i = 0;
	while (str[i] && str[i] != d)
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
