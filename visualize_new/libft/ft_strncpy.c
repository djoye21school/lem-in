/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdoughnu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 16:11:31 by sdoughnu          #+#    #+#             */
/*   Updated: 2019/04/07 16:08:06 by sdoughnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		if (n != 0)
		{
			dest[i] = src[i];
			n = n - 1;
			i = i + 1;
		}
		else
			return (dest);
	}
	while (n != 0)
	{
		dest[i] = '\0';
		n--;
		i++;
	}
	return (dest);
}
