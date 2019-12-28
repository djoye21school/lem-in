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

#include "../../includes/lem_in_viz.h"

char 	*is_valid(char *str, t_path *pat)
{
	str = ants(str, &(pat->ant));
	if (pat->ant <= 0 || !str || (!(str = add_arr_room(pat, str))))
		return (NULL);
	while (*str && *str != 'L')
	{
		if (*str == '#')
			str = skip_text(str);
		else
		{
			if (!(strchr_until(str, '-')))
				return (NULL);
            ox_eeee(pat, str);
			str = skip_text(str);
		}
	}
	return (str);
}

char	*output_lem_in(void)
{
	char *str;
	char *tmp;
	char *del;

	if (!(tmp = ft_strnew(10000)))
		return (NULL);
	str = NULL;
	while (read(0, tmp, 10000) > 0)
	{
		del = str;
		str = ft_strjoin(str, tmp);
		del ? ft_strdel(&del) : NULL;
		ft_bzero(tmp, 10000);
	}
	ft_strdel(&tmp);
	return (str);
}

void	init_lem(t_path **pat)
{
	if (!(*pat = (t_path*)malloc(sizeof(t_path))))
		error_inlem(NULL, 1);
	(*pat)->start.name = NULL;
	(*pat)->end.name = NULL;
	(*pat)->arr = NULL;
	(*pat)->ant = 0;
	(*pat)->size = 0;
	(*pat)->now = -1;
}

void	init_sdl(t_sdl *yep)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		error_st(0, yep);
	if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG)
		error_img(0, yep);
	if (!(yep->win = SDL_CreateWindow("Lem_In | djoye && sdoughnu", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			WIN_W, WIN_H, SDL_WINDOW_SHOWN)))
	    error_st(1, yep);
	if (!(yep->ren = SDL_CreateRenderer(yep->win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)))
		error_st(1, yep);
	if (SDL_SetRenderDrawColor(yep->ren, 255, 255, 255, 255))
		error_st(1, yep);
	if (!(yep->fon = IMG_LoadTexture(yep->ren, "pic/mmm.bmp")))
		error_img(1, yep);
	SDL_SetTextureBlendMode(yep->fon, SDL_BLENDMODE_NONE);
    if (!(yep->ant = IMG_LoadTexture(yep->ren, "pic/ant1.png")))
		error_img(1, yep);
	if (!(yep->house = IMG_LoadTexture(yep->ren, "pic/house.png")))
		error_img(1, yep);
}

int		main(int ac, char **av)
{
    char *str;
    char *s;
    t_sdl yep;
    t_path *pat;

    str = output_lem_in();
    if (str == NULL)
        error_inlem(str, 1);
    if (!(ft_strcmp("Error\n", str)))
        error_inlem(str, 1);
    init_lem(&pat);
    if (!(s = is_valid(str, pat)))
        error_inlem(str, 1);
    if (new_coor(pat))
    	error_inlem(str, 0);
	init_sdl(&yep);
	if (!vizu(&yep, pat, s))
		error_st(1, &yep);
	exit(0);
}
