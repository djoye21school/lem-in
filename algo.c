/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoye <djoye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 19:54:37 by djoye             #+#    #+#             */
/*   Updated: 2019/12/22 19:43:54 by djoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_routes		*count_step(t_routes *routes)
{
	t_room		*tmp;
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
		c++;
	}
	return (routes);
}

int				if_free_route(t_routes *routes)
{
	int			c;
	t_room		*tmp;

	c = 0;
	while (routes->start[c])
	{
		tmp = routes->start[c];
		while (tmp)
		{
			if (tmp->lem_id != 0 && !ft_strequ(tmp->name, "end"))
				return (1);
			tmp = tmp->next;
		}
		c++;
	}
	return (0);
}

t_routes		*lem_go(t_head *head, t_routes *routes)
{
	int			i;
	int			c;
	t_room		*tmp;

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
				printf("L%d-%s ", tmp->next->lem_id, tmp->next->name))
					tmp->lem_id = 0;
				else
					tmp = tmp->prev;
			if (routes->start[c]->lem_id == 0 && i <= head->count_lem &&
			(routes->start[c]->lem_id = i++))
				printf("L%d-%s ", routes->start[c]->lem_id, routes->start[c]->name);
		}
		printf("\n");
	}
	return (routes);
}

t_head		*add_queue(t_head *head, t_room *room)
{
	int		i;
	t_room	*tmp;

	i = 0;
	if (!head->q_stack && (head->q_stack = room))
		head->q_last = room;
	else head->q_last->queue = room;
	tmp = head->q_last;
	while (room->link[i] && i < 10)
	{
		if (room->link[i]->visit == 0)
		{
			tmp->queue = room->link[i];
			room->link[i]->visit = 1;
			printf("%s\n", tmp->queue->name);
			tmp = tmp->queue;
		}
		i++;
	}
	head->q_last = tmp;
	return (head);
}

t_room			*pop_queue(t_head *head, t_room *room)
{
	if (!(head->q_stack))
		return (NULL);
	if (head->q_stack == head->q_last)
		head->q_last = NULL;
	head->q_stack = room->next;
	room->next = NULL;
	return (head->q_stack);
}
