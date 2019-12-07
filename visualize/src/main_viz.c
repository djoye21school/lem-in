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

int		main(int ac, char **av)
{
	ac++;
	av++;
	if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER) != 0)
	{
		write(1, "error\n", 6);
		return (0);
	}
	SDL_Window *win = SDL_CreateWindow("HELLO", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);
	if (!win)
	{
		write(1, "error\n", 6);
		SDL_Quit();
		return (0);
	}
	//SDL_Delay(5000);
	while (1)
		//SDL_Delay(5000);
	SDL_DestroyWindow(win);
	SDL_Quit();
}












