/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdoughnu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 15:39:59 by sdoughnu          #+#    #+#             */
/*   Updated: 2019/12/25 19:41:57 by sdoughnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in_viz.h"

char		*strchr_until(const char *s, int c)
{
	char	*arr;

	arr = (char*)s;
	while (*arr && *arr != '\n')
	{
		if (*arr == (unsigned char)c)
			return (arr);
		arr++;
	}
	return (*arr == (unsigned char)c ? arr : NULL);
}

char		*skip_com2(char *str)
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

char		*is_dig(char *str)
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

char		*is_start(char *str, t_path *pat)
{
	t_stack		*a;
	int			x;
	int			y;

	if (*(str - 1) == '#' && *(str - 2) == '#' && !strcmp_until(str, "start"))
	{
		str = skip_text(str);
		str = skip_com2(str);
		pat->start.name = ft_strcut(str, ' ');
		while (*str && *str != ' ')
			str++;
		while (*str && (*str == ' ' || *str == '\t'))
			str++;
		x = ft_atoi(str);
		str = is_dig(str);
		y = ft_atoi(str);
		str = is_dig(str);
		pom1(pat, x, y);
		if (!(a = new_stack(pat->start.name, pat->start.i, x, y)))
			return (NULL);
		if (add_pat(a, pat))
			return (NULL);
		return (str);
	}
	return (str - 2);
}

char		*is_end(char *str, t_path *pat)
{
	t_stack		*a;
	int			x;
	int			y;

	if (*(str - 1) == '#' && *(str - 2) == '#' && !strcmp_until(str, "end"))
	{
		str = skip_text(str);
		str = skip_com2(str);
		pat->end.name = ft_strcut(str, ' ');
		while (*str && *str != ' ')
			str++;
		while (*str && (*str == ' ' || *str == '\t'))
			str++;
		x = ft_atoi(str);
		str = is_dig(str);
		y = ft_atoi(str);
		str = is_dig(str);
		pom2(pat, x, y);
		if (!(a = new_stack(pat->end.name, pat->end.i, x, y)))
			return (NULL);
		if (add_pat(a, pat))
			return (NULL);
		return (str);
	}
	return (str - 2);
}
