/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolecomt <jolecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:23:09 by jolecomt          #+#    #+#             */
/*   Updated: 2023/12/08 17:42:23 by jolecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void iso(int *x, int *y, int z)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599); // cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599); // sin(0.523599);
}

void set_iso(t_pxl *pxl, t_map *map, int coef, int x, int y)
{
	pxl->iso_xa = ( x - (map->height / 2) - 1) * coef;
	pxl->iso_xb = ( x - (map->height / 2) - 1) * coef;
	pxl->iso_xc = ( x - (map->height / 2) - 1) * coef;
	pxl->iso_ya = (y - (map->length / 2) - 1) * coef;
	pxl->iso_yb = (y - (map->length / 2) - 1) * coef;
	pxl->iso_yc = (y - (map->length / 2) - 1) * coef;
	iso(&pxl->iso_xa, &pxl->iso_ya, map->map[x][y] * (coef / 2));
	if (x + 1 < map->height)
	{
		pxl->iso_xb = ( (x + 1) - (map->height / 2) - 1) * coef;
		iso(&pxl->iso_xb, &pxl->iso_yb, map->map[x + 1][y] * (coef / 2));
	}
	else
		iso(&pxl->iso_xb, &pxl->iso_yb, map->map[x][y] * coef);
	if (y + 1 < map->length)
	{
		pxl->iso_yc = ( (y + 1) - (map->length / 2) - 1) * coef;
		iso(&pxl->iso_xc, &pxl->iso_yc, map->map[x][y + 1] * (coef / 2));
	}
	else
		iso(&pxl->iso_xc, &pxl->iso_yc, map->map[x][y] * (coef / 2));
}

void	set_numbers(const char *line, int *tab, int length)
{
	int	i;

	i = 0;
	while (i < length)
	{
		tab[i++] = ft_atoi(&line);
	}
}
