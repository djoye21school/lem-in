/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoye <djoye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 12:59:53 by djoye             #+#    #+#             */
/*   Updated: 2019/12/21 18:46:17 by djoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				main(int ac, char **av)
{
	int			fd;
	t_head		*head;
	int			i;
	t_routes	*routes;
	t_route		*tmp;
	t_room		*temp;
	t_stack		*tmp_s;
	int			l;
	char		*str;

	if (ac != 2 || (fd = open(av[1], O_RDONLY)) < 0 || read(fd, NULL, 0) == -1)
		if (!(ac == 1 && fd == 0))
			exit(write(1, "usage: not valid file\n", 21) - 21);
	head = (t_head*)malloc(sizeof(t_head));
	head->instruction = NULL;
	head->first = NULL;
	head->start = NULL;
	head->end = NULL;
	head->matrix = NULL;
	head->queue = NULL;
	read_file(head, fd);
	head->split = ft_strsplit(head->instruction, '\n');
	head->routes = (t_routes*)malloc(sizeof(t_routes));
	add_data(head);
	add_queue(head, head->first);
	print_stack(head);
	pop_queue(head, head->queue->room);
	printf("\n");
	add_queue(head, head->queue->room);
	pop_queue(head, head->queue->room);
	pop_queue(head, head->queue->room);
	pop_queue(head, head->queue->room);
	pop_queue(head, head->queue->room);
	//pop_queue(head, head->queue->room);
	print_stack(head);
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
	

	

	//recurse(head, 0, 0, 0, 1);
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

void		print_stack(t_head *head)
{
	t_stack *tmp;

	tmp = head->queue;
	while (tmp)
	{
		printf("%s\n", tmp->room->name);
		tmp = tmp->next;
	}
}