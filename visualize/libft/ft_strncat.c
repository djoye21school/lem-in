/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdoughnu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 11:36:12 by sdoughnu          #+#    #+#             */
/*   Updated: 2019/04/07 17:46:17 by sdoughnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t nb)
{
	size_t i;
	size_t it;

	it = 0;
	i = ft_strlen(dest);
	while (src[it] && nb)
	{
		dest[i] = src[it];
		i++;
		it++;
		nb--;
	}
	dest[i] = '\0';
	return (dest);
}
