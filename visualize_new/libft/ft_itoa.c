/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdoughnu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 14:37:13 by sdoughnu          #+#    #+#             */
/*   Updated: 2019/04/10 13:45:03 by sdoughnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lens(int n)
{
	int i;

	i = 0;
	if (n == 0)
		i = 1;
	else if (n < 0)
		i++;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char			*buf;
	int				i;
	int				sign;
	unsigned int	res;

	i = 0;
	res = n;
	sign = n;
	if (!(buf = ft_strnew(ft_lens(n))))
		return (NULL);
	if (n < 0)
		res = -n;
	if (res == 0)
		buf[i++] = '0';
	while (res > 0)
	{
		buf[i++] = res % 10 + '0';
		res = res / 10;
	}
	if (sign < 0)
		buf[i++] = '-';
	buf[i] = '\0';
	ft_strrev(buf);
	return (buf);
}
