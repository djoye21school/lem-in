/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdoughnu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:29:45 by sdoughnu          #+#    #+#             */
/*   Updated: 2019/04/07 16:10:32 by sdoughnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	unsigned int i;
	unsigned int count;

	i = 0;
	count = 0;
	if (!s1[i] && !s2[i])
		return ((char *)s1);
	while (s1[i])
	{
		while (s1[i + count] == s2[count] && s2[count])
			count++;
		if (s2[count] == 0)
			return ((char *)&s1[i]);
		count = 0;
		i++;
	}
	return (NULL);
}
