/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdoughnu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:16:38 by sdoughnu          #+#    #+#             */
/*   Updated: 2019/04/09 16:16:44 by sdoughnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		i;
	int		len;

	len = 0;
	i = 0;
	while (src[len] != 0)
		len++;
	if (!(dest = (char *)malloc(sizeof(char) * (len + 1))) || src == 0)
		return (NULL);
	while (len != 0)
	{
		dest[i] = src[i];
		i++;
		len--;
	}
	dest[i] = '\0';
	return (dest);
}
