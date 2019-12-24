/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoye <djoye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 12:59:53 by djoye             #+#    #+#             */
/*   Updated: 2019/12/23 19:56:13 by djoye            ###   ########.fr       */
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
	head->routes = NULL;
	algo(head);
	while (head->count_route)
		algo(head);
	count_step(head->routes);
	lem_go(head, head->routes);
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
		printf("%s -> lev: %d\n", tmp->name, tmp->level);
		tmp = tmp->queue;
	}
}
