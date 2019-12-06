/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoye <djoye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 19:54:37 by djoye             #+#    #+#             */
/*   Updated: 2019/12/06 18:02:51 by djoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "lem_in.h"

t_routes		*route_line(t_head *head)
{
	int			i;
	t_routes	*routes;
	t_room		*room;
	int			c;

	i = 0;
	c = 0;
	while(head->matrix[0][i])
		if(head->matrix[0][i++] == '1')
			c++;
	routes = (t_routes*)malloc(sizeof(t_routes));
	routes->start = (t_route**)malloc(sizeof(t_route*) * (c + 1));
	routes->step = (int*)malloc(sizeof(int) * (c + 1));
	i = 0;
	c = 0;
	while(head->matrix[0][i])
	{
		if(head->matrix[0][i] == '1')
		{
			room = head->first;
			while(room)
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
	while(head->matrix[l] && head->matrix[l][i])
	{
		if (ft_strequ(tmp->room->name, "end"))
			return (routes);
		if(head->matrix[l][i] == '1' && tmp->prev->room->id != i && tmp->prev->room->id != l)
		{
			room = head->start;
			while(room)
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
		routes->step[c]= i;
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
	while(routes->start[c])
	{
		tmp = routes->start[c];
		while(tmp)
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
	while(routes->start[c])
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
	while(i <= head->count_lem || if_free_route(routes))
	{
		c = 0;
		while(routes->start[c])
		{
			tmp = routes->start[c];
			while (tmp->next)
			{
				if (tmp->lem_id != 0 && tmp->next->lem_id == 0)
				{
					tmp->next->lem_id = tmp->lem_id;
					printf("L%d-%s ", tmp->next->lem_id, tmp->next->room->name);
					tmp->lem_id = 0;
					if (ft_strequ("end", tmp->next->room->name))
						tmp->next->lem_id = 0;
					break ;
				}
				tmp = tmp->next;
			}
			if (routes->start[c]->lem_id == 0 && i <= head->count_lem)
			{
				routes->start[c]->lem_id = i++;
				printf("L%d-%s ", routes->start[c]->lem_id, routes->start[c]->room->name);
			}
			c++;
		}
		printf("\n");
	}
	return (routes);
}
