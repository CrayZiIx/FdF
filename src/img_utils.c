/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolecomt <jolecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:57:53 by jolecomt          #+#    #+#             */
/*   Updated: 2023/12/12 13:08:59 by jolecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	check_if_in(t_pxl *pxl, t_map *map, int *coef)
{
	if (((pxl->iso_xa + 960) > 1920 || (pxl->iso_xa + 960) < 0)
		|| ((pxl->iso_ya + 540) > 1080 || (pxl->iso_ya + 540) < 0))
	{
		map->y = 0;
		map->x = 0;
		*coef = *coef / 2;
		return (1);
	}
	if (((pxl->iso_xb + 960) > 1920 || (pxl->iso_xb + 960) < 0)
		|| ((pxl->iso_yb + 540) > 1080 || (pxl->iso_yb + 540) < 0))
	{
		map->y = 0;
		map->x = 0;
		*coef = *coef / 2;
		return (1);
	}
	if (((pxl->iso_xc + 960) > 1920 || (pxl->iso_xc + 960) < 0)
		|| ((pxl->iso_yc + 540) > 1080 || (pxl->iso_yc + 540) < 0))
	{
		map->y = 0;
		map->x = 0;
		*coef = *coef / 2;
		return (1);
	}
	return (0);
}

void	refresh_img(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.img);
	vars->img.img = mlx_new_image(vars->mlx, 1920, 1080);
}

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

int	free_mlx(t_vars *vars)
{
	if (vars->mlx)
	{
		mlx_clear_window(vars->mlx, vars->mlx_win);
		mlx_destroy_window(vars->mlx, vars->mlx_win);
	}
	if (vars->img.img)
	{
		mlx_destroy_image(vars->mlx, vars->img.img);
	}
	if (vars->mlx)
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	return (0);
}
