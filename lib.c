/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoye <djoye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 14:46:45 by djoye             #+#    #+#             */
/*   Updated: 2019/11/27 19:35:18 by djoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		ft_strequ(char const *s1, char const *s2)
{
	while (s1 && s2 && *s1 && s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (s1 && s2 && *s1 == '\0' && *s2 == '\0')
		return (1);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	unsigned int	i;
	unsigned int	c;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	while (s1[i] != '\0')
		i++;
	c = 0;
	while (s2[c] != '\0')
		c++;
	i = c + i;
	str = (char*)malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (*s1)
		str[i++] = *s1++;
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}
