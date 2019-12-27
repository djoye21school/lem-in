/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoye <djoye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 12:59:53 by djoye             #+#    #+#             */
/*   Updated: 2019/12/27 20:51:33 by djoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				main(int ac, char **av)
{
	int			fd;
	t_head		head;

	if (ac != 2 || (fd = open(av[1], O_RDONLY)) < 0 || read(fd, NULL, 0) == -1)
		if (!(ac == 1 && fd == 0))
			exit(write(1, "ERROR: not valid file\n", 21) - 21);
	read_file(&head, fd);
	check_instruction(head.instruction);
	head.split = ft_strsplit(head.instruction, '\n');
	head.first = NULL;
	head.count_room = 0;
	add_data(&head);
	head.q_stack = NULL;
	head.q_last = NULL;
	write(1, head.instruction, ft_strlen(head.instruction));
	write(1, "\n", 1);
	check_start_end(&head, fd);
	create_routes(&head);
	while (head.count_route-- > 0)
		algo(&head);
	if (!head.routes[0])
		exit(write(1, "ERROR: not valid route\n", 22) - 22);
	lem_go(&head);
	exit(close(fd));
}

t_head			*algo(t_head *head)
{
	while (!check_end(head))
	{
		add_queue(head);
		if (!head->q_stack && (head->count_route = 0) == 0)
			break ;
	}
	clear_room_attribute(head);
	return (head);
}
