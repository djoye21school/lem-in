/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdoughnu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 19:37:25 by sdoughnu          #+#    #+#             */
/*   Updated: 2019/04/07 20:03:39 by sdoughnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;
	size_t			i;

	s = (unsigned char *)s1;
	d = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s[i] != d[i])
			return ((unsigned char)s[i] - (unsigned char)d[i]);
		i++;
	}
	return (0);
}
