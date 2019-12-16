/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdoughnu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 10:26:29 by sdoughnu          #+#    #+#             */
/*   Updated: 2019/12/16 12:50:07 by sdoughnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	unsigned int i;
	unsigned int it;

	it = 0;
	i = ft_strlen(dest);
	while (src[it] != '\0')
	{
		dest[i] = src[it];
		i++;
		it++;
	}
	dest[i] = '\0';
	return (dest);
}
