/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdoughnu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:46:25 by sdoughnu          #+#    #+#             */
/*   Updated: 2019/04/09 15:41:36 by sdoughnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char const		*d;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (*s == ' ' || *s == '\t' || *s == '\n'
			|| *s == ',')
		s++;
	if (*s == '\0')
		return (ft_strnew(0));
	d = s + ft_strlen(s) - 1;
	while (*d == ' ' || *d == '\t' || *d == '\n' || *d == ',')
		d--;
	return (ft_strsub(s, 0, d - s + 1));
}
