/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolecomt <jolecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:07:29 by jolecomt          #+#    #+#             */
/*   Updated: 2023/11/21 14:09:12 by jolecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	ft_atoi(const char **s)
{
	int result;
	int sign;

	result = 0;
	sign = 1;
	while (**s == ' ')
		++(*s);
	if(**s == '-')
	{
		sign = -1;
		++(*s);
	}
	while(**s >= '0' && **s <= '9')
	{
		result = result * 10 + (**s - '0');
		++(*s);
	}
	if(**s == ',')
	{
		while (**s != ' ')
			++(*s);
	}
	return (result * sign);
}
