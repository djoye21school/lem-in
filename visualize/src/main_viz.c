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

/*int		main()
{
	int scr_wi = 100;
	int scr_hei = 100;
	t_sdl p;

//	p->win = SDL_CreateWindow("HI!", scr_wi, scr_hei, )

}*/

/*int main(int argc, char **argv)
{
	SDL_Surface *screen;
	SDL_Window *window;
	SDL_Surface *image;

	SDL_Init(SDL_INIT_EVERYTHING);

	window = SDL_CreateWindow("SDL2 Example",  100, 100, 640, 480, SDL_WINDOW_SHOWN);
	screen = SDL_GetWindowSurface(window);
	image = SDL_LoadBMP("a.bmp");
	SDL_BlitSurface(image, NULL, screen, NULL);
	SDL_FreeSurface(image);


	SDL_UpdateWindowSurface(window);

	SDL_Delay(2000);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}*/

/*int		main(int ac, char **av)
{
	t_sdl v;


	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		return (write(1, "error\n", 6));

	if ((v.win = SDL_CreateWindow("Hello World!", 0, 0, 640, 480, SDL_WINDOW_ALLOW_HIGHDPI)) == NULL)
		return (write(1, "error\n", 6));

		if ((v.ren = SDL_CreateRenderer(v.win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)) == NULL)
			return (write(1, "error\n", 6));
		if ((v.bmp = SDL_LoadBMP("./a.bmp")) == NULL)
			return (write(1, "error\n", 6));
		v.bg = SDL_CreateTextureFromSurface(v.ren, v.bmp);
		SDL_FreeSurface(v.bmp);
		if (v.bg == NULL)
			return (write(1, "error\n", 6));
		SDL_RenderClear(v.ren);
		SDL_RenderCopy(v.ren, v.bg, NULL, NULL);
		SDL_RenderPresent(v.ren);

		SDL_Delay(5000);
		SDL_DestroyTexture(v.bg);
		SDL_DestroyRenderer(v.ren);
		SDL_DestroyWindow(v.win);
		SDL_Quit();
}*/

int         	main()
{
	int			run;
	SDL_Event	e;
	SDL_Window	*win;
	SDL_Surface	*ant;
	SDL_Surface	*surf;
	SDL_Rect	rect;
	int			speed;
	SDL_Keycode	before;

	run = 1;
	rect.x = 0;
	rect.y = 0;
	rect.h = 100;
	rect.w = 100;
	speed = 1;
	SDL_Init(SDL_INIT_EVERYTHING);
	win = SDL_CreateWindow("Dota 2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, SDL_WINDOW_SHOWN);
	surf = SDL_GetWindowSurface(win);
	ant = SDL_LoadBMP("../pic/2.bmp");

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
		SDL_FillRect(surf ,NULL, 0x404040);
		SDL_BlitScaled(ant, NULL, surf, &rect);
		SDL_UpdateWindowSurface(win);
	}
	SDL_FreeSurface(surf);
	SDL_DestroyWindow(win);
	SDL_Quit();
	return (0);
}











