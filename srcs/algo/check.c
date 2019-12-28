/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoye <djoye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 11:57:40 by djoye             #+#    #+#             */
/*   Updated: 2019/12/28 14:57:29 by djoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			check_instruction(char *str)
{
	int		i;

	i = 0;
	if (!(str[i]))
		exit(write(2, "ERROR instruction\n", 18) - 18);
	while (str[i])
		if ((i && str[i] == '\n' && str[i - 1] == '\n'))
			exit(write(2, "ERROR instruction\n", 18) - 18);
		else
			i++;
	return (i);
}

int			check_replay(t_head *head, char *str, int x, int y)
{
	t_room	*tmp;
	int		c;

	c = 0;
	tmp = head->first;
	while (tmp && tmp->follow)
	{
		if (ft_strequ(tmp->name, str))
			exit(write(2, "ERROR: duplicate room\n", 22) - 22);
		if (tmp->x == x && tmp->y == y)
			exit(write(2, "ERROR: duplicate coord\n", 23) - 23);
		tmp = tmp->follow;
	}
	return (0);
}

int			check_end(t_head *head)
{
	int		i;

	i = 0;
	while (head->q_stack && head->q_stack->link[i])
	{
		if (head->q_stack->link[i] == head->end)
		{
			route(head);
			return (1);
		}
		i++;
	}
	return (0);
}

int			check_start_end(t_head *head)
{
	int		i;
	int		lem;

	i = 0;
	if (!head->start || !head->start->link)
		exit(write(2, "ERROR: not valid route\n", 23) - 23);
	while (head->start->link[i])
	{
		if (head->start->link[i] == head->end)
		{
			lem = 0;
			while (++lem <= head->count_lem)
			{
				lem == 1 ? write(1, "L", 1) : write(1, " L", 2);
				ft_putnbr(lem);
				write(1, "-end", 4);
			}
			write(1, "\n", 1);
			exit(0);
		}
		i++;
	}
	return (0);
}

int			if_free_route(t_head *head)
{
	int		c;
	t_room	*tmp;

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
