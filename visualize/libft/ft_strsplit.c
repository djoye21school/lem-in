/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdoughnu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 11:12:06 by sdoughnu          #+#    #+#             */
/*   Updated: 2019/04/09 15:57:44 by sdoughnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_long(char const *s, char c)
{
	unsigned int i;
	unsigned int slovo;

	i = 0;
	slovo = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			slovo++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (slovo);
}

static char	*ft_strndup(char const *s, int len)
{
	char *buf;

	if (!(buf = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	buf = ft_strncpy(buf, s, len);
	buf[len] = '\0';
	return (buf);
}

static void	ft_res(unsigned int *i, unsigned int *slovo)
{
	*i = 0;
	*slovo = 0;
}

char		**ft_strsplit(char const *s, char c)
{
	char			**d;
	unsigned int	len;
	unsigned int	slovo;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	slovo = ft_long(s, c);
	if (!(d = (char **)malloc(sizeof(char *) * slovo + 1)))
		return (NULL);
	d[slovo] = NULL;
	ft_res(&i, &slovo);
	while (s[i])
	{
		if (s[i] != c)
		{
			len = i;
			while (s[i] != c && s[i])
				i++;
			d[slovo++] = ft_strndup(s + len, i - len);
		}
		else
			i++;
	}
	return (d);
}
