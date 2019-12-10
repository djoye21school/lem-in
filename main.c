/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoye <djoye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 12:59:53 by djoye             #+#    #+#             */
/*   Updated: 2019/12/10 20:32:33 by djoye            ###   ########.fr       */
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
		{
			head->instruction = (char*)malloc(sizeof(char) + 1);
			head->instruction[0] = '\0';
		}
		tmp = head->instruction;
		head->instruction = ft_strjoin(tmp, buf);
		free(tmp);
	}
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

t_room			*add_room(t_head *head, char *str, int flag)
{
	int			i;
	static int	id = 0;
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
	i = find_chr(str, 0, ' ');
	room->name = ft_strsub(str, 0, i);
	room->id = (flag != 0 && flag != 1) ? ++id : flag;
	l = find_chr(str, i + 1, ' ');
	room->x = ft_atoi(ft_strsub(str, i + 1, l));
	room->y = ft_atoi(ft_strsub(str, l + 1, ft_strlen(str)));
	check_replay(head, room->name, room->x, room->y);
	if (head->end && head->end->id)
		head->end->id = id + 1;
	head->count_room = id + 2;
	printf("id:%d | name: %s | x = %d | y = %d\n", room->id, room->name, room->x, room->y);
	return (room);
}

t_head			*add_connect(t_head *head, char *str)
{
	int			i;
	int			id;
	t_room		*tmp;
	char		*first;
	char		*second;

	if (!head->matrix)
		map(head);
	i = find_chr(str, 0, '-');
	first = ft_strsub(str, 0, i);
	tmp = head->first;
	while (tmp && !ft_strequ(tmp->name, first))
		tmp = tmp->next;
	if (!ft_strequ(tmp->name, first))
		exit(write(1, "error\n", 6) - 6);
	id = tmp->id;
	second = ft_strsub(str, i + 1, ft_strlen(str));
	tmp = head->first;
	while (tmp && !ft_strequ(tmp->name, second))
		tmp = tmp->next;
	if (!ft_strequ(tmp->name, second))
		exit(write(1, "error\n", 6) - 6);
	printf("connect: %d | %d\n", id, tmp->id);
	head->matrix[id][tmp->id] = head->count_room;
	head->matrix[tmp->id][id] = head->count_room;
	printf("%s->%s\n", first, second);
	return (head);
}

int				main(int ac, char **av)
{
	int			fd;
	t_head		*head;
	int			i;
	t_routes	*routes;
	t_route		*tmp;
	t_room		*temp;
	int			l;

	if (ac != 2 || (fd = open(av[1], O_RDONLY)) < 0 || read(fd, NULL, 0) == -1)
		return (write(1, "usage: not valid file\n", 21) - 21);
	head = (t_head*)malloc(sizeof(t_head));
	head->instruction = NULL;
	read_file(head, fd);
	head->first = NULL;
	head->start = NULL;
	head->end = NULL;
	head->matrix = NULL;
	head->split = ft_strsplit(head->instruction, '\n');
	add_data(head);
	printf("  ");
	temp = head->first;
	while (temp)
	{
		if (!ft_strequ("end", temp->name))
			printf("%c", temp->name[0]);
		temp = temp->next;
	}
	printf("e\n");
	l = 0;
	temp = head->first;
	while (l < head->count_room)
	{
		if (!ft_strequ("end", temp->name))
			printf("%c|", temp->name[0] - 1);
		else
			printf("e|");
		temp = temp->next;
		i = 0;
		while (i < head->count_room)
		{
			printf("%d", head->matrix[l][i]);
			i++;
		}
		printf("\n");
		l++;
	}
	
	printf("\n");
	printf("  ");
	temp = head->first;
	while (temp)
	{
		if (!ft_strequ("end", temp->name))
			printf("%c", temp->name[0]);
		temp = temp->next;
	}
	printf("e\n");
	upd_map(head);
	temp = head->first;
	l = 0;
	while (l < head->count_room)
	{
		if (!ft_strequ("end", temp->name))
			printf("%c|", temp->name[0] - 1);
		else
			printf("e|");
		temp = temp->next;
		i = 0;
		while (i < head->count_room)
		{
			printf("%d", head->matrix[l][i]);
			i++;
		}
		printf("\n");
		l++;
	}

	i = 0;
	routes = route_line(head);
	while (routes->start[i])
	{
		tmp = routes->start[i];
		printf("%s", tmp->prev->room->name);
		while (tmp)
		{
			printf("->%s", tmp->room->name);
			tmp = tmp->next;
		}
		printf("\n");
		i++;
	}
	count_step(routes);
	lem_go(head, routes);
	exit(close(fd));
}

t_head			*add_data(t_head *head)
{
	int			i;

	i = -1;
	while (head->split[++i])
	{
		printf("%s\n", head->split[i]);
		if (i == 0)
			head->count_lem = ft_atoi(head->split[i]);
		else if (ft_strequ("##start", head->split[i]))
			head->start = add_room(head, head->split[++i], 0);
		else if (ft_strequ("##end", head->split[i]))
			head->end = add_room(head, head->split[++i], 1);
		else if (head->split[i][find_chr(head->split[i], 0, '-')] == '-')
			add_connect(head, head->split[i]);
		else if (head->split[i][find_chr(head->split[i], 0, ' ')] == ' ')
			add_room(head, head->split[i], -1);
		else if (head->split[i][0] == '#')
			continue ;
		else
			exit(write(1, "error\n", 6) - 6);
	}
	return (head);
}

t_head			*map(t_head *head)
{
	int			l;
	int			c;

	head->matrix = (int**)malloc(sizeof(int*) * (head->count_room + 1));
	l = -1;
	while (++l < head->count_room)
	{
		c = -1;
		head->matrix[l] = (int*)malloc(sizeof(int) * (head->count_room + 1));
		while (++c < head->count_room)
		{
			head->matrix[l][c] = 0;
		}
	}
	return (head);
}
