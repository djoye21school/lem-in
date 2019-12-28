/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdoughnu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 20:07:52 by sdoughnu          #+#    #+#             */
/*   Updated: 2019/12/26 20:08:14 by sdoughnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in_viz.h"

void 	calculator(bool coor, bool plmin, t_stack **ant, int i)
{
	float buf;

	buf = 0.0;
	if (coor == X)
	{
		ant[i]->itog_X = (plmin == PL) ? ant[i]->speed : -ant[i]->speed;
		if (ant[i]->dify != 0)
		{
			buf = (ant[i]->dify * ant[i]->speed) / ant[i]->difx;
			ant[i]->itog_Y = (plmin == PL) ? buf : -buf;
		}
	}
	else if (coor == Y)
	{
		ant[i]->itog_Y = (plmin == PL) ? ant[i]->speed : -ant[i]->speed;
		if (ant[i]->difx != 0)
		{
			buf = (ant[i]->difx * ant[i]->speed) / ant[i]->dify;
			ant[i]->itog_X = (plmin == PL) ? buf : -buf;
		}
	}
}

void	cor1(bool *pop, t_stack **ant, int i)
{
	if (ant[i]->px > ant[i]->nx)
	{
		ant[i]->px += ant[i]->itog_X;
		if (ant[i]->px < ant[i]->nx)
			ant[i]->px = ant[i]->nx;
		*pop = 0;

	}
	else if (ant[i]->px < ant[i]->nx)
	{
		ant[i]->px += ant[i]->itog_X;
		if (ant[i]->px > ant[i]->nx)
			ant[i]->px = ant[i]->nx;
		*pop = 0;
	}
}

void	cor2(bool *pop, t_stack **ant, int i)
{
	if (ant[i]->py > ant[i]->ny)
	{
		ant[i]->py += ant[i]->itog_Y;
		if (ant[i]->py < ant[i]->ny)
			ant[i]->py = ant[i]->ny;
		*pop = 0;
	}
	else if (ant[i]->py < ant[i]->ny)
	{
		ant[i]->py += ant[i]->itog_Y;
		if (ant[i]->py > ant[i]->ny)
			ant[i]->py = ant[i]->ny;
		*pop = 0;
	}
}

void	ant_goo(bool *pop, t_sdl *yep, t_stack **ant, t_path *pat, int i)
{
	cor1(pop, ant, i);
	cor2(pop, ant, i);
	if (ant[i]->px != -1 && ant[i]->py != -1 && ant[i]->nx != -1 && ant[i]->ny != -1)
	{
		ant[i]->hey = init_cor(ant[i]->px, ant[i]->py, house_w / 2, house_h / 2);
		if (SDL_RenderCopy(yep->ren, yep->ant, NULL, &ant[i]->hey))
			error_st(1, yep);
	}
}

void	go_right_now(t_sdl *yep, t_stack **ant, t_path *pat)
{
	bool pop;
	int		i;

	pop = 0;
	while (pop == 0)
	{
		pop = 1;
		if ((SDL_RenderClear(yep->ren)) < 0)
			error_st(1, yep);
		SDL_SetRenderTarget(yep->ren, yep->fon);
		if (SDL_RenderCopy(yep->ren, yep->fon, NULL, NULL) != 0)
		{
			ft_putstr("Oops... Error in going\n");
			error_st(1, yep);
		}
		draw_house(pat, yep);
		i = 0;
		while (i < pat->ant)
		{
			if (ant[i]->move)
				ant_goo(&pop, yep, ant, pat, i);
			i++;
		}
		SDL_RenderPresent(yep->ren);
	}
}

