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
# include "SDL.h"
# include "SDL_image.h"
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "../libft/libft.h"

typedef struct		s_sdl
{
	SDL_Window		*win;
	SDL_Renderer	*ren;
	SDL_Surface		*surf;

	SDL_Texture 	*fon;
	SDL_Texture		*start;
	SDL_Texture 	*ant;
	SDL_Texture		*end;
	int				size_sqr;
	int				win_x;
	int				win_y;
	SDL_Texture		*house;
	SDL_Rect		srcr;
	SDL_Rect		destr;
}					t_sdl;

typedef struct		s_stack
{
	char 			*name;
	unsigned		i;
	long 			x;
	long 			y;
	float 			dx;
	float 			dy;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_path
{
	int				ant;
	t_stack			**arr;
	t_stack			start;
	t_stack 		end;
}					t_path;


void	error_inlem(char *str);
void 	error_st(int i, t_sdl *yep);
void	error_img(int i, t_sdl *yep);
void	quit(t_sdl *yep);

char 	*ants(char *str, int *ant);
char 	*add_rooms(t_path *pat, char *str);
char 	*skip_comm(char *str, int *ant);

char    *strchr_until(const char *s, int c);

#endif
