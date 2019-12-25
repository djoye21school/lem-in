/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoye <djoye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 12:59:53 by djoye             #+#    #+#             */
/*   Updated: 2019/12/25 16:23:47 by djoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				main(int ac, char **av)
{
	int			fd;
	t_head		head;

	if (ac != 2 || (fd = open(av[1], O_RDONLY)) < 0 || read(fd, NULL, 0) == -1)
		if (!(ac == 1 && fd == 0))
			exit(write(1, "usage: not valid file\n", 21) - 21);
	read_file(&head, fd);
	check_instruction(head.instruction);
	head.split = ft_strsplit(head.instruction, '\n');
	head.first = NULL;
	head.count_room = 0;
	add_data(&head);
	head.q_stack = NULL;
	head.q_last = NULL;
	head.routes = NULL;
	algo(&head);
	while (head.count_route)
		algo(&head);
	count_step(&head);
	lem_go(&head);
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
