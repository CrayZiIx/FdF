/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolecomt <jolecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:28:08 by jolecomt          #+#    #+#             */
/*   Updated: 2023/12/12 12:29:27 by jolecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	lower_line(t_line *line, t_img_data *img)
{
	int	x;
	int	y;

	line->dx = line->x1 - line->x0;
	line->dy = line->y1 - line->y0;
	if (line->dy < 0)
	{
		line->i = -line->i;
		line->dy = -line->dy;
	}
	line->line = (2 * line->dy) - line->dx;
	x = line->x0;
	y = line->y0;
	while (x < line->x1)
	{
		my_mlx_pixel_put(img, (x + 960), (y + 540), 0xFFFFF0);
		if (line->line > 0)
		{
			y = y + line->i;
			line->line = line->line + (2 * (line->dy - line->dx));
		}
		else
			line->line = line->line + 2 * line->dy;
		x++;
	}
}

void	upper_line(t_line *line, t_img_data *img)
{
	int	x;
	int	y;

	line->dx = line->x1 - line->x0;
	line->dy = line->y1 - line->y0;
	if (line->dx < 0)
	{
		line->i = -line->i;
		line->dx = -line->dx;
	}
	line->line = (2 * line->dx) - line->dy;
	x = line->x0;
	y = line->y0;
	while (y < line->y1)
	{
		my_mlx_pixel_put(img, x + 960, y + 540, 0xFFFFFF);
		if (line->line > 0)
		{
			x = x + line->i;
			line->line = line->line + (2 * (line->dx - line->dy));
		}
		else
			line->line = line->line + 2 * line->dx;
		y++;
	}
}

void	draw_line(t_line *line, t_img_data *img)
{
	if (line->abs_y < line->abs_x)
	{
		if (line->x0 > line->x1)
		{
			swap_co(&line->x0, &line->x1, &line->y0, &line->y1);
			lower_line(line, img);
		}
		else
			lower_line(line, img);
	}
	else
	{
		if (line->y0 > line->y1)
		{
			swap_co(&line->x0, &line->x1, &line->y0, &line->y1);
			upper_line(line, img);
		}
		else
			upper_line(line, img);
	}
}
