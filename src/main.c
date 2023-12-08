/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolecomt <jolecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:41:08 by jolecomt          #+#    #+#             */
/*   Updated: 2023/12/08 20:32:13 by jolecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void free_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->height)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
	free(map);
}

int     main(int argc, char **argv)
{
	t_map		*map;
	
	map = malloc(sizeof(t_map));
	map->length =  get_length(argv[1]);        
	map->height =  get_height(argv[1]);
	map->map = alloc_map(argv[1]);
	display(map);
	free_map(map);
	(void)argc;

	return (0);
}

//TODO -> FIX GNL ( LEAK IN CONCATENANTE BUFER ) <3
