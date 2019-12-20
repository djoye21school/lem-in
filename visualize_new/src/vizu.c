/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vizu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdoughnu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 17:17:41 by sdoughnu          #+#    #+#             */
/*   Updated: 2019/12/16 17:17:42 by sdoughnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in_viz.h"
/*
int			eventi(void)
{
  	SDL_Event e;

  	while (SDL_PollEvent(&e))
	{
	  	if (e.type == SDL_QUIT)
	  	  return (0);
	  	if (e.type == SDL_KEYDOWN)
		  {
		    if (e.key.keysym.sym == SDLK_ESCAPE)
		      return (0);
		  }
	}
	  return (1);
}
*/

int 	init_ants(t_stack *ant, t_path *pat)
{
	int		i;

	i = 0;
	if (!(ant = (t_stack*)malloc(sizeof(t_stack) * (pat->ant))))
		return (0);
	while (i < pat->ant)
	{
		ant->i = i;
		ant->x = pat->start.x;
		ant->y = pat->start.y;
		i++;
		ant = ant->next;
	}
	return (1);
}

int 	init_coordinates(t_path *pat, t_sdl *yep)
{
	int i;

	i = 0;
	yep->srcr.x = pat->start.x;
	yep->srcr.y = pat->start.y;
	SDL_QueryTexture(yep->house, NULL, NULL, &yep->srcr.w, &yep->srcr.h);

	if (SDL_RenderCopy(yep->ren, yep->house, NULL, &(yep->srcr)) != 0)
		error_st(1, yep);
	while (i++ <= pat->now)
	{
		if (pat->arr[i]->i == pat->start.i)
			continue ;

	}
}

int 	vizu(t_sdl *yep, t_path *pat, char *str)
{
  	int 		q;
  	t_stack		*ant;

  	q = 1;
  	ant = NULL;
  	if (!init_ants(ant, pat))
  		return (0);
  	while (q)
  	{
		SDL_Event e;
		while (SDL_PollEvent(&e))
			{
				if (e.type == SDL_QUIT)
					q = 0;
				if (e.type == SDL_KEYDOWN)
					if (e.key.keysym.sym == SDLK_ESCAPE)
						q = 0;
			}
		SDL_SetRenderTarget(yep->ren, yep->fon);
	//	if (SDL_RenderClear(yep->ren) != 0)
		//	error_st(1, yep);

		if (SDL_RenderCopy(yep->ren, yep->fon, NULL, NULL) != 0)
			error_st(1, yep);
		SDL_RenderDrawLine(yep->ren, 0, 0, 1000, 1000);
		SDL_RenderPresent(yep->ren);
  		//house_stay(t_path *pat);
  		//ants_go(t_path *pat);
  	  	//q = eventi();
  	}
  	quit(yep);
  	return (1);
}

