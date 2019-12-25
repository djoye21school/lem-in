/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoye <djoye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 19:54:37 by djoye             #+#    #+#             */
/*   Updated: 2019/12/25 19:38:00 by djoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_head		*count_step(t_head *head)
{
	t_room		*tmp;
	int			i;
	int			c;

	c = 0;
	while (head->routes[c])
	{
		i = 1;
		tmp = head->routes[c];
		while (tmp)
		{
			printf("%s -> ", tmp->name);
			tmp->lem_id = 0;
			tmp->level = i;
			tmp = tmp->next;
			i++;
		}
		printf("\n");
		head->step[c] = i;
		c++;
	}
	return (head);
}

int				if_free_route(t_head *head)
{
	int			c;
	t_room		*tmp;

	c = 0;
	while (head->routes[c])
	{
		tmp = head->routes[c];
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

t_head		*lem_go(t_head *head)
{
	int			i;
	int			c;
	t_room		*tmp;

	i = 1;
	while (i <= head->count_lem || if_free_route(head))
	{
		c = -1;
		while (head->routes[++c])
		{
			tmp = head->routes[c];
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
			if (head->routes[c]->lem_id == 0 && i <= head->count_lem &&
			(head->routes[c]->lem_id = i++))
				printf("L%d-%s ", head->routes[c]->lem_id, head->routes[c]->name);
		}
		printf("\n");
	}
	return (head);
}

t_room		*add_queue(t_head *head)
{
	int		i;
	t_room	*room;

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

int				check_end(t_head *head)
{
	int			i;

	i = 0;
	while (head->q_stack && head->q_stack->link[i])
	{
		if (head->q_stack->link[i] == head->end)
		{
			printf("%s\n", head->q_stack->name);
			route(head);
			head->count_route -= 1;
			return (1);
		}
		i++;
	}
	return (0);
}

t_head			*create_routes(t_head *head)
{
	int			i;

	i = 0;
	while (head->start->link[i])
		i++;
	head->count_route = i;
	head->routes = (t_room**)malloc(sizeof(t_room*) * (i + 1));
	head->step = (int*)malloc(sizeof(int));
	head->routes[i] = NULL;
	return (head);
}

t_head			*route(t_head *head)
{
	t_room		*tmp;
	t_room		*room;
	int			i;

	if (!head->routes)
		create_routes(head);
	tmp = head->q_stack;
	tmp->next = head->end;
	while (tmp && tmp->prev && tmp->prev != head->start)
	{
		room = tmp;
		tmp = tmp->prev;
		tmp->next = room;
	}
	i = 0;
	while (head->routes[i])
		i++;
	head->routes[i] = tmp;
	head->routes[i + 1] = NULL;
	return (head);
}

t_head			*algo(t_head *head)
{
	while (!check_end(head))
	{
		print_stack(head);
		printf("----------\n");
		add_queue(head);
		if (!head->q_stack)
			break ;
	}
	clear_room_attribute(head);
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
