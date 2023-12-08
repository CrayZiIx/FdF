/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolecomt <jolecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:20:55 by jolecomt          #+#    #+#             */
/*   Updated: 2023/12/08 19:27:00 by jolecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "mlx.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct	s_img_data
{
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}			t_img_data;

typedef struct	s_color
{
	int r;
	int g;
	int b;
	int a;
}		t_color;

typedef struct s_line
{
	int dx;
	int dy;
	int x;
	int y;
	int i;
	int line;
}		t_line;

typedef struct s_map
{
	int	height;
	int	length;
	int	x;
	int	y;
	int	**map;
}		t_map;

typedef struct	s_pxl
{
	int	iso_xa;
	int 	iso_ya;
	int 	iso_xb;
	int 	iso_yb;
	int 	iso_xc;
	int 	iso_yc;
	float	steep_ab;
	float	steep_ac;
}		t_pxl;

typedef struct s_vars
{
	void	*mlx;
	void	*mlx_win;
	t_img_data	img;
}		t_vars;

/*----parsing.c----*/
int     get_length(char *map);
int     get_height(char *map);
void	reverse_line(int *s, int length);
int     **fill_map(int **tab, char *map, int height, int length);
int     **alloc_map(char *map);

/*----ft_atoi.c*/
int	ft_atoi(const char **s);

/*----display.c----*/
void	do_point(t_img_data *img, t_map *map,t_color *color, int coef);
void	do_lines(t_pxl *pxl, t_img_data *img, t_color *color, t_map *map);
void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color);
void	display(t_map *map);

/*----color.c----*/
unsigned long createRGB(t_color *color);
void 	set_color(t_color *color, int **map, int x, int y);

/*----utils.c----*/
void	iso(int *x, int *y, int z);
void	set_iso(t_pxl *pxl, t_map *map, int coef, int x, int y);
void	set_numbers(const char *line, int *tab, int length);

/*----draw_line.c----*/
void set_line(int x0, int y0, int x1, int y1, t_line *line);
void lowerLine(int x0, int y0, int x1, int y1, t_img_data *img);
void upperLine(int x0, int y0, int x1, int y1, t_img_data *img);
void	draw_line(int x0, int y0, int x1, int y1, t_img_data *img);

#endif