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

char 	*is_valid(char *str, t_path *pat)
{
	t_stack *one;
	t_stack	*two;

	str = ants(str, &(pat->ant));
	if (pat->ant <= 0 || (!(str = add_rooms(pat, str)))) // && !str
		return (NULL);
}


char	*output_lem_in(void)
{
	char *str;
	char *tmp;
	char *del;

	if ((tmp = ft_strnew(100000)))
		return (NULL);
	str = NULL;
	while (read(0, tmp, 100000) > 0)
	{
		del = str;
		str = ft_strjoin(str, tmp);
		del ? ft_strdel(&del) : NULL;
		ft_bzero(tmp, 100000);
	}
	ft_strdel(&tmp);
	return (str);
}
void	init_lem(t_path **pat)
{
	(*pat)->start.name = NULL;
	(*pat)->end.name = NULL;
	(*pat)->arr = NULL;
	(*pat)->ant = 0;
}

int		main(int ac, char **av)
{
	char	*str;
	char 	*s;
	t_sdl	*yep;
	t_path	*pat;

	if (!(str = output_lem_in()))
		error_inlem(str);
	if (!ft_strcmp("Error\n", str))
		error_inlem(str);
	init_lem(&pat);
	if (!(s = is_valid(str, pat)))
		error_inlem(str);

}

/*int         	main(int ac, char **av)
{
	t_sdl		yep;
	int			run;
	SDL_Event	e;


	int			speed;
	SDL_Keycode	before;

	run = 1;
	speed = 1;
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		error_st(0, &yep);

	if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG)
		error_img(0, &yep);

	if (!(yep.win = SDL_CreateWindow("VLADIMIRRRRRRR  SUPER GOOD", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			1720, 1080, SDL_WINDOW_SHOWN)))
		error_st(1, &yep);
	if (!(yep.ren = SDL_CreateRenderer(yep.win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)))
		error_st(1, &yep);

//	if (!(yep.surf = SDL_LoadBMP("../pic/trav.bmp")))
//		error_st(1, &yep);
//	if (!(yep.fon = SDL_CreateTextureFromSurface(yep.ren, yep.surf)))
//		error_st(1, &yep);
//	SDL_FreeSurface(yep.surf);

	if (!(yep.fon = IMG_LoadTexture(yep.ren, "../pic/trav.bmp")))
		error_img(1, &yep);
	SDL_SetRenderTarget(yep.ren, yep.fon);


	if (!(yep.ant = IMG_LoadTexture(yep.ren, "../pic/ant.png")))
		error_img(1, &yep);
	if (!(yep.house = IMG_LoadTexture(yep.ren, "../pic/house.png")))
		error_img(1, &yep);

	if (SDL_RenderClear(yep.ren) != 0)
		error_st(1, &yep);

//	if (SDL_RenderCopy(yep.ren, yep.fon, NULL, NULL) != 0)
//		error_st(1, &yep);

	int w;
	int h;
	SDL_QueryTexture(yep.ant, NULL, NULL, &w, &h);
	int x = 1720 / 2 - w / 2;
	int y = 1080 / 2 - h / 2;

	//int x = 100;
	//int y = 100;
	yep.destr.x = x;
	yep.destr.y = y;
	yep.destr.w = w / 3;
	yep.destr.h = h / 3;

	SDL_QueryTexture(yep.house, NULL, NULL, &w, &h);
	yep.srcr.x = 100;
	yep.srcr.y = 100;
	yep.srcr.w = w / 4;
	yep.srcr.h = h / 4;
	printf("%d\n %d", yep.destr.x, yep.destr.y);
//	SDL_QueryTexture(yep.house, NULL, NULL, )

//	SDL_RenderCopy(yep.ren, yep.ant, NULL, &(yep.destr));
//	SDL_RenderPresent(yep.ren);
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
					yep.destr.x -= speed;
				}
				else if (e.key.keysym.sym == SDLK_UP)
				{
					if (before == SDLK_UP)
						speed++;
					else
						speed = 1;
					yep.destr.y -= speed;
				}
				else if (e.key.keysym.sym == SDLK_DOWN)
				{
					if (before == SDLK_DOWN)
						speed++;
					else
					speed = 1;
					yep.destr.y += speed;
				}
				else if (e.key.keysym.sym == SDLK_RIGHT)
				{
					if (before == SDLK_RIGHT)
						speed++;
					else
						speed = 1;
					yep.destr.x += speed;
				}
			}
				if (SDL_RenderCopy(yep.ren, yep.fon, NULL, NULL) != 0)
					error_st(1, &yep);
				if (SDL_RenderCopy(yep.ren, yep.house, NULL, &(yep.srcr)) != 0)
					error_st(1, &yep);
				if (SDL_RenderCopy(yep.ren, yep.ant, NULL, &(yep.destr)) != 0)
					error_st(1, &yep);


		}
		SDL_RenderPresent(yep.ren);
	}
	quit(&yep);
	return (0);
}*/









