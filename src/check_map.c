/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolecomt <jolecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:30:36 by jolecomt          #+#    #+#             */
/*   Updated: 2023/11/07 17:55:38 by jolecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	check_error(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0' || s[i] != '\n')
	{
		if (s[i] <= '0' && s[i] >= '9')
		{
			printf("invalid map : (1)"); // change printf for ft_printf
			exit(EXIT_FAILURE);
		}
		while (s[i] >= '0' && s[i] <= '9')
			i++;
		if (s[i] != ' ')
		{
			printf("invalid map :(2)"); // change printf for ft_printf
			exit(EXIT_FAILURE);
		}
		++i;
		if (s[i] != '\0' || s[i] != '\n')
			return ;
	}
}

void	check_map(void)
{
	int		fd;
	char	*s;

	fd = open("test.txt", O_RDONLY);
	s = get_next_line(fd);
	while (s != NULL)
	{
		check_error(s);
		s = get_next_line(fd);
	}
	printf("map ok\n"); // change printf for ft_printf
	close(fd);
	return ;
}
