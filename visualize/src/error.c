/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdoughnu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 12:23:43 by sdoughnu          #+#    #+#             */
/*   Updated: 2019/12/09 12:24:05 by sdoughnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in_viz.h"

void 	error_st(int i, t_sdl *yep)
{
	const char *str;

	str = SDL_GetError();
	printf("%s\n", str);
	if (i)
		quit(yep);
	exit (0);
}

void	quit(t_sdl *yep)
{
	SDL_DestroyTexture(yep->start);
	SDL_DestroyTexture(yep->fon);
	SDL_DestroyTexture(yep->ant);
	SDL_DestroyTexture(yep->end);
	SDL_DestroyTexture(yep->house);
	SDL_DestroyRenderer(yep->ren);
	SDL_DestroyWindow(yep->win);
	SDL_Quit();
}

void	error_img(int i, t_sdl *yep)
{
	const char *str;

	str = IMG_GetError();
	printf("%s\n", str);
	if (i)
		quit(yep);
	exit(0);
}