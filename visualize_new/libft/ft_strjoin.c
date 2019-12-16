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
	size_t	len;
	char	*res;
	char	*temp;

	len = (s1 ? ft_strlen(s1) : 0) + (s2 ? ft_strlen(s2) : 0);
	res = (char*)malloc(sizeof(char) * (len + 1));
	temp = res;
	if (res)
	{
		while (s1 && *s1 != '\0')
			*temp++ = (char)*s1++;
		while (s2 && *s2 != '\0')
			*temp++ = (char)*s2++;
		*temp = '\0';
	}
	return (res);
}

