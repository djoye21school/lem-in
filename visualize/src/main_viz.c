/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_viz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdoughnu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 11:02:47 by sdoughnu          #+#    #+#             */
/*   Updated: 2019/12/03 11:04:04 by sdoughnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in_viz.h"


/*char	*output_lem_in()
{
	char *str;

	while (read())
}

int		main(int ac, char **av)
{
	char *str;

	str = output_lem_in();
	if (!ft_strcmp("Error\n", str))
	{
		ft_strdel(&str);
		return (write(2, "Error\n", 6));
	}
}*/

int         	main(int ac, char **av)
{
	t_sdl		yep;
	int			run;
	SDL_Event	e;

	SDL_Rect	rect;
	int			speed;
	SDL_Keycode	before;

	run = 1;
	rect.x = 0;
	rect.y = 0;
	rect.h = 100;
	rect.w = 100;
	speed = 1;
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		error_st(0, &yep);
	if (!(yep.win = SDL_CreateWindow("VLADIMIRRRRRRR  SUPER GOOD", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			1720, 1080, SDL_WINDOW_SHOWN)))
		error_st(1, &yep);
	yep.ren = SDL_CreateRenderer(yep.win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);


	if (!(yep.surf = SDL_LoadBMP("../pic/trav.bmp")))
		error_st(1, &yep);
	if (!(yep.fon = SDL_CreateTextureFromSurface(yep.ren, yep.surf)))
		error_st(1, &yep);
	SDL_FreeSurface(yep.surf);

	SDL_RenderClear(yep.ren);
	SDL_RenderCopy(yep.ren, yep.fon, NULL, NULL);

	SDL_RenderPresent(yep.ren);
	while (run)
	{  
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
				run = 0;
			if (e.type == SDL_KEYDOWN)
			{
				before = e.key.keysym.sym;
				if (e.key.keysym.sym == SDLK_ESCAPE)
					run = 0;
				else if (e.key.keysym.sym == SDLK_LEFT)
				{
					if (before == SDLK_LEFT)
						speed++;
					else
						speed = 1;
					rect.x -= speed;
				}
				else if (e.key.keysym.sym == SDLK_UP)
				{
					if (before == SDLK_UP)
						speed++;
					else
						speed = 1;
					rect.y -= speed;
				}
				else if (e.key.keysym.sym == SDLK_DOWN)
				{
					if (before == SDLK_DOWN)
						speed++;
					else
						speed = 1;
					rect.y += speed;
				}
				else if (e.key.keysym.sym == SDLK_RIGHT)
				{
					if (before == SDLK_RIGHT)
						speed++;
					else
						speed = 1;
					rect.x += speed;
				}
			}
		}

	}
	SDL_DestroyTexture(yep.fon);
	SDL_DestroyRenderer(yep.ren);
	SDL_DestroyWindow(yep.win);
	SDL_Quit();
	return (0);
}










