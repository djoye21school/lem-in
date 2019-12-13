/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdoughnu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 13:51:07 by sdoughnu          #+#    #+#             */
/*   Updated: 2019/04/08 14:23:46 by sdoughnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	i;
	char			*d;

	i = 0;
	if (s != NULL)
	{
		while (s[i])
			i++;
		if (!(d = (char *)malloc(sizeof(char) * i + 1)))
			return (NULL);
		i = 0;
		while (s[i])
		{
			d[i] = f(s[i]);
			i++;
		}
		d[i] = '\0';
		return (d);
	}
	return (NULL);
}
