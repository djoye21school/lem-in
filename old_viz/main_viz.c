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

#include "./include/lem_in_viz.h"

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
	SDL_Surface *screen; // even with SDL2, we can still bring ancient code back
	SDL_Window *window;
	SDL_Surface *image;

	SDL_Init(SDL_INIT_EVERYTHING); // init video

	// create the window like normal
	window = SDL_CreateWindow("SDL2 Example",  100, 100, 640, 480, SDL_WINDOW_SHOWN);

	// but instead of creating a renderer, we can draw directly to the screen
	screen = SDL_GetWindowSurface(window);

	// let's just show some classic code for reference
	image = SDL_LoadBMP("./pic/a.bmp"); // loads image
	SDL_BlitSurface(image, NULL, screen, NULL); // blit it to the screen
	SDL_FreeSurface(image);

	// this works just like SDL_Flip() in SDL 1.2
	SDL_UpdateWindowSurface(window);

	// show image for 2 seconds
	SDL_Delay(10000);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}*/

int main(int argc, char* argv[])
{
	SDL_Window *window;                    // Declare a pointer

	SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2

	// Create an application window with the following settings:
	window = SDL_CreateWindow(
			"An SDL2 window",                  // window title
			SDL_WINDOWPOS_UNDEFINED,           // initial x position
			SDL_WINDOWPOS_UNDEFINED,           // initial y position
			640,                               // width, in pixels
			480,                               // height, in pixels
			SDL_WINDOW_SHOWN                 // flags - see below
	);

	// Check that the window was successfully created
	if (window == NULL) {
		// In the case that the window could not be made...
		printf("Could not create window: %s\n", SDL_GetError());
		return 1;
	}

	// The window is open: could enter program loop here (see SDL_PollEvent())

	SDL_Delay(4000);  // Pause execution for 3000 milliseconds, for example

	// Close and destroy the window
	SDL_DestroyWindow(window);

	// Clean up
	SDL_Quit();
	return 0;
}