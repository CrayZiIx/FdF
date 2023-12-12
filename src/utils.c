/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolecomt <jolecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:23:09 by jolecomt          #+#    #+#             */
/*   Updated: 2023/12/12 13:20:22 by jolecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	iso(int *x, int *y, int z)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

void	set_iso(t_pxl *pxl, t_map *map, int coef)
{
	pxl->iso_xa = (map->x - (map->height / 2) - 1) * coef;
	pxl->iso_xb = (map->x - (map->height / 2) - 1) * coef;
	pxl->iso_xc = (map->x - (map->height / 2) - 1) * coef;
	pxl->iso_ya = (map->y - (map->length / 2) - 1) * coef;
	pxl->iso_yb = (map->y - (map->length / 2) - 1) * coef;
	pxl->iso_yc = (map->y - (map->length / 2) - 1) * coef;
	iso(&pxl->iso_xa, &pxl->iso_ya, map->map[map->x][map->y] * (coef / 2));
	if (map->x + 1 < map->height)
	{
		pxl->iso_xb = ((map->x + 1) - (map->height / 2) - 1) * coef;
		iso(&pxl->iso_xb, &pxl->iso_yb, map->map[map->x + 1][map->y]
			* (coef / 2));
	}
	else
		iso(&pxl->iso_xb, &pxl->iso_yb, map->map[map->x][map->y] * coef);
	if (map->y + 1 < map->length)
	{
		pxl->iso_yc = ((map->y + 1) - (map->length / 2) - 1) * coef;
		iso(&pxl->iso_xc, &pxl->iso_yc, map->map[map->x][map->y + 1]
			* (coef / 2));
	}
	else
		iso(&pxl->iso_xc, &pxl->iso_yc, map->map[map->x][map->y] * (coef / 2));
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
