/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoye <djoye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 12:59:53 by djoye             #+#    #+#             */
/*   Updated: 2019/11/28 18:57:12 by djoye            ###   ########.fr       */
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
	while(str[i] && str[i] != ' ')
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
	room->x = ft_atoi(ft_strsub(str, i, l));
	i = l;
	l = find_chr(str, i + 1, ' ');
	room->y = ft_atoi(ft_strsub(str, i, l));
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
	i = -1;
	while (++i < head->count_room - 1)
	{
		if (ft_strequ("##start", head->split[i]))
			add_room(head, room, head->split[i + 1]);
	}
		//printf("%s\n", head->split[i]);
	//printf("%s\n", head->split[0]);
	if (ft_strequ("##start", head->split[i]))
		add_room(head, room, head->split[i + 1]);
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