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

int			event(t_path *pat, t_sdl *yep, char *str, t_stack **ant)
{
  	SDL_Event e;
  	int p = 1;

  	while (SDL_PollEvent(&e))
	{
	  	if (e.type == SDL_QUIT)
	  	  return (0);
	  	if (e.type == SDL_KEYDOWN)
		  {
		    if (e.key.keysym.sym == SDLK_ESCAPE)
		      return (0);
		    else if (e.key.keysym.sym == SDLK_RIGHT)
				return (move_ant(pat, yep, str, ant));
		  }
	}
	  return (1);
}


t_stack 	**init_ants(t_path *pat)
{
	int		k;
	t_stack **ant;

	k = 0;
	if (!(ant = (t_stack**)malloc(sizeof(t_stack*) * (pat->ant))))
		return (0);
	while (k < pat->ant)
	{
		if (!(ant[k] = (t_stack*)malloc(sizeof(t_stack) * 1)))
			return (NULL);
		ant[k]->i = k;
		ant[k]->x = pat->start.x;
		ant[k]->y = pat->start.y;
		ant[k]->px = -1;
		ant[k]->py = -1;
		ant[k]->nx = -1;
		ant[k]->ny = -1;
		ant[k]->move = 0;
		ant[k]->speed = 1;
		ant[k]->next = NULL;
		k = k + 1;
	}
	return (ant);
}


int 	init_coordinates(t_path *pat, t_sdl *yep)
{
	SDL_QueryTexture(yep->house, NULL, NULL, &(yep->srcr.w), &(yep->srcr.h));
	yep->srcr.w = yep->srcr.w - 100;
    yep->srcr.h = yep->srcr.h - 100;
    return (0);
}

int     draw_house(t_path *pat, t_sdl *yep)
{
    int i;

    i = 0;
	init_coordinates(pat, yep);
	if (!draw_line(pat, yep))
		return (0);
    while (i <= pat->now)
    {
        yep->srcr.x = pat->arr[i]->x;
        yep->srcr.y = pat->arr[i]->y;
        SDL_SetRenderTarget(yep->ren, yep->house);
        if (SDL_RenderCopy(yep->ren, yep->house, NULL, &(yep->srcr)) != 0)
            error_st(1, yep);
        i++;
    }
    return (1);
}

int 	vizu(t_sdl *yep, t_path *pat, char *str)
{
  	int 		q;
  	t_stack		**ant;

  	q = 1;
  	if (!(ant = init_ants(pat)))
  		return (0);
  	while (q)
  	{
        SDL_SetRenderTarget(yep->ren, yep->fon);
		if (SDL_RenderCopy(yep->ren, yep->fon, NULL, NULL) != 0)
			error_st(1, yep);
        if (!draw_house(pat, yep))
        	return (0);
		SDL_RenderPresent(yep->ren);
		q = event(pat, yep, str, ant);
  	}
  	quit(yep);
  	return (1);
}
