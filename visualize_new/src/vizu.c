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

int			event(t_path *pat, t_sdl *yep, char *str)
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
		  //  else if (e.key.keysym.sym == SDLK_RETURN)
		   // 	move_ant(pat, yep, str);
		  }
	}
	  return (1);
}


int 	init_ants(t_stack *ant, t_path *pat)
{
	int		i;

	i = 0;
	if (!(ant = (t_stack*)malloc(sizeof(t_stack) * (pat->ant))))
		return (0);
	while (i < pat->ant)
	{
		ant[i].i = i;
		ant[i].x = pat->start.x;
		ant[i].y = pat->start.y;
		i++;
	}
	return (1);
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
  	t_stack		*ant;

  	q = 1;
  	ant = NULL;
  	if (!init_ants(ant, pat))
  		return (0);
  	while (q)
  	{
        SDL_SetRenderTarget(yep->ren, yep->fon);
		if (SDL_RenderCopy(yep->ren, yep->fon, NULL, NULL) != 0)
			error_st(1, yep);
        if (!draw_house(pat, yep))
        	return (0);
        //draw_name(pat, yep);
		SDL_RenderPresent(yep->ren);
		q = event(pat, yep, str);
  	}
  	quit(yep);
  	return (1);
}
