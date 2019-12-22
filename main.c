/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoye <djoye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 12:59:53 by djoye             #+#    #+#             */
/*   Updated: 2019/12/22 19:42:44 by djoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				main(int ac, char **av)
{
	int			fd;
	t_head		*head;
	t_routes	*routes;

	if (ac != 2 || (fd = open(av[1], O_RDONLY)) < 0 || read(fd, NULL, 0) == -1)
		if (!(ac == 1 && fd == 0))
			exit(write(1, "usage: not valid file\n", 21) - 21);
	head = (t_head*)malloc(sizeof(t_head));
	read_file(head, fd);
	head->split = ft_strsplit(head->instruction, '\n');
	head->first = NULL;
	head->count_room = 0;
	add_data(head);
	head->routes = (t_routes*)malloc(sizeof(t_routes));
	head->q_stack = NULL;
	head->q_last = NULL;
	//exit(0);
	add_queue(head, head->start);
	print_stack(head);
	printf("\n");
	add_queue(head, head->start);
	print_stack(head);
	exit(close(fd));
	//routes = route_line(head);
	count_step(routes);
	lem_go(head, routes);
	exit(close(fd));
}

void			print_stack(t_head *head)
{
	t_room		*tmp;

	if (!head->q_stack)
		return ;
	tmp = head->q_stack;
	while (tmp)
	{
		printf("%s\n", tmp->name);
		tmp = tmp->queue;
	}
}
