/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoye <djoye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 13:51:54 by djoye             #+#    #+#             */
/*   Updated: 2019/12/27 16:56:25 by djoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_head		*read_file(t_head *head, int fd)
{
	char	buf[BUFF_SIZE + 1];
	int		len;
	char	*tmp;

	head->instruction = NULL;
	while ((len = read(fd, buf, BUFF_SIZE)))
	{
		buf[len] = '\0';
		if (!head->instruction)
			head->instruction = ft_strnew(1);
		tmp = head->instruction;
		head->instruction = ft_strjoin(tmp, buf);
		free(tmp);
	}
	return (head);
}

int			skip(char **str, int *i)
{
	while (str[*i][0] == '#')
		(*i)++;
	return (1);
}

int			count_lem(char *str)
{
	double	nb;
	int		i;

	i = 0;
	nb = 0;
	while (str[i])
		nb = nb * 10 + str[i++] - '0';
	if (!ft_str_is_numeric(str) || nb != (double)ft_atoi(str))
		exit(write(1, "error: no valid ants\n", 21) - 21);
	return ((int)nb);
}

t_head		*add_data(t_head *head)
{
	int		i;

	i = -1;
	while (head->split[++i])
	{
		if (i == 0 && skip(head->split, &i))
			head->count_lem = count_lem(head->split[i]);
		else if (ft_strequ("##start", head->split[i]) && skip(head->split, &i))
			head->start = add_room(head, head->split[i]);
		else if (ft_strequ("##end", head->split[i]) && skip(head->split, &i))
			head->end = add_room(head, head->split[i]);
		else if (head->split[i][0] == '#')
			continue ;
		else if (head->split[i][find_chr(head->split[i], 0, ' ')] == ' ')
			add_room(head, head->split[i]);
		else if (head->split[i][find_chr(head->split[i], 0, '-')] == '-')
			add_connect(head, head->split[i]);
		else
			exit(write(1, "error_read\n", 10) - 10);
	}
	return (head);
}

int			find_chr(char *str, int i, char c)
{
	while (str[i] && str[i] != c)
		i++;
	return (i);
}
