/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolecomt <jolecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:24:48 by jolecomt          #+#    #+#             */
/*   Updated: 2023/12/08 17:27:55 by jolecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

unsigned long createRGB(t_color *color)
{   
	return (((color->r & 0xff) << 24) + ((color->g & 0xff) << 16) + ((color->b & 0xff) << 8));
}

void 	set_color(t_color *color, int **map, int x, int y)
{
	if (map[x][y] > 0)// top
	{
		color->r = 0xff;
		color->g = 0x00;
		color->b = 0xff;
	}
	else if (map[x][y] == 0) // mid
	{
		color->r = 0x00;
		color->g = 0xff;
		color->b = 0x00;
	}
	else // bottom
	{
		color->r = 0x00;
		color->g = 0xff;
		color->b = 0xff;
	}
}
