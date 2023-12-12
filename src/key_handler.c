/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolecomt <jolecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:57:33 by jolecomt          #+#    #+#             */
/*   Updated: 2023/12/12 13:44:42 by jolecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	key_handle(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
	{
		mlx_loop_end(vars);
		return (1);
	}
	return (0);
}
