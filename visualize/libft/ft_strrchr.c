/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdoughnu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 09:36:53 by sdoughnu          #+#    #+#             */
/*   Updated: 2019/04/07 16:09:25 by sdoughnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;

	i = ft_strlen(s);
	if ((char)c == '\0')
		return ((char *)s + i);
	i--;
	while (i >= 0)
	{
		if ((*(s + i)) == (char)c)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}
