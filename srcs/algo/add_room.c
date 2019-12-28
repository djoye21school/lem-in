/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoye <djoye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 12:04:01 by djoye             #+#    #+#             */
/*   Updated: 2019/12/28 12:39:05 by djoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room		*add_room(t_head *head, char *str)
{
	size_t	i;
	size_t	l;
	t_room	*room;
	t_room	*tmp;

	head->count_room++;
	room = (t_room*)malloc(sizeof(t_room));
	if (head->first && (tmp = head->first))
	{
		while (tmp->follow)
			tmp = tmp->follow;
		tmp->follow = room;
	}
		else head->first = room;
	room->follow = NULL;
	room->link = NULL;
	room->queue = NULL;
	room->visit = 0;
	i = find_chr(str, 0, ' ');
	if ((l = find_chr(str, i + 1, ' ')) <= i + 1 || ft_strlen(str) <= l + 1)
		exit(write(2, "ERROR room param\n", 17) - 17);
	room_param(room, ft_strsub(str, 0, i), ft_strsub(str, i + 1, (l - i - 1)),
	ft_strsub(str, l + 1, ft_strlen(str) - l - 1));
	check_replay(head, room->name, room->x, room->y);
	return (room);
}

t_room		*room_param(t_room *room, char *str, char *x, char *y)
{
	if (str[0] == 'L' || find_chr(str, 0, '-') < (int)ft_strlen(str) ||
	!ft_str_is_numeric(x) || !ft_str_is_numeric(y))
		exit(write(2, "ERROR room param\n", 17) - 17);
	room->name = str;
	room->x = max_int(x);
	room->y = max_int(y);
	free(x);
	free(y);
	return (room);
}

t_room		*find_room(t_head *head, char *buf)
{
	t_room	*tmp;

	tmp = head->first;
	while (tmp && !ft_strequ(tmp->name, buf))
		tmp = tmp->follow;
	if (!tmp || !ft_strequ(tmp->name, buf))
		exit(write(2, "ERROR: room not found\n", 22) - 22);
	free(buf);
	return (tmp);
}

t_room		*connect(t_head *head, t_room *first, t_room *second)
{
	t_room	**tmp;
	int		i;

	if (!first->link)
	{
		first->link = (t_room**)malloc(sizeof(t_room*) * head->count_room);
		first->link[0] = NULL;
	}
	tmp = first->link;
	i = 0;
	while (tmp[i])
	{
		if (tmp[i] == second)
			exit(write(2, "ERROR: bad room link\n", 21) - 21);
		i++;
	}
	tmp[i] = second;
	tmp[i + 1] = NULL;
	return (first);
}

t_head		*add_connect(t_head *head, char *str)
{
	int		i;
	t_room	*first;
	t_room	*second;

	i = find_chr(str, 0, '-');
	first = find_room(head, ft_strsub(str, 0, i));
	second = find_room(head, ft_strsub(str, i + 1, ft_strlen(str)));
	connect(head, first, second);
	connect(head, second, first);
	return (head);
}
