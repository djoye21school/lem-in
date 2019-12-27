/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoye <djoye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 19:54:37 by djoye             #+#    #+#             */
/*   Updated: 2019/12/27 16:11:17 by djoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room			*add_queue(t_head *head)
{
	int			i;
	t_room		*room;

	if (!head->q_stack && head->start->visit == 0)
	{
		head->q_stack = head->start;
		head->q_last = head->start;
		head->start->visit = 1;
		head->q_stack->level = 0;
		return (head->q_stack);
	}
	i = -1;
	room = head->q_stack;
	while (head->q_stack && head->q_stack->link[++i])
	{
		if (head->q_stack->link[i]->visit == 0)
		{
			head->q_last->queue = head->q_stack->link[i];
			head->q_last->queue->level = room->level + 1;
			head->q_stack->link[i]->visit = 1;
			head->q_stack->link[i]->prev = room;
			head->q_last = head->q_last->queue;
		}
	}
	return (pop_queue(head));
}

t_room			*pop_queue(t_head *head)
{
	t_room		*tmp;

	if (!(head->q_stack))
		return (NULL);
	tmp = head->q_stack;
	if (tmp == head->q_last)
		head->q_last = NULL;
	head->q_stack = tmp->queue;
	tmp->queue = NULL;
	return (tmp);
}

t_head			*create_routes(t_head *head)
{
	int			i;

	i = 0;
	while (head->start->link[i])
		i++;
	head->count_route = i;
	head->routes = (t_room**)malloc(sizeof(t_room*) * (i + 1));
	head->last_ant = (t_room**)malloc(sizeof(t_room*) * (i + 1));
	head->step = (int*)malloc(sizeof(int) * (i + 1));
	while (i >= 0)
	{
		head->routes[i] = NULL;
		head->last_ant[i] = NULL;
		head->step[i] = 0;
		i--;
	}
	return (head);
}

t_head			*route(t_head *head)
{
	t_room		*tmp;
	t_room		*room;
	int			i;
	int			step;

	tmp = head->q_stack;
	tmp->next = head->end;
	step = 2;
	while (tmp && tmp->prev && tmp->prev != head->start)
	{
		room = tmp;
		tmp = tmp->prev;
		tmp->next = room;
		step++;
	}
	i = 0;
	while (head->routes[i])
		i++;
	head->routes[i] = tmp;
	head->step[i] = step;
	head->routes[i + 1] = NULL;
	return (head);
}

t_head			*clear_room_attribute(t_head *head)
{
	t_room		*room;

	head->q_stack = NULL;
	head->q_last = NULL;
	room = head->first;
	while (room)
	{
		if (room != head->end && !room->next)
		{
			room->level = 0;
			room->visit = 0;
			room->prev = NULL;
			room->queue = NULL;
		}
		room = room->follow;
	}
	return (head);
}
