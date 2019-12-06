/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_viz.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdoughnu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 09:40:25 by sdoughnu          #+#    #+#             */
/*   Updated: 2019/12/06 11:26:15 by sdoughnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_VIZ_H
# define LEM_IN_VIZ_H

# include <stdlib.h>
# include "SDL2/SDL.h"
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

typedef struct		s_sdl
{
	SDL_Window		*win;
	SDL_Renderer	*ren;
	SDL_Surface		*bmp;
	SDL_Texture		*bg;
	SDL_Texture		*ant;
	SDL_Texture		*end;
	int				size_sqr;
	int				win_x;
	int				win_y;
	SDL_Texture		*sqr;
	SDL_Rect		srcr;
	SDL_Rect		destr;
}					t_sdl;

#endif
