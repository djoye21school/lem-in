/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_go.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoye <djoye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 15:54:35 by djoye             #+#    #+#             */
/*   Updated: 2019/12/28 15:53:03 by djoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

t_head			*lem_go(t_head *head)
{
	int			i;
	int			c;
	int			flag;

	i = 1;
	c = 0;
	flag = 0;
	while (head->routes[c])
	{
		flag = go_to(head, c, flag);
		if (i <= head->count_lem && head->routes[c]->lem_id == 0 &&
		(c == 0 || (c && head->count_lem - i >= use_route(head, c))))
		{
			head->routes[c]->lem_id = i++;
			if (!head->last_ant[c])
				head->last_ant[c] = head->routes[c];
			print_lem(head->routes[c]->lem_id, head->routes[c]->name, flag);
			flag = 1;
		}
		if (!head->routes[++c])
			c = 0;
		flag = (c == 0) ? 0 : flag;
		(c == 0) ? write(1, "\n", 1) : 0;
	}
	return (head);
}

int				go_to(t_head *head, int c, int flag)
{
	t_room		*tmp;
	static int	lem_finish;

	tmp = head->last_ant[c];
	while (tmp && tmp->next && tmp->prev && tmp->lem_id != 0)
	{
		if (tmp->next != head->end && head->last_ant[c] == tmp)
			head->last_ant[c] = tmp->next;
		if (tmp->next == head->end)
			lem_finish++;
		tmp->next->lem_id = tmp->lem_id;
		tmp->lem_id = 0;
		flag = print_lem(tmp->next->lem_id, tmp->next->name, flag);
		if (lem_finish == head->count_lem)
			exit(write(1, "\n", 1));
		head->end->lem_id = 0;
		tmp = tmp->prev;
	}
	return (flag);
}

int				use_route(t_head *head, int c)
{
	int			i;

	i = 0;
	i = head->step[c] * c;
	while (--c >= 0)
		i -= head->step[c];
	return (i);
}

int				print_lem(int nb, char *str, int flag)
{
	flag == 0 ? write(1, "L", 1) : write(1, " L", 2);
	ft_putnbr(nb);
	write(1, "-", 1);
	ft_putstr(str);
	return (1);
}
