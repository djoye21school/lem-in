/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdoughnu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 15:45:21 by sdoughnu          #+#    #+#             */
/*   Updated: 2019/12/26 15:45:27 by sdoughnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in_viz.h"

char 	*find_name(char *str)
{
	int		i;
	char	*room;

	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '\n')
		i++;
	if (!(room = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (*str && *str != ' ' && *str != '\n')
	{
		room[i] = *str;
		str++;
		i++;
	}
	room[i] = '\0';
	return (room);
}

char 	*record(char **str, t_path *pat, t_stack **ant)
{
	int		a;
	char 	*room;
	t_stack	*new;

	if (**str == 'L')
		(*str)++;
	a = ft_atoi(*str);
	while (ft_isdigit(**str))
		(*str)++;
	if (**str == '-')
		(*str)++;
	else
	{
		ft_putstr("Invalid connect\n");
		exit(0);
	}
	room = find_name(*str);
	while (**str && **str != ' ' && **str != '\n')
		(*str)++;
	new = find_stack(pat, room);
	ant[a - 1]->next = new;
	ant[a - 1]->move = 1;
	if (**str == ' ')
		(*str)++;
	return (*str);
}

void 	update_coor(t_stack **arr, int i)
{
	arr[i]->px = arr[i]->x;
	arr[i]->py = arr[i]->y;
	arr[i]->nx = arr[i]->next->x;
	arr[i]->ny = arr[i]->next->y;
	arr[i]->itog_X = 0;
	arr[i]->itog_Y = 0;
}

void	ant_go(t_stack **ant, int i)
{
	ant[i]->difx = ant[i]->nx - ant[i]->px;
	ant[i]->dify = ant[i]->ny - ant[i]->py;
	if (ant[i]->difx > 0)
		calculator(X, PL, ant, i);
	else if (ant[i]->difx < 0)
		calculator(X, MIN, ant, i);
	else if (ant[i]->dify > 0)
		calculator(Y, PL, ant, i);
	else if (ant[i]->dify < 0)
		calculator(Y, MIN, ant, i);
}

int 	draw_ants(t_path *pat, t_sdl *yep, t_stack **ant)
{
	int i;

	i = 0;
	while (i < pat->ant)
	{
		if (ant[i]->next != NULL)
			update_coor(ant, i);
		i++;
	}
	i = 0;
	while (i < pat->ant)
	{
		if (ant[i]->next)
		{
			ant_go(ant, i);
			ant[i]->next = NULL;
		}
		i++;
	}
	go_right_now(yep, ant, pat);
	end(ant, pat->ant);
	return (1);
}
































