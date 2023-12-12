/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolecomt <jolecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:41:08 by jolecomt          #+#    #+#             */
/*   Updated: 2023/12/12 16:40:53 by jolecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
	free(map);
}

int	main(int argc, char **argv)
{
	t_map		*map;
	int fd;

	if (argc != 2 || (fd = open(argv[1], O_RDONLY))< 0 )
	{
		write(1, "Rentre une map valide !", 24);
		return (1);
	}
	map = malloc(sizeof(t_map));
	get_stats(map, argv[1]);
	display(map);
	free_map(map);
	(void)argc;
	return (0);
}
