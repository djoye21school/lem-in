/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdoughnu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 15:39:59 by sdoughnu          #+#    #+#             */
/*   Updated: 2019/12/12 15:40:01 by sdoughnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in_viz.h"

char    *strchr_until(const char *s, int c)
{
	char    *arr;

	arr = (char*)s;
	while (*arr && *arr != '\n')
	{
		if (*arr == (unsigned char)c)
			return (arr);
		arr++;
	}
	return (*arr == (unsigned char)c ? arr : NULL);
}

char 	*find_start(char *str, t_path *pat)
{
	if (*(str - 1) == '#' && *(str - 2) == '#' && !strcmp_until(str, "start"))
	{
		if (pat->start.name)
			return (NULL);
		str = skip_text;
		if (!str || strchr_until(str, '-') || *str == 'L' || *str == '#')
			return (NULL);
		pat->start.name = ft_strcat(str, ' ');
		while (*str && *str != ' ')
			str++;
		while (*str && (*str == ' ' || *str == '\t'))
			str++;

	}
	return (str - 2);
}

char 	*find_end(char *str, t_path *pat)
{

}
