/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoye <djoye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 13:51:54 by djoye             #+#    #+#             */
/*   Updated: 2019/12/25 18:37:07 by djoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_head		*read_file(t_head *head, int fd)
{
	char	buf[BUFF_SIZE + 1];
	int		len;
	char	*tmp;

	head->instruction = NULL;
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

int		skip(char **str, int *i)
{
	while (str[*i][0] == '#')
		(*i)++;
	return (1);
}

int		count_lem(char *str)
{
	double	nb;
	int		i;

	i = 0;
	nb = 0;
	while (str[i])
		nb = nb * 10 + str[i++] - '0';
	if (!ft_str_is_numeric(str) || nb != (double)ft_atoi(str))
		exit(write(1, "error: no valid ants\n", 21) - 21);
	return ((int)nb);
}

int			check_instruction(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		if ((i && str[i] == '\n' && str[i - 1] == '\n') ||
			(str[i] == '\n' && str[i + 1] == '\0'))
			exit(write(1, "error instruction\n", 18) - 18);
		else
			i++;
	return (i);
}

t_head		*add_data(t_head *head)
{
	int		i;

	i = -1;
	while (head->split[++i])
	{
		printf("%s | %d\n", head->split[i], i);
		if (i == 0 && skip(head->split, &i))
			head->count_lem = count_lem(head->split[i]);
		else if (ft_strequ("##start", head->split[i]) && skip(head->split, &i))
			head->start = add_room(head, head->split[i]);
		else if (ft_strequ("##end", head->split[i]) && skip(head->split, &i))
			head->end = add_room(head, head->split[i]);
		else if (head->split[i][0] == '#')
			skip(head->split, &i);
		else if (head->split[i][find_chr(head->split[i], 0, ' ')] == ' ')
			add_room(head, head->split[i]);
		else if (head->split[i][find_chr(head->split[i], 0, '-')] == '-')
			add_connect(head, head->split[i]);
		else
			exit(write(1, "error_read\n", 10) - 10);
	}
	return (head);
}

int			find_chr(char *str, int i, char c)
{
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

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
		exit(write(1, "error room param\n", 16) - 16);
	room_param(room, ft_strsub(str, 0, i), ft_strsub(str, i + 1, (l - i - 1)),
	ft_strsub(str, l + 1, ft_strlen(str) - l - 1));
	check_replay(head, room->name, room->x, room->y);
	return (room);
}

t_room		*room_param(t_room *room, char *str, char *x, char *y)
{
	if (str[0] == 'L' || !ft_str_is_numeric(x) || !ft_str_is_numeric(y))
		exit(write(1, "error room param\n", 16) - 16);
	room->name = str;
	room->x = ft_atoi(x);
	room->y = ft_atoi(y);
	free(x);
	free(y);
	return (room);
}

int			check_replay(t_head *head, char *str, int x, int y)
{
	t_room	*tmp;
	int		c;

	c = 0;
	tmp = head->first;
	while (tmp && tmp->follow)
	{
		if (ft_strequ(tmp->name, str) || (tmp->x == x && tmp->y == y))
			exit(write(1, "error: duplicate room\n", 21) - 21);
		tmp = tmp->follow;
	}
	return (0);
}

t_room		*find_room(t_head *head, char *buf)
{
	t_room	*tmp;

	tmp = head->first;
	while (tmp && !ft_strequ(tmp->name, buf))
		tmp = tmp->follow;
	if (!tmp || !ft_strequ(tmp->name, buf))
		exit(write(1, "error: room not found\n", 22) - 22);
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
			exit(write(1, "error: bad room link\n", 21) - 21);
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
