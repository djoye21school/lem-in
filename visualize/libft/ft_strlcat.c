/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdoughnu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 12:47:18 by sdoughnu          #+#    #+#             */
/*   Updated: 2019/04/09 15:37:19 by sdoughnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t len;
	size_t i;

	i = 0;
	len = 0;
	if (size < ft_strlen(dest))
		return (size + ft_strlen(src));
	if (size == 0)
		return (ft_strlen(src));
	while (dest[len] && len < size)
		len++;
	while ((size > len + i + 1) && src[i])
	{
		dest[i + len] = src[i];
		i++;
	}
	if (len != size)
		dest[len + i] = '\0';
	return (ft_strlen(src) + len);
}
