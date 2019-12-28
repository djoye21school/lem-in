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

#include "../../includes/lem_in_viz.h"

t_stack		*new_stack(char *st, int iter, int x, int y)
{
	t_stack *a;

	if (!(a = (t_stack*)malloc(sizeof(t_stack))))
		return (NULL);
	a->name = st;
	a->i = iter;
	a->x = x;
	a->y = y;
	a->next = NULL;
	return (a);
}

int			add_pat(t_stack *new, t_path *pat)
{
	t_stack **aaa;
	int r;

	r = 0;
	if (pat->now == pat->size - 1)
	{
		if (!(aaa = ft_memalloc(sizeof(t_stack *) * (pat->size + 15))))
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
	pat->now += 1;
	pat->arr[pat->now] = new;
	return (0);
}

char 		*ft_strcut(char *str, char d)
{
	char *s;
	int i;

	i = 0;
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

SDL_Rect 	init_cor(int x, int y, int w, int h)
{
	SDL_Rect	r;


	r.x = x + w / 2;
	r.y = y + h / 2;
	r.w = w;
	r.h = h;
	return (r);
}

void		end(t_stack **ant, int t)
{
	int i;

	i = 0;
	while (i < t)
	{
		if (ant[i]->move)
		{
			ant[i]->x = ant[i]->nx;
			ant[i]->y = ant[i]->ny;
			ant[i]->nx = -1;
			ant[i]->ny = -1;
			ant[i]->px = -1;
			ant[i]->py = -1;
			ant[i]->move = 0;
		}
		i++;
	}
}
