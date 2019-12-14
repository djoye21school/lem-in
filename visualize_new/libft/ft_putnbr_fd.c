/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdoughnu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 19:50:48 by sdoughnu          #+#    #+#             */
/*   Updated: 2019/04/08 19:50:54 by sdoughnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int res;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		res = n * (-1);
	}
	else
		res = n;
	while (res >= 10)
	{
		ft_putnbr_fd(res / 10, fd);
		res = res % 10;
	}
	ft_putchar_fd('0' + res, fd);
}
