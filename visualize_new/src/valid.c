/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdoughnu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 13:10:23 by sdoughnu          #+#    #+#             */
/*   Updated: 2019/12/11 13:10:31 by sdoughnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in_viz.h"

int 	strcmp_until(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return ((unsigned char)(*s1) - (unsigned char)(*s2));
		s1++;
		s2++;
	}
	if (!*s2 && *s1 == '\n')
		return (0);
	return (1);
}

char 	*skip_text(char *str)
{
	while (*str && *str != '\n')
		str++;
	if (*str == '\n')
		str++;
	return (str);
}

char 	*skip_comm(char *str, int *ant)
{
	while (!ft_isdigit(*str))
	{
		if (*str == '#')
		{
			if (*(str + 1) != '#')
			{
				str = skip_text(str);
				continue;
			}
			if (!strcmp_until(str, "start") || !strcmp_until(str, "end"))
			{
				*ant = 0;
				return (NULL);
			}
			str = skip_text(str);
		}
		else
		{
			*ant = 0;
			return (NULL);
		}
	}
	return (str);
}

char 	*ants(char *str, int *ant)
{
	if (!(str = skip_comm(str, ant)))
	    return (NULL);
	*ant = ft_atoi(str);
	while (*str && *str != '\n')
	{
		if (!ft_isdigit(*str))
			return (NULL);
		str++;
	}
	if (*str == '\n')
		str++;
	return (str);
}

char 	*add_arr_room(t_path *pat, char *str)
{
	while (*str)
	{
		if (*str == '#')
		{
			if (*(str + 1) != '#')
			{
				str = skip_text(str);
				continue ;
			}
			if (!(str = is_start(str + 2, pat)))
				return (NULL);
			if (!(str = is_end(str + 2, pat)))
				return (NULL);
		}
		else
		{
			if (strchr_until(str, '-'))
				return (str);
			if (*str == 'L' || find_repeat(pat, str)
					|| !(str = add_arr(pat, str)))
				return (NULL);
		}
		*str ? str++ : NULL;
	}
	return (str);
}





































