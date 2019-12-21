/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoye <djoye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 13:51:54 by djoye             #+#    #+#             */
/*   Updated: 2019/12/21 18:47:34 by djoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_head			*read_file(t_head *head, int fd)
{
	char		buf[BUFF_SIZE + 1];
	int			len;
	char		*tmp;

	while ((len = read(fd, buf, BUFF_SIZE)))
	{
		buf[len] = '\0';
		if (!head->instruction)
			head->instruction = ft_strnew(1);
		tmp = head->instruction;
		head->instruction = ft_strjoin(tmp, buf);
		free(tmp);
	}
	return (head);
}

t_head			*add_data(t_head *head)
{
	int			i;

	i = -1;
	while (head->split[++i])
	{
		if (i == 0)
			head->count_lem = ft_atoi(head->split[i]);
		else if (ft_strequ("##start", head->split[i]))
			head->start = add_room(head, head->split[++i], 0);
		else if (ft_strequ("##end", head->split[i]))
			head->end = add_room(head, head->split[++i], 1);
		else if (head->split[i][0] == '#')
			continue ;
		else if (head->split[i][find_chr(head->split[i], 0, ' ')] == ' ')
			add_room(head, head->split[i], -1);
		else if (head->split[i][find_chr(head->split[i], 0, '-')] == '-')
			add_connect(head, head->split[i]);
		else
			exit(write(1, "error\n", 6) - 6);
	}
	return (head);
}

t_room			*room_param(t_head *head, t_room *room, char *str, char *x, char *y)
{

	if (str[0] == 'L' || !ft_str_is_numeric(x) || !ft_str_is_numeric(y))
		exit(write(1, "error\n", 6) - 6);
	room->name = str;
	room->x = ft_atoi(x);
	room->y = ft_atoi(y);
	free(x);
	free(y);
	check_replay(head, room->name, room->x, room->y);
	return (room);
}

t_room			*add_room(t_head *head, char *str, int flag)
{
	int			i;
	static int	id;
	int			l;
	t_room		*room;

	if (!head->first)
	{
		room = (t_room*)malloc(sizeof(t_room));
		head->first = room;
	}
	else
	{
		room = head->first;
		while (room->next)
			room = room->next;
		room->next = (t_room*)malloc(sizeof(t_room));
		room = room->next;
	}
	room->next = NULL;
	room->link = NULL;
	i = find_chr(str, 0, ' ');
	l = find_chr(str, i + 1, ' ');
	room_param(head, room, ft_strsub(str, 0, i), ft_strsub(str, i + 1, (l - i - 1)),
	ft_strsub(str, l + 1, ft_strlen(str) - l - 1));
	room->id = (flag != 0 && flag != 1) ? ++id : flag;
	if (head->end)
		head->end->id = id + 1;
	head->count_room = id + 2;
	//printf("id:%d | name: %s | x = %d | y = %d\n", room->id, room->name, room->x, room->y);
	return (room);
}

t_room			*find_room(t_head *head, char *buf)
{
	t_room		*room;

	room = head->first;
	while (room && !ft_strequ(room->name, buf))
		room = room->next;
	if (!ft_strequ(room->name, buf))
		exit(write(1, "error\n", 6) - 6);
	free(buf);
	return (room);
}

t_room			*connect(t_head *head, t_room *first, t_room *second)
{
	t_room		**tmp;
	int			i;

	if (!first->link)
	{
		first->link = (t_room**)malloc(sizeof(t_room*) * head->count_room);
		first->link[0] = NULL;
	}
	tmp = first->link;
	i = 0;
	while (tmp[i])
		i++;
	tmp[i] = second;
	tmp[i + 1] = NULL;
	return (first);
}

t_head			*add_connect(t_head *head, char *str)
{
	int			id;
	int			i;
	t_room		*first;
	t_room		*second;

	if (!head->matrix)
		map(head);
	i = find_chr(str, 0, '-');
	first = find_room(head, ft_strsub(str, 0, i));
	second = find_room(head, ft_strsub(str, i + 1, ft_strlen(str)));
	connect(head, first, second);
	connect(head, second, first);
	head->matrix[first->id][second->id] = min_val(head, first->id, second->id) + 1;
	head->matrix[second->id][first->id] = min_val(head, second->id, first->id) + 1;
	//printf("%s->%s\n", first, second);
	return (head);
}

int				find_chr(char *str, int i, char c)
{
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

int				check_replay(t_head *head, char *str, int x, int y)
{
	t_room		*tmp;
	int			c;

	c = 0;
	tmp = head->first;
	while (tmp && tmp->next)
	{
		if (ft_strequ(tmp->name, str) || (tmp->x == x && tmp->y == y))
			c++;
		if (c > 1 || head->count_lem <= 0)
			exit(write(1, "error\n", 6) - 5);
		tmp = tmp->next;
	}
	return (0);
}
