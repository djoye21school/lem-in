/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_old.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoye <djoye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 13:47:40 by djoye             #+#    #+#             */
/*   Updated: 2019/12/14 14:33:52 by djoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				upd_map(t_head *head)
{
	int			l;
	int			c;
	int			min;
	int			i;

	l = 0;
	c = 0;
	i = 0;
	while (l < head->count_room)
	{
		c = -1;
		while (++c < head->count_room)
			if (head->matrix[l][c] > (min = min_val(head, l, c)))
			{
				if (head->matrix[l][c] > min + 1)
				{
					printf("m = %d, l = %d, c = %d, min = %d", head->matrix[l][c], l, c, min);
					i++;
				}
				head->matrix[l][c] =  min + 1;
			}
		l++;
	}
	return (i);
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
	routes = head->routes;
	
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

t_head			*map(t_head *head)
{
	int			l;
	int			c;

	head->matrix = (int**)malloc(sizeof(int*) * head->count_room);
	l = -1;
	while (++l < head->count_room)
	{
		c = -1;
		head->matrix[l] = (int*)malloc(sizeof(int) * head->count_room);
		while (++c < head->count_room)
			head->matrix[l][c] = 0;
	}
	return (head);
}

int				recurse(t_head *head, int l, int c, int i, int flag)
{
	t_route		*tmp;
	t_room		*room;
	int			id;

	while (l < head->count_room && c < head->count_room)
	{
			if ((l == head->count_room - 1 || c == head->count_room - 1) && head->matrix[l][c] > 0)
			{
				i++;
				return (1);
			}
			if (recurse(head, flag == 1 ? ++l : l, flag == 0 ? ++c : c, i, flag))
			{
				if (!head->routes->start[i])
					head->routes->start[i] = (t_route*)malloc(sizeof(t_route));
				tmp = head->routes->start[i];
				while (tmp)
					tmp = tmp->next;
			id = flag == 1 ? l : c; 
			room = head->first;
				while (room)
					if (room->id == id)
						break ;
				tmp->room = room;
				tmp->next = NULL;			
				if (flag == 1 && (i = -1))
					flag = 0;
				else if ((l = -1))
					flag = 1;				
				return (1);
			}
			flag == 1 ? l++ : i++;
	}
	return (0);
}