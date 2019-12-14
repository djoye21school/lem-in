/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdoughnu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 09:36:50 by sdoughnu          #+#    #+#             */
/*   Updated: 2019/04/07 17:51:35 by sdoughnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int i;

	i = 0;
	if (n == 0)
		return (0);
	else if (!s1[i] && !s2[i])
		return (0);
	else if (s1[i] == 0)
		return (-1);
	else if (s2[i] == 0)
		return (1);
	while (--n && (s1[i] == s2[i]) && s1[i] && s2[i])
	{
		i++;
	}
	return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
}
