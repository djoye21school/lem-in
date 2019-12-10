/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoye <djoye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 19:54:37 by djoye             #+#    #+#             */
/*   Updated: 2019/12/10 20:19:56 by djoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_routes		*route_line(t_head *head)
{
	int			i;
	t_routes	*routes;
	t_room		*room;
	int			c;

	i = -1;
	c = 0;
	while (++i < head->count_room)
		if (head->matrix[0][i] > 0)
			c++;
	routes = (t_routes*)malloc(sizeof(t_routes));
	routes->start = (t_route**)malloc(sizeof(t_route*) * (c + 1));
	routes->step = (int*)malloc(sizeof(int) * (c + 1));
	i = 0;
	c = 0;
	while (i < head->count_room)
	{
		if (head->matrix[0][i] > 0)
		{
			room = head->first;
			while (room)
			{
				if (room->id == i)
				{
					routes->start[c] = (t_route*)malloc(sizeof(t_route));
					routes->start[c]->room = room;
					route_traffic(head, routes, i, c, 1);
					c++;
					routes->start[c] = NULL;
					break ;
				}
				room = room->next;
			}
		}
		i++;
	}
	return (routes);
}

t_routes		*route_traffic(t_head *head, t_routes *routes, int i, int c, int flag)
{
	int			l;
	t_room		*room;
	t_route		*tmp;
	t_route		*previos;

	l = 0;
	tmp = routes->start[c];
	tmp->prev = (t_route*)malloc(sizeof(t_route));
	tmp->prev->room = head->start;
	while (l < head->count_room && i < head->count_room)
	{
		if (ft_strequ(tmp->room->name, "end"))
			return (routes);
		if (head->matrix[l][i] > 0 && tmp->prev->room->id != i && tmp->prev->room->id != l)
		{
			room = head->start;
			while (room)
			{
				if ((room->id == i && tmp->room->id == l) ||
					(room->id == l && tmp->room->id == i))
				{
					tmp->next = (t_route*)malloc(sizeof(t_route));
					tmp->next->room = room;
					if (flag == 1 && (i = -1))
						flag = 0;
					else if ((l = -1))
						flag = 1;
					previos = tmp;
					tmp = tmp->next;
					tmp->prev = previos;
					tmp->next = NULL;
					break ;
				}
				room = room->next;
			}
		}
		flag == 1 ? l++ : i++;
	}
	return (routes);
}

t_routes		*count_step(t_routes *routes)
{
	t_route		*tmp;
	int			i;
	int			c;

	c = 0;
	while (routes->start[c])
	{
		i = 1;
		tmp = routes->start[c];
		while (tmp)
		{
			tmp->lem_id = 0;
			tmp->level = i;
			tmp = tmp->next;
			i++;
		}
		routes->step[c] = i;
		printf("%d | %s | %d\n", c, routes->start[c]->room->name, i);
		c++;
	}
	return (routes);
}

int				if_free_route(t_routes *routes)
{
	int			c;
	t_route		*tmp;

	c = 0;
	while (routes->start[c])
	{
		tmp = routes->start[c];
		while (tmp)
		{
			if (tmp->lem_id != 0 && !ft_strequ(tmp->room->name, "end"))
				return (1);
			tmp = tmp->next;
		}
		c++;
	}
	return (0);
}

void			print_lem_position(t_routes *routes)
{
	t_route		*tmp;
	int			c;

	c = 0;
	while (routes->start[c])
	{
		tmp = routes->start[c];
		while (tmp)
		{
			if (tmp->lem_id != 0)
				printf("L%d-%s ", tmp->lem_id, tmp->room->name);
			tmp = tmp->next;
		}
		c++;
	}
	printf("\n");
}

t_routes		*lem_go(t_head *head, t_routes *routes)
{
	int			i;
	int			c;
	t_route		*tmp;

	i = 1;
	while (i <= head->count_lem || if_free_route(routes))
	{
		c = -1;
		while (routes->start[++c])
		{
			tmp = routes->start[c];
			while (tmp->next)
				if (tmp->lem_id != 0 && tmp->next->lem_id == 0)
					break ;
				else
					tmp = tmp->next;
			if (tmp->next == NULL && (tmp->lem_id = 0) == 0)
				tmp = tmp->prev;
			while (tmp && tmp->next && tmp->prev)
				if (tmp->lem_id != 0 && tmp->next->lem_id == 0 &&
				(tmp->next->lem_id = tmp->lem_id) &&
				printf("L%d-%s ", tmp->next->lem_id, tmp->next->room->name))
					tmp->lem_id = 0;
				else
					tmp = tmp->prev;
			if (routes->start[c]->lem_id == 0 && i <= head->count_lem &&
			(routes->start[c]->lem_id = i++))
				printf("L%d-%s ", routes->start[c]->lem_id, routes->start[c]->room->name);
		}
		printf("\n");
	}
	return (routes);
}

int				min_val(t_head *head, int l, int c)
{
	int			min_l;
	int			min_c;
	int			mem_l;

	if (l == 0 || c == 0)
		return (0);
	mem_l = l;
	min_l = head->count_room;
	l = 0;
	while (l < head->count_room && c < head->count_room - 1)
	{
		if (head->matrix[l][c] > 0 && min_l > head->matrix[l][c])
			min_l = head->matrix[l][c];
		l++;
	}
	min_c = head->count_room;

	l = mem_l;
	c = 0;
	while (c < head->count_room && l < head->count_room - 1)
	{
		if (head->matrix[l][c] > 0 && min_c > head->matrix[l][c])
			min_c = head->matrix[l][c];
		c++;
	}
	return (min_l < min_c ? min_l : min_c);
}

t_head			*upd_map(t_head *head)
{
	int			l;
	int			c;
	int			flag;

	l = 0;
	flag = 1;
	c = 0;
	while (l < head->count_room)
	{
		c = 0;
		while (c < head->count_room)
		{
			if (head->matrix[l][c] > 0)
			{
				head->matrix[l][c] = min_val(head, l, c) + 1;
				/*
				if (flag == 1 && (i = -1))
					flag = 0;
				else if ((l = -1))
					flag = 1;
					*/
			}
			c++;
		}
		l++;
		//flag == 1 ? l++ : i++;
	}
	return (head);
}