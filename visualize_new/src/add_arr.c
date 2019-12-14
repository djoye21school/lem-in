/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_arr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdoughnu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 12:42:00 by sdoughnu          #+#    #+#             */
/*   Updated: 2019/12/14 12:42:02 by sdoughnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in_viz.h"

char 	*add_arr(t_path *pat, char *str)
{
	t_stack *a;

	a->name = ft_strcat(str, " ");
	while (*str && *str != ' ')
		str++;
	while (*str && (*str == ' ' || *str == '\t'))
		str++;
	if (!(is_dig(str)))
		return (NULL);
	if (!(is_dig(str)))
		return (NULL);
	a->i = pat->now + 1;
	a = new_stack(a->name, a->i);
	if (add_pat(a, pat))
		return (NULL);
	return (str);
}

int 	strcmp_name(t_stack *old, char *str, char s)
{
	char *dest;

	dest = old->name;
	while (*str && *dest)
	{
		if (*str != *dest)
			return (1);
		dest++;
		str++;
	}
	if (!*dest && *str == s)
		return (0);
	return (1);
}

int 	find_repeat(t_path *pat, char *str)
{
	int		i;
	char	*s;

	i = 0;
	s = str;
	while (i <= pat->now)
	{
		if (strcmp_name(pat->arr[i], s, ' '))
			return (1);
		i++;
	}
	return (0);
}
