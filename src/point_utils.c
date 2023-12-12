/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolecomt <jolecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:59:35 by jolecomt          #+#    #+#             */
/*   Updated: 2023/12/12 13:11:42 by jolecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	set_ab(t_line *line, t_pxl *pxl)
{
	line->i = 1;
	line->x0 = pxl->iso_xa;
	line->y0 = pxl->iso_ya;
	line->x1 = pxl->iso_xb;
	line->y1 = pxl->iso_yb;
	line->dx = line->x1 - line->x0;
	line->dy = line->y1 - line->y0;
	line->abs_x = abs(pxl->iso_xb - pxl->iso_xa);
	line->abs_y = abs(pxl->iso_yb - pxl->iso_ya);
}

void	set_ac(t_line *line, t_pxl *pxl)
{
	line->i = 1;
	line->x0 = pxl->iso_xa;
	line->y0 = pxl->iso_ya;
	line->x1 = pxl->iso_xc;
	line->y1 = pxl->iso_yc;
	line->dx = line->x1 - line->x0;
	line->dy = line->y1 - line->y0;
	line->abs_x = abs(pxl->iso_xc - pxl->iso_xa);
	line->abs_y = abs(pxl->iso_yc - pxl->iso_ya);
}

void	set_point(t_line *line1, t_line *line2, t_pxl *pxl)
{
	set_ab(line1, pxl);
	set_ac(line2, pxl);
}
