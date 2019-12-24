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

int			event(void)
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

int     init_coordinates2(t_stack *room)
{
    static int x = 10;
    int y;
    t_stack     *buf;

    y = 100;
    x += 150;
    buf = room;
    while (buf)
    {
        buf->x = buf->x + x;
        buf->y = buf->y + y;
        y = y + 150;
        buf = buf->next;
    }
    return (0);
}

int 	init_coordinates(t_path *pat, t_sdl *yep)
{
	int i;

	i = 0;
	SDL_QueryTexture(yep->house, NULL, NULL, &(yep->srcr.w), &(yep->srcr.h));
	yep->srcr.w = yep->srcr.w - 100;
    yep->srcr.h = yep->srcr.h - 100;
    while (i <= pat->now)
    {
        init_coordinates2(pat->arr[i]);
        i++;
    }
}

int     init(t_path *pat, t_sdl *yep)
{
    int i = 0;
//    t_stack *buf;
    while (i <= pat->now)
    {
//        buf = pat->arr[i];
        yep->srcr.x = pat->arr[i]->x;
        yep->srcr.y = pat->arr[i]->y;
        SDL_SetRenderTarget(yep->ren, yep->house);
        if (SDL_RenderCopy(yep->ren, yep->house, NULL, &(yep->srcr)) != 0)
            error_st(1, yep);
        i++;
//        printf("name: %s\n", buf->name);
//        printf("   x: %d\n", buf->x);
//        printf("   y: %d\n\n", buf->y);
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
    init_coordinates(pat, yep);
  	while (q)
  	{
        SDL_SetRenderTarget(yep->ren, yep->fon);
		if (SDL_RenderCopy(yep->ren, yep->fon, NULL, NULL) != 0)
			error_st(1, yep);
//      SDL_SetRenderTarget(yep->ren, yep->fon);
//		SDL_RenderDrawLine(yep->ren, 0, 0, 1000, 1000);
        init(pat, yep);
		SDL_RenderPresent(yep->ren);
		q = event();
  		//house_stay(t_path *pat);
  		//ants_go(t_path *pat);
  	  	//q = eventi();
  	}
  	quit(yep);
  	return (1);
}

