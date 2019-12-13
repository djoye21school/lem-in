/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdoughnu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 11:10:36 by sdoughnu          #+#    #+#             */
/*   Updated: 2019/04/08 12:28:36 by sdoughnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*buf;
	size_t	i;

	i = 0;
	if (!(buf = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (i <= size)
	{
		buf[i] = '\0';
		i++;
	}
	return (buf);
}
