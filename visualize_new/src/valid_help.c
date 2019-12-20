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

char	*skip_com2(char *str)
{
	while (*str)
	{
		if (*str == '#' && *(str + 1) != '#')
			str = skip_text(str);
		else if ((*str == '#' && *(str + 1) == '#'))
			return (NULL);
		else
			return (str);
	}
	return (str);
}

char	*is_dig(char *str)
{
	while (*str && (*str == ' ' || *str == '\t'))
		str++;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && ft_isdigit(*str))
		str++;
	if (*str && *str != ' ' && *str != '\t' && *str != '\n')
		return (NULL);
	while (*str && (*str == ' ' || *str == '\t'))
		str++;
	return (str);
}

char 	*is_start(char *str, t_path *pat)
{
	t_stack		*a;
	int x;
	int y;

	if (*(str - 1) == '#' && *(str - 2) == '#' && !strcmp_until(str, "start"))
	{
		if (pat->start.name)
			return (NULL);
		str = skip_text(str);
		str = skip_com2(str);
		if (!str || strchr_until(str, '-') || *str == 'L' || *str == '#')
			return (NULL);
		pat->start.name = ft_strcut(str, ' ');
		while (*str && *str != ' ')
			str++;
		while (*str && (*str == ' ' || *str == '\t'))
			str++;
		x = ft_atoi(str);
		if (!(str = is_dig(str)))
			return (NULL);
		y = ft_atoi(str);
		if (!(str = is_dig(str)))
			return (NULL);
		pat->start.i = pat->now + 1;
		pat->start.x = x;
		pat->start.y = y;
		if (!(a = new_stack(pat->start.name, pat->start.i, x, y)))
			return (NULL);
		if (add_pat(a, pat))
			return (NULL);
		return (str);
	}
	return (str - 2);
}

char 	*is_end(char *str, t_path *pat)
{
	t_stack		*a;

	if (*(str - 1) == '#' && *(str - 2) == '#' && !strcmp_until(str, "end"))
	{
		int x;
		int y;
		if (pat->end.name)
			return (NULL);
		str = skip_text(str);
		str = skip_com2(str);
		if (!str || strchr_until(str, '-') || *str == 'L' || *str == '#')
			return (NULL);
		pat->end.name = ft_strcut(str, ' ');
		while (*str && *str != ' ')
			str++;
		while (*str && (*str == ' ' || *str == '\t'))
			str++;
		x = ft_atoi(str);
		if (!(str = is_dig(str)))
			return (NULL);
		y = ft_atoi(str);
		if (!(str = is_dig(str)))
			return (NULL);
		pat->end.i = pat->now + 1;
		pat->end.x = x;
		pat->end.y = y;
		if (!(a = new_stack(pat->end.name, pat->end.i, x, y)))
			return (NULL);
		if (add_pat(a, pat))
			return (NULL);
		return (str);
	}
	return (str - 2);
}
