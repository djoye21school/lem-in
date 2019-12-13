/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdoughnu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 14:50:08 by sdoughnu          #+#    #+#             */
/*   Updated: 2019/04/09 15:38:19 by sdoughnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
			d[i] = f(i, s[i]);
			i++;
		}
		d[i] = '\0';
		return (d);
	}
	return (NULL);
}
