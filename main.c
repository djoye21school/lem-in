/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoye <djoye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 12:59:53 by djoye             #+#    #+#             */
/*   Updated: 2019/11/27 15:15:29 by djoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int			main(int ac, char **av)
{
	char	buf[BUFF_SIZE + 1];
	int		fd;
	char	*str;
	char	*tmp;
	int		len;
	t_head	*head;

	if (ac != 2 || (fd = open(av[1], O_RDONLY)) < 0 || read(fd, NULL, 0) == -1)
		return (write(1, "usage: not valid file\n", 21) - 21);
	str = NULL;
	while((len = read(fd, buf, BUFF_SIZE)))
	{
		buf[len] = '\0';
		if (!str)
		{
			str = malloc(sizeof(char) + 1);
			str[0] = '\0';
		}
		tmp = str;
		str = ft_strjoin(tmp, buf);
		free (tmp);
	}
	head = add_head(str);
	printf("%s", str);
	return (close(fd));
}

t_head		*add_head(char *str)
{
	int		line;
	int		i;
	t_head	*head;

	line = 1;
	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			line++;
	printf("%d\n", line);
	return (head);
}

