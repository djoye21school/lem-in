/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoye <djoye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 19:54:37 by djoye             #+#    #+#             */
/*   Updated: 2019/12/21 18:02:10 by djoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
		//printf("%d | %s | %d\n", c, routes->start[c]->room->name, i);
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

t_head		*add_queue(t_head *head, t_room *room)
{
	t_room		**tmp;
	int			i;
	t_stack		*tmp_s;

	tmp = room->link;
	i = 0;
	while (tmp[i])
	{
		tmp_s = (t_stack*)malloc(sizeof(t_stack*));
		tmp_s->room = tmp[i];
		tmp_s->next = NULL;
		if (!head->queue)
			head->queue = tmp_s;
		else head->q_last->next = tmp_s;
		head->q_last = tmp_s;
		i++;
	}
	return (head);
}

t_room			*pop_queue(t_head *head, t_room *room)
{
	t_stack		*tmp;

	tmp = head->queue;
	if (!tmp)
		return (NULL);
	if (head->queue == head->q_last)
		head->q_last = NULL;
	head->queue = head->queue->next;
	return (tmp->room);
}
