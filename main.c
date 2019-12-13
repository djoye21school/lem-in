/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoye <djoye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 12:59:53 by djoye             #+#    #+#             */
/*   Updated: 2019/12/13 19:53:43 by djoye            ###   ########.fr       */
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
	char		*tmp;

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
	if (ft_str_is_numeric(tmp = ft_strsub(str, i + 1, (l - i - 1)))
		|| (tmp[0] == '-' && ft_str_is_numeric(tmp + 1)))
	{
		room->x = ft_atoi(tmp);
		free(tmp);
	}
		else exit(write(1, "error\n", 6) - 6);
	if (ft_str_is_numeric(tmp = ft_strsub(str, l + 1, ft_strlen(str) - l - 1))
	|| (tmp[0] == '-' && ft_str_is_numeric(tmp + 1)))
	{
		room->y = ft_atoi(tmp);
		free (tmp);
	}
			else exit(write(1, "error\n", 6) - 6);
	check_replay(head, room->name, room->x, room->y);
	if (head->end && head->end->id)
		head->end->id = id + 1;
	head->count_room = id + 2;
	//printf("id:%d | name: %s | x = %d | y = %d\n", room->id, room->name, room->x, room->y);
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
	//printf("connect: %d | %d\n", id, tmp->id);
	free (first);
	free (second);
	head->matrix[id][tmp->id] = min_val(head, id, tmp->id) + 1;
	head->matrix[tmp->id][id] = min_val(head, tmp->id, id) + 1;
	//printf("%s->%s\n", first, second);
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
	char		*str;

	if (ac != 2 || (fd = open(av[1], O_RDONLY)) < 0 || read(fd, NULL, 0) == -1)
		if (!(ac == 1 && fd == 0))
			exit(write(1, "usage: not valid file\n", 21) - 21);
	head = (t_head*)malloc(sizeof(t_head));
	head->instruction = NULL;
	read_file(head, fd);
	head->first = NULL;
	head->start = NULL;
	head->end = NULL;
	head->matrix = NULL;
	head->split = ft_strsplit(head->instruction, '\n');
	head->routes = (t_routes*)malloc(sizeof(t_routes));

	add_data(head);
	temp = head->first;
	str = (char*)malloc(sizeof(char) * head->count_room);
	
	i = 0;

	while (temp)
	{
		if (!ft_strequ("end", temp->name))
			str[i++] = temp->name[0];
		temp = temp->next;
	}
	str[i++] = 'e';
	str[i] = '\0';
	printf("  %s\n", str);
	
	l = 0;
	temp = head->first;
	while (l < head->count_room)
	{
		printf("%c|", str[l]);
		i = -1;
		while (++i < head->count_room)
			printf("%d", head->matrix[l][i]);
		printf("\n");
		l++;
	}
	recurse(head, 0, 0, 0, 1);
/*

	while (upd_map(head))
		printf("\n");
	
		printf("\n");
		printf("  %s\n", str);
		temp = head->first;
		l = 0;
		while (l < head->count_room)
		{
			printf("%c|", str[l]);
			i = -1;
			while (++i < head->count_room)
				printf("%d", head->matrix[l][i]);
			printf("\n");
			l++;
		}
	*/
	exit (0);
	routes = route_line(head);
	
	i = 0;
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
		//printf("%s\n", head->split[i]);
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

t_head			*map(t_head *head)
{
	int			l;
	int			c;

	head->matrix = (int**)malloc(sizeof(int*) * head->count_room);
	l = -1;
	while (++l < head->count_room)
	{
		c = -1;
		head->matrix[l] = (int*)malloc(sizeof(int) * head->count_room);
		while (++c < head->count_room)
			head->matrix[l][c] = 0;
	}
	return (head);
}



int				recurse(t_head *head, int l, int c, int i, int flag)
{
	t_route		*tmp;
	t_room		*room;
	int			id;

	while (l < head->count_room && c < head->count_room)
	{
			if ((l == head->count_room - 1 || c == head->count_room - 1) && head->matrix[l][c] > 0)
			{
				i++;
				return (1);
			}
			if (recurse(head, flag == 1 ? ++l : l, flag == 0 ? ++c : c, i, flag))
			{
				if (!head->routes->start[i])
					head->routes->start[i] = (t_route*)malloc(sizeof(t_route));
				tmp = head->routes->start[i];
				while (tmp)
					tmp = tmp->next;
			id = flag == 1 ? l : c; 
			room = head->first;
				while (room)
					if (room->id == id)
						break ;
				tmp->room = room;
				tmp->next = NULL;			
				if (flag == 1 && (i = -1))
					flag = 0;
				else if ((l = -1))
					flag = 1;				
				return (1);
			}
			flag == 1 ? l++ : i++;
	}
	return (0);
}
