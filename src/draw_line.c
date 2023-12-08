/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolecomt <jolecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 20:39:09 by jolecomt          #+#    #+#             */
/*   Updated: 2023/12/08 17:32:48 by jolecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void set_line(int x0, int y0, int x1, int y1, t_line *line)
{
	line->dx = x1 - x0;
	line->dy = y1 - y0;
	line->x = x0;
	line->y = y0;
	line->i = 1;
}

void lowerLine(int x0, int y0, int x1, int y1, t_img_data *img)
{
	t_line *line;

	line = malloc(sizeof(t_line));
	set_line(x0, y0, x1, y1, line);
	if (line->dy < 0)
	{
		line->i = -1;
		line->dy = -line->dy;
	}
	line->line = (2 * line->dy) - line->dx;
	line->y = y0;
	line->x = x0;
	while (line->x < x1)
	{
		my_mlx_pixel_put(img, line->x + 960 , line->y + 540, 0xFFFFFF);
		if (line->line > 0)
		{
			line->y = line->y + line->i;
			line->line = line->line + (2 * (line->dy - line->dx));
		}
		else
			line->line = line->line + 2 * line->dy;
		line->x++;	
	}
	free(line);
}

void upperLine(int x0, int y0, int x1, int y1, t_img_data *img)
{
	t_line *line;

	line = malloc(sizeof(t_line));
	set_line(x0, y0, x1, y1, line);
	if (line->dx < 0)
	{
		line->i = -line->i;
		line->dx = -line->dx;
	}
	line->line = (2 * line->dx) - line->dy;
	while (line->y < y1)
	{
		my_mlx_pixel_put(img, line->x + 960 , line->y + 540, 0xFFFFFF);
		if (line->line > 0)
		{
			line->x = line->x + line->i;
			line->line = line->line + (2 * (line->dx - line->dy));
		}
		else
			line->line = line->line + 2 * line->dx;
		line->y++;
	}
	free(line);
}
void	draw_line(int x0, int y0, int x1, int y1, t_img_data *img)
{
	if (abs(y1 - y0) < abs(x1 - x0))
	{
		if (x0 > x1)
			lowerLine(x1, y1, x0, y0, img);
		else 
			lowerLine(x0, y0, x1, y1, img);
	}
	else
	{
		if (y0 > y1)
			upperLine(x1, y1, x0, y0, img);
		else
			upperLine(x0, y0, x1, y1, img);
	}
}