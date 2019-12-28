/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pomoch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdoughnu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 18:26:08 by sdoughnu          #+#    #+#             */
/*   Updated: 2019/12/28 18:26:48 by sdoughnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in_viz.h"

void		pom1(t_path *pat, int x, int y)
{
	pat->start.i = pat->now + 1;
	pat->start.x = x;
	pat->start.y = y;
}

void		pom2(t_path *pat, int x, int y)
{
	pat->end.i = pat->now + 1;
	pat->end.x = x;
	pat->end.y = y;
}
