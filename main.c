/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoye <djoye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 12:59:53 by djoye             #+#    #+#             */
/*   Updated: 2019/12/06 18:02:05 by djoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_head		*read_file(t_head *head, int fd)
{
	char	buf[BUFF_SIZE + 1];
	int		len;
	char	*tmp;

	while((len = read(fd, buf, BUFF_SIZE)))
	{
		buf[len] = '\0';
		if (!head->instruction)
		{
			head->instruction = (char*)malloc(sizeof(char) + 1);
			head->instruction[0] = '\0';
		}
		tmp = head->instruction;
		head->instruction = ft_strjoin(tmp, buf);
		free (tmp);
	}
	return (head);
}

int			find_chr(char *str, int i, char c)
{
	while(str[i] && str[i] != c)
		i++;
	return (i);
}

t_room		*add_room(t_head *head, char *str, int flag)
{
	int			i;
	static int	id = 0;
	int			l;
	t_room		*room;

	if (!head->first && (room = (t_room*)malloc(sizeof(t_room))))
		head->first = room;
	else
	{
		room->next = (t_room*)malloc(sizeof(t_room));
		room = room->next;
	}
	i = find_chr(str, 0, ' ');
	room->name = ft_strsub(str, 0, i);
	room->id = (flag != 0 && flag != 1) ? ++id : flag;
	l = find_chr(str, i + 1, ' ');
	room->x = ft_atoi(ft_strsub(str, i + 1, l));
	room->y = ft_atoi(ft_strsub(str, l + 1, ft_strlen(str)));
	room->next = NULL;
	if (head->end && head->end->id)
		head->end->id = id + 1;
	head->count_room = id + 2;
	//printf("id:%d | name: %s | x = %d | y = %d\n", room->id, room->name, room->x, room->y);
	return (room);
}

t_head		*add_connect(t_head *head, char *str)
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
	while(tmp && !ft_strequ(tmp->name , first))
		tmp = tmp->next;
	if (!ft_strequ(tmp->name , first))
		exit (write(1, "error\n", 6) - 6);
	id = tmp->id;
	second = ft_strsub(str, i + 1, ft_strlen(str));
	tmp = head->first;
	while(tmp && !ft_strequ(tmp->name , second))
		tmp = tmp->next;
	if (!ft_strequ(tmp->name , second))
		exit (write(1, "error\n", 6) - 6);
	printf("connect: %d | %d\n", id, tmp->id);
	head->matrix[id][tmp->id] = '1';
	head->matrix[tmp->id][id] = '1';
	printf("%s->%s\n", first, second);
	return (head);
}

int			main(int ac, char **av)
{
	int		fd;
	t_head	*head;
	int		i;
	t_routes *routes;

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
	
	/*
	while (head->first)
	{
		printf("%s\n", head->first->name);
		head->first = head->first->next;
	}*/


	i = 0;
	printf("  s01234e\n");
	while (head->matrix[i] != 0)
	{
		printf("%d|%s\n", i == 0 ? 0 : i - 1, head->matrix[i]);
		i++;
	}
	i = 0;
	routes = route_line(head);
	t_route *tmp;
	while(routes->start[i])
	{	
		tmp = routes->start[i];
		//printf("%s\n", routes->start[i]->room->name);
		printf("%s", tmp->prev->room->name);
		while(tmp)
		{
			printf("->%s", tmp->room->name);
		//	printf("\n%s\n", tmp->prev->room->name);
			tmp = tmp->next;
		}
		printf("\n");
		i++;
	}
	count_step(routes);
	lem_go(head, routes);
	return (close(fd));
}

t_head		*add_data(t_head *head)
{
	int		i;

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
		else if (head->split[i][find_chr(head->split[i], 0, '#')] == '#')
			continue ;
		else
			add_room(head, head->split[i], -1);
	}
	return (head);
}

t_head		*map(t_head *head)
{
	int		l;
	int		c;

	head->matrix = (char**)malloc(sizeof(char*) * (head->count_room + 1));
	l = -1;
	while (++l < head->count_room)
	{
		c = -1;
		head->matrix[l] = (char*)malloc(sizeof(char) * (head->count_room + 1));
		while(++c < head->count_room)
			head->matrix[l][c] = '0';
		head->matrix[l][c] = '\0';
	}
	head->matrix[l] = 0;
	return (head);
}
