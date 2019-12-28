/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoye <djoye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 12:59:53 by djoye             #+#    #+#             */
/*   Updated: 2019/12/28 15:52:23 by djoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

int				main(int ac, char **av)
{
	t_head		head;
	int			n;

	if (ac != 1 && av)
		exit(write(2, "ERROR: not valid file\n", 22) - 22);
	read_file(&head);
	check_instruction(head.instruction);
	head.split = ft_strsplit(head.instruction, '\n');
	head.first = NULL;
	head.count_room = 0;
	add_data(&head);
	head.q_stack = NULL;
	head.q_last = NULL;
	write(1, head.instruction, n = ft_strlen(head.instruction));
	head.instruction[n - 1] == '\n' ? write(1, "\n", 1) : write(1, "\n\n", 2);
	check_start_end(&head);
	create_routes(&head);
	while (head.count_route-- > 0)
		algo(&head);
	if (!head.routes[0])
		exit(write(2, "ERROR: not valid route\n", 23) - 23);
	lem_go(&head);
	exit(0);
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
