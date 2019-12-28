/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdoughnu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 15:43:16 by sdoughnu          #+#    #+#             */
/*   Updated: 2019/12/25 13:04:27 by sdoughnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in_viz.h"

int 		check(t_stack *arr)
{
	if ((arr->x > WIN_W) || (arr->y > WIN_H))
	{
		ft_putstr("Invalid coordinate\n");
		return (1);
	}
	if (arr->x + house_w > WIN_W)
		arr->x = arr->x - (arr->x + house_w - WIN_W);
	if (arr->y + house_h > WIN_H)
		arr->y = arr->y - (arr->y + house_h - WIN_H);
	return (0);
}

int 		new_coor(t_path *pat)
{
	int i;

	i = 0;
	while (i <= pat->now)
	{
		if (check(pat->arr[i]))
			return (1);
		i++;
	}
	return (0);
}

t_stack 	*find_stack(t_path *pat, char *name)
{
	int i;

	i = 0;
	while (i <= pat->now)
	{
		if (!ft_strcmp(name, pat->arr[i]->name))
			return (pat->arr[i]);
		i++;
	}
	return (NULL);
}

int 		draw_line(t_path *pat, t_sdl *yep)
{
	int i;
	t_stack *stack;
	t_stack *buf;
	t_stack	*find;

	i = 0;
	while (i <= pat->now)
	{
		stack = pat->arr[i];
		buf = stack->next;
		while (buf)
		{
			if ((find = find_stack(pat, buf->name)))
			{
				if (SDL_RenderDrawLine(yep->ren, stack->x + onx, stack->y + ony, find->x + onx, find->y + ony))
					return (0);
				if (SDL_RenderDrawLine(yep->ren, stack->x + onx + 1, stack->y + ony, find->x + onx + 1, find->y + ony))
					return (0);
				if (SDL_RenderDrawLine(yep->ren, stack->x + onx, stack->y + ony + 1, find->x + onx, find->y + ony + 1))
					return (0);
				if (SDL_RenderDrawLine(yep->ren, stack->x + onx - 1, stack->y + ony, find->x + onx - 1, find->y + ony))
					return (0);
				if (SDL_RenderDrawLine(yep->ren, stack->x + onx, stack->y + ony - 1, find->x + onx, find->y + ony - 1))
					return (0);
			}
			buf = buf->next;
		}
		i++;
	}
	return (1);
}

char 	*move_ant(t_path *pat, t_sdl *yep, char **str, t_stack **ant)
{
	if (!*str)
		return (0);
	while (**str && **str != '\n')
	{
		record(str, pat, ant);
		SDL_SetRenderTarget(yep->ren, yep->fon);
		if (SDL_RenderCopy(yep->ren, yep->fon, NULL, NULL) != 0)
			error_st(1, yep);
		if (!draw_house(pat, yep))
			return (0);
	}
	if (**str == '\n')
		(*str)++;
	draw_ants(pat, yep, ant);
	return (*str);
}
