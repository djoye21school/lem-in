/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoye <djoye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 12:59:53 by djoye             #+#    #+#             */
/*   Updated: 2019/11/29 12:55:12 by djoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

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


t_room		*add_room(t_head *head, t_room *room, char *str)
{
	int			i;
	static int	id;
	int			l;

	i = find_chr(str, 0, ' ');
	room->name = ft_strsub(str, 0, i);
	room->id = ++id;
	l = find_chr(str, i + 1, ' ');
	room->x = ft_atoi(ft_strsub(str, i + 1, l));
	room->y = ft_atoi(ft_strsub(str, l + 1, ft_strlen(str)));
	printf("%s\n%d\n%d\n", room->name, room->x, room->y);
	return (room);
}

t_room		*add_connect(t_head *head, t_room *room, char *str)
{
	int			i;
	static int	id;
	int			l;
	t_room		*tmp;
	char		*first;
	char		*second;

	printf("connect");
	i = find_chr(str, 0, '-');
	first = ft_strsub(str, 0, i);
	tmp = room;
	while(tmp && tmp->name != first)
		tmp = tmp->next;
	if (tmp->name == first)
		id = tmp->id;
	second = ft_strsub(str, i + 1, ft_strlen(str));
	tmp = room;
	while(tmp && tmp->name != second)
		tmp = tmp->next;
	head->matrix[id][tmp->id] = 1;
	head->matrix[tmp->id][id] = 1;
	printf("%s\n%d\n%d\n", room->name, room->x, room->y);
	return (room);
}

int			main(int ac, char **av)
{
	int		fd;
	t_head	*head;
	int		i;
	t_room	*room;

	if (ac != 2 || (fd = open(av[1], O_RDONLY)) < 0 || read(fd, NULL, 0) == -1)
		return (write(1, "usage: not valid file\n", 21) - 21);
	head = (t_head*)malloc(sizeof(t_head));
	head->instruction = NULL;
	read_file(head, fd);
	add_head(head);
	map (head);
	room = (t_room*)malloc(sizeof(t_room));
	head->split = ft_strsplit(head->instruction, '\n');
	head->count_lem = ft_atoi(head->split[0]);
	printf("%dlemm\n", head->count_lem);
	i = -1;
	while (++i < head->count_room - 1)
	{
		printf("%s\n", head->split[i]);
		if (ft_strequ("##start", head->split[i]))
			add_room(head, room, head->split[i + 1]);
		else if (head->split[i][find_chr(head->split[i], 0, '-')] == '-')
		{
			
			add_connect(head, room, head->split[i]);
		}
	}
	i = 0;
	while (head->matrix[i] != 0)
	{
		printf("%s\n", head->matrix[i]);
		i++;
	}

		//printf("%s\n", head->split[i]);
	//printf("%s\n", head->split[0]);
	return (close(fd));
}

t_head		*add_head(t_head *head)
{
	int		i;

	head->count_room = 0;
	i = -1;
	while (head->instruction[++i])
		if (head->instruction[i] == '\n')
			head->count_room++;
	//printf("%d\n", head->count_room);
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
	//room->id = ;
	//room->name = ft_strncpy() //  send position "-""
	//room->name = ft_strncpy()