/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolecomt <jolecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:22:01 by jolecomt          #+#    #+#             */
/*   Updated: 2023/12/12 13:45:00 by jolecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	do_lines(t_pxl *pxl, t_img_data *img, t_map *map)
{
	t_line	*line1;
	t_line	*line2;

	line1 = malloc(sizeof(t_line));
	line2 = malloc(sizeof(t_line));
	set_point(line1, line2, pxl);
	if (map->x < map->height - 1)
	{
		draw_line(line1, img);
		draw_line(line2, img);
	}
	else
		draw_line(line2, img);
	free(line1);
	free(line2);
	(void)map;
}

void	do_point(t_vars *vars, t_map *map, t_color *color, int coef)
{
	t_pxl	*pxl;

	pxl = malloc(sizeof(t_pxl));
	map->x = 0;
	map->y = 0;
	while (map->x < map->height)
	{
		while (map->y < map->length)
		{
			set_iso(pxl, map, coef);
			set_color(color, map->map, map->x, map->y);
			if (check_if_in(pxl, map, &coef) == 1)
			{
				refresh_img(vars);
				continue ;
			}
			do_lines(pxl, &vars->img, map);
			my_mlx_pixel_put(&vars->img, pxl->iso_xa
				+ 960, pxl->iso_ya + 540, color->color);
			map->y++;
		}
		map->x++;
		map->y = 0;
	}
	free(pxl);
}

void	display(t_map *map)
{
	t_vars	*vars;
	t_color	*color;
	int		coef;

	vars = malloc(sizeof(t_vars));
	color = malloc(sizeof(t_color) + 1);
	coef = 100;
	vars->mlx = mlx_init();
	vars->mlx_win = mlx_new_window(vars->mlx, 1920, 1080, "FdF");
	vars->img.img = mlx_new_image(vars->mlx, 1920, 1080);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel,
			&vars->img.line_length, &vars->img.endian);
	do_point(vars, map, color, coef);
	mlx_hook(vars->mlx_win, KeyPress, KeyPressMask, key_handle, vars->mlx);
	mlx_hook(vars->mlx_win, 17, 1L << 17, mlx_loop_end, vars->mlx);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img.img, 0, 0);
	mlx_loop(vars->mlx);
	free_mlx(vars);
	free(color);
	free(vars);
}
