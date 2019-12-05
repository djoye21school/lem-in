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

#include "./lem_in_viz.h"

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

int main(int argc, char* argv[])
{
	SDL_Surface *screen; // even with SDL2, we can still bring ancient code back
	SDL_Window *window;
	SDL_Surface *image;

	SDL_Init(SDL_INIT_VIDEO); // init video

	// create the window like normal
	window = SDL_CreateWindow("SDL2 Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);

	// but instead of creating a renderer, we can draw directly to the screen
	screen = SDL_GetWindowSurface(window);

	// let's just show some classic code for reference
	image = SDL_LoadBMP("box.bmp"); // loads image
	SDL_BlitSurface(image, NULL, screen, NULL); // blit it to the screen
	SDL_FreeSurface(image);

	// this works just like SDL_Flip() in SDL 1.2
	SDL_UpdateWindowSurface(window);

	// show image for 2 seconds
	SDL_Delay(2000);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}