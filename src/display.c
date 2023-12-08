/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolecomt <jolecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:22:01 by jolecomt          #+#    #+#             */
/*   Updated: 2023/12/08 19:55:51 by jolecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	do_lines(t_pxl *pxl, t_img_data *img, t_color *color, t_map *map)
{
	if (map->x < map->height - 1)
	{
		draw_line(pxl->iso_xa, pxl->iso_ya, pxl->iso_xb, pxl->iso_yb,  img);
		draw_line(pxl->iso_xa, pxl->iso_ya, pxl->iso_xc, pxl->iso_yc,  img);
	}
	else
		draw_line(pxl->iso_xa, pxl->iso_ya, pxl->iso_xc, pxl->iso_yc,  img);
	
	(void)color;
	(void)map;
}

void	do_point(t_img_data *img, t_map *map, t_color *color, int coef)
{
	t_pxl	*pxl;

	pxl = malloc(sizeof(t_pxl));
	map->x = 0;
	map->y = 0;
	while (map->x < map->height) // (x < height)
	{
		while (map->y < map->length)//(y < length)
		{
			set_iso(pxl, map, coef, map->x, map->y);
			set_color(color, map->map, map->x , map->y);
			if ((pxl->iso_xa + 960 > 1920 || pxl->iso_xa + 960 < 0) || (pxl->iso_ya + 540 > 1080 || pxl->iso_ya + 540 < 0))
			{
				map->y++;
				continue ;
			}
			do_lines(pxl, img, color, map);
			my_mlx_pixel_put(img, pxl->iso_xa + 960 , pxl->iso_ya + 540, createRGB(color));
			map->y++;
		}
		map->x++;
		map->y = 0;
	}
	free(pxl);
}

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}



int	free_mlx(t_vars *vars)
{
	// (void) vars;
	if (vars->mlx)
	{
		printf("1\n");
		mlx_clear_window(vars->mlx, vars->mlx_win);
		printf("1\n");
		mlx_destroy_window(vars->mlx, vars->mlx_win);
	}
	if (vars->img.img)
	{
		printf("2\n");
		mlx_destroy_image(vars->mlx, vars->img.img);
	}
	if (vars->mlx)
	{
		printf("3\n");
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}

	return (0);
}
int key_handler(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
	{
		mlx_loop_end(vars);
		return (1);
	}
	return (0);
		
}

void	display(t_map *map)
{
	t_vars *vars;
	// void	*mlx;
	// void	*mlx_win;
	// t_img_data	img;
	int coef;
	t_color *color = malloc(sizeof(t_color) + 1);

	vars = malloc(sizeof(t_vars));
	coef = 5;
	vars->mlx = mlx_init();
	vars->mlx_win = mlx_new_window(vars->mlx, 1920, 1080, "FdF");
	vars->img.img = mlx_new_image(vars->mlx, 1920, 1080);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel, &vars->img.line_length, &vars->img.endian);
	do_point(&vars->img, map, color, coef);
	mlx_hook(vars->mlx_win, KeyPress, KeyPressMask, key_handler, vars->mlx);
	mlx_hook(vars->mlx_win, 17, 1L << 17, mlx_loop_end, vars->mlx);	
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img.img, 0, 0);
	mlx_loop(vars->mlx);
	free_mlx(vars);
	free(color);
	free(vars);
}
