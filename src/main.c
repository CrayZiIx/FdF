/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolecomt <jolecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:41:08 by jolecomt          #+#    #+#             */
/*   Updated: 2023/12/12 17:48:16 by jolecomt         ###   ########.fr       */
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
	int			fd;

	if (argc != 2 || argv[1] == NULL)
	{
		write(1, "Please check in 'utils/test_maps' for a valid map!1\n", 53);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		write(1, "Please check in 'utils/test_maps' for a valid map!2\n", 53);
		return (1);
	}
	map = malloc(sizeof(t_map));
	get_stats(map, argv[1]);
	display(map);
	free_map(map);
	(void)argc;
	return (0);
}
