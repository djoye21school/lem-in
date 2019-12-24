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

char	*output_lem_in(int fd)
{
	char *str;
	char *tmp;
	char *del;

	if (!(tmp = ft_strnew(10000)))
		return (NULL);
	str = NULL;
	while (read(fd, tmp, 10000) > 0)
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
		error_inlem(NULL);
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
	if (!(yep->win = SDL_CreateWindow("VLADIMIRRRRRRR  SUPER GOOD", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
	        4000, 2000, SDL_WINDOW_FULLSCREEN)))
	    error_st(1, yep);

	if (!(yep->ren = SDL_CreateRenderer(yep->win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)))
		error_st(1, yep);
	if (!(yep->fon = IMG_LoadTexture(yep->ren, "../pic/mmm.bmp")))
		error_img(1, yep);
    SDL_SetTextureBlendMode(yep->fon, SDL_BLENDMODE_NONE);


	if (!(yep->ant = IMG_LoadTexture(yep->ren, "../pic/ant1.png")))
		error_img(1, yep);
	if (!(yep->house = IMG_LoadTexture(yep->ren, "../pic/house.png")))
		error_img(1, yep);
}

int		main(int ac, char **av) {
    char *str;
    char *s;
    t_sdl yep;
    t_path *pat;

    int fd;
    fd = open("test", O_RDONLY);
    printf("%d\n", fd);
    str = output_lem_in(fd);
    if (str == NULL)
        error_inlem(str);
    if (!(ft_strcmp("Error\n", str)))
        error_inlem(str);
    init_lem(&pat);
    if (!(s = is_valid(str, pat)))
        error_inlem(str);
//    printf("STOOOOP\n");
//    printf("%s - ", pat->arr[0]->name);
//    printf("%s - ", pat->arr[0]->next->name);
//    printf("%s - ", pat->arr[0]->next->next->name);
//    printf("\n%ld x ", pat->arr[0]->next->next->x);
//    printf("\n%ld y ", pat->arr[0]->next->next->y);
//    printf("%s - ", pat->arr[0]->next->next->next->name);
//    printf("\n%ld x ", pat->arr[0]->next->next->next->x);
//    printf("\n%ld y ", pat->arr[0]->next->next->next->y);
//        t_stack *buf;
//        int i = 0;
//        while (i < pat->now)
//        {
//            buf = pat->arr[i];
//            while (buf)
//            {
//                printf("%s - ", buf->name);
//                buf = buf->next;
//            }
//            printf("\n");
//            i++;
//        }
    init_sdl(&yep);

	vizu(&yep, pat, s);
	return (0);
}



/*

int         	main(int ac, char **av)
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
			5120, 2880, SDL_WINDOW_FULLSCREEN)))
		error_st(1, &yep);
	if (!(yep.ren = SDL_CreateRenderer(yep.win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)))
		error_st(1, &yep);

	if (!(yep.fon = IMG_LoadTexture(yep.ren, "../pic/mine(1).bmp")))
		error_img(1, &yep);
	SDL_SetRenderTarget(yep.ren, yep.fon);


	if (!(yep.ant = IMG_LoadTexture(yep.ren, "../pic/ant1.png")))
		error_img(1, &yep);
	if (!(yep.house = IMG_LoadTexture(yep.ren, "../pic/house.png")))
		error_img(1, &yep);


	int w;
	int h;
	SDL_Rect a;
	SDL_Rect b;
	SDL_Rect c;

	SDL_QueryTexture(yep.house, NULL, NULL, &w, &h);
	printf("house ширина %d\n", w);
	printf("house высота %d\n", h);
	yep.srcr.x = 100;
	yep.srcr.y = 100;
	yep.srcr.w = w / 5;
	yep.srcr.h = h / 5;
	printf("%d\n %d", yep.destr.x, yep.destr.y);
	int ab = w;
	int bb = h;
	a.x = 300;
	a.y = 7;
	a.w = w / 5;
	a.h = h / 5;

	b.x = 500;
	b.y = 500;
	b.w = w;
	b.h = h;

	c.x = 700;
	c.y = 700;
	c.w = w;
	c.h = h;



	SDL_QueryTexture(yep.ant, NULL, NULL, &w, &h);
	int x = 1720 / 2 - w / 2;
	int y = 1080 / 2 - h / 2;


	yep.destr.x = x;
	yep.destr.y = y;
	yep.destr.w = ab / 2;
	yep.destr.h = bb / 3;

	printf("ant ширина %d\n", w);
	printf("ant высота %d\n", h);

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
			if (SDL_RenderCopy(yep.ren, yep.house, NULL, &(a)) != 0)
				error_st(1, &yep);
			if (SDL_RenderCopy(yep.ren, yep.house, NULL, &(b)) != 0)
				error_st(1, &yep);
			if (SDL_RenderCopy(yep.ren, yep.house, NULL, &(c)) != 0)
				error_st(1, &yep);
			if (SDL_RenderCopy(yep.ren, yep.ant, NULL, &(yep.destr)) != 0)
					error_st(1, &yep);
		}
		SDL_RenderPresent(yep.ren);
	}
	quit(&yep);
	return (0);
}


*/
