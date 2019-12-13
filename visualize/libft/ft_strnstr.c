/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdoughnu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 12:40:02 by sdoughnu          #+#    #+#             */
/*   Updated: 2019/04/07 17:46:08 by sdoughnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t count;

	i = 0;
	count = 0;
	if (s2[i] == 0)
		return ((char *)s1);
	while (s1[i] && i < n)
	{
		while (i + count < n && s1[i + count] == s2[count]
				&& s2[count])
		{
			count++;
		}
		if (s2[count] == 0)
			return ((char *)&s1[i]);
		count = 0;
		i++;
	}
	return (NULL);
}
