/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolecomt <jolecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:24:48 by jolecomt          #+#    #+#             */
/*   Updated: 2023/12/12 13:15:23 by jolecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	set_color(t_color *color, int **map, int x, int y)
{
	if (map[x][y] > 0)
		color->color = 0xff00ff;
	else if (map[x][y] == 0)
		color->color = 0x00ff00;
	else
		color->color = 0x00ffff;
}
