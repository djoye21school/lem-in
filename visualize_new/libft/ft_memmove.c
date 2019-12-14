/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdoughnu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:36:15 by sdoughnu          #+#    #+#             */
/*   Updated: 2019/04/08 10:29:41 by sdoughnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	i = 0;
	if (s < d)
	{
		while (++i <= len)
			*(d + len - i) = *(s + len - i);
	}
	else
	{
		while (len--)
			*(d++) = *(s++);
	}
	return (dst);
}
