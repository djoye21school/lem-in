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

# include <stdio.h>
# include <stdlib.h>
# include "SDL.h"
# include "SDL_image.h"
# include <unistd.h>
# include <fcntl.h>
# include <sys/uio.h>
# include <ctype.h>
# include <string.h>
# include <aio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "../libft/libft.h"

#define WIN_H 1000
#define WIN_W 1300
#define house_w 150
#define house_h 150
#define onx (house_w / 2)
#define ony (house_h / 2)

typedef struct		s_sdl
{
	SDL_Window		*win;
	SDL_Renderer	*ren;
	SDL_Surface		*surf;

	SDL_Texture 	*fon;
	SDL_Texture		*start;
	SDL_Texture 	*ant;
	SDL_Texture		*end;
	int				ant_rect;
	SDL_Texture		*house;
	SDL_Rect		srcr;
	SDL_Rect		destr;
}					t_sdl;

typedef struct		s_stack
{
	char 			*name;
	long			i;
	long 			x;
	long 			y;
	float 			dx;
	float 			dy;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_path
{
	int				ant;
	long			size;
	long			now;
	t_stack 		ants;
	t_stack			**arr;
	t_stack			start;
	t_stack 		end;
}					t_path;

typedef struct		s_ttf
{
	int				ant;
	long			size;
	long			now;
	t_stack 		ants;
	t_stack			**arr;
	t_stack			start;
	t_stack 		end;
}					t_ttf;

void	error_inlem(char *str, int i);
void 	error_st(int i, t_sdl *yep);
void	error_img(int i, t_sdl *yep);
void	quit(t_sdl *yep);

char 	*ants(char *str, int *ant);
char 	*add_arr_room(t_path *pat, char *str);
char 	*skip_comm(char *str, int *ant);

char    *strchr_until(const char *s, int c);
char	*is_dig(char *str);
char 	*is_end(char *str, t_path *pat);
char 	*is_start(char *str, t_path *pat);
char	*skip_com2(char *str);

char 	*skip_text(char *str);
int 	strcmp_until(char *s1, char *s2);

int 	find_repeat(t_path *pat, char *str);
int 	strcmp_name(t_stack *old, char *str, char s);
char 	*add_arr(t_path *pat, char *str);

char 	*ft_strcut(char *str, char d);

int		add_pat(t_stack *new, t_path *pat);
t_stack	*new_stack(char *st, int iter, int x, int y);

int 	vizu(t_sdl *yep, t_path *pat, char *str);
int 	init_coordinates(t_path *pat, t_sdl *yep);
int     ox_eeee(t_path *pat, char *str);

int 		new_coor(t_path *pat, t_sdl *yep);
//int 		draw_name(t_path *pat, t_sdl *yep);
int 		draw_line(t_path *pat, t_sdl *yep);
int 	move_ant(t_path *pat, t_sdl *yep, char *str);

#endif
