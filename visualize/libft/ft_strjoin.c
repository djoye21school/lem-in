/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdoughnu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:11:10 by sdoughnu          #+#    #+#             */
/*   Updated: 2019/04/09 15:37:44 by sdoughnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	it;
	unsigned int	count;
	char			*d;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	d = (char *)malloc(sizeof(char) * i + 1);
	if (!d)
		return (NULL);
	count = 0;
	while (s1[count])
	{
		d[count] = s1[count];
		count++;
	}
	it = count;
	count = 0;
	while (s2[count])
		d[it++] = s2[count++];
	d[it] = '\0';
	return (d);
}
