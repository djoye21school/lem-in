/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdoughnu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 15:09:59 by sdoughnu          #+#    #+#             */
/*   Updated: 2019/04/10 10:09:21 by sdoughnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_strrev(char *s)
{
	unsigned int i;
	unsigned int len;

	i = 0;
	len = ft_strlen(s) - 1;
	while (i < len)
		ft_swap(&s[i++], &s[len--]);
}
