/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdoughnu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 13:27:37 by sdoughnu          #+#    #+#             */
/*   Updated: 2019/04/08 19:49:35 by sdoughnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int res;

	if (n < 0)
	{
		ft_putchar('-');
		res = n * (-1);
	}
	else
		res = n;
	while (res >= 10)
	{
		ft_putnbr(res / 10);
		res = res % 10;
	}
	ft_putchar('0' + res);
}
