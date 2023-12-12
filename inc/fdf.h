/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolecomt <jolecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:20:55 by jolecomt          #+#    #+#             */
/*   Updated: 2023/12/12 14:04:02 by jolecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct s_img_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img_data;

typedef struct s_color
{
	int	color;
}		t_color;

typedef struct s_map
{
	int	fd;
	int	height;
	int	length;
	int	x;
	int	y;
	int	**map;
}		t_map;

typedef struct s_pxl
{
	float	steep_ab;
	float	steep_ac;
	int		iso_xa;
	int		iso_ya;
	int		iso_xb;
	int		iso_yb;
	int		iso_xc;
	int		iso_yc;
}		t_pxl;

typedef struct s_vars
{
	void		*mlx;
	void		*mlx_win;
	t_img_data	img;
}		t_vars;

typedef struct s_line
{
	int	x0;
	int	x1;
	int	y0;
	int	y1;
	int	dx;
	int	dy;
	int	i;
	int	line;
	int	abs_x;
	int	abs_y;
}		t_line;

/*----color.c----*/
unsigned long	create_rgb(t_color *color);// idk how to fix that
void			set_color(t_color *color, int **map, int x, int y);

/*----parsing.c----*/
int				**fill_map(t_map *map, char *path_map);
int				**alloc_map(t_map *map);
void			get_stats(t_map *map, char *path_map);
void			reverse_line(int *s, int length);
int				get_length(char *s);

/*----ft_atoi.c*/
int				ft_atoi(const char **s);

/*----display.c----*/
void			do_lines(t_pxl *pxl, t_img_data *img, t_map *map);
void			do_point(t_vars *vars, t_map *map, t_color *color, int coef);
void			display(t_map *map);

/*----utils.c----*/
void			iso(int *x, int *y, int z);
void			set_iso(t_pxl *pxl, t_map *map, int coef);
void			set_numbers(const char *line, int *tab, int length);

/*----line.c----*/
void			lower_line(t_line *line, t_img_data *img);
void			upper_line(t_line *line, t_img_data *img);
void			draw_line(t_line *line, t_img_data *img);

/*----key_handler.c----*/
int				key_handle(int keycode, t_vars *vars);

/*----point_utils.c ----*/
void			set_ab(t_line *line, t_pxl *pxl);
void			set_ac(t_line *line, t_pxl *pxl);
void			set_point(t_line *line1, t_line *line2, t_pxl *pxl);

/*----img_utils.c ----*/
int				check_if_in(t_pxl *pxl, t_map *map, int *coef);
int				free_mlx(t_vars *vars);
void			refresh_img(t_vars *vars);
void			my_mlx_pixel_put(t_img_data *data, int x, int y, int color);

/*----line_utils.c----*/
void			swap_co(int *x0, int *x1, int *y0, int *y1);

#endif