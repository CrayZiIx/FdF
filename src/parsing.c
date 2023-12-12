/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolecomt <jolecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:36:02 by jolecomt          #+#    #+#             */
/*   Updated: 2023/12/12 16:34:23 by jolecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	get_length(char *s)
{
	int	length;
	int	index;

	length = 0;
	index = 0;
	while (s[index])
	{
		if (s[index] == ' ')
		{
			length++;
			while (s[index] == ' ')
				index++;
		}
		index++;
	}
	if (s[index - 2] == ' ')
		length--;
	return (length + 1);
}

void	get_stats(t_map *map, char *path_map)
{
	char	*s;

	map->height = 0;
	map->fd = open(path_map, O_RDONLY);
	s = get_next_line(map->fd);
	map->length = get_length(s);
	free(s);
	while (s != NULL)
	{
		s = get_next_line(map->fd);
		free(s);
		map->height++;
	}
	map->map = alloc_map(map);
	close(map->fd);
	map->map = fill_map(map, path_map);
}

void	reverse_line(int *s, int length)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = length - 1;
	while (i < length / 2)
	{
		k = s[i];
		s[i] = s[j];
		s[j] = k;
		i++;
		j--;
	}
}

int	**fill_map(t_map *map, char *path_map)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(path_map, O_RDONLY);
	i = 0;
	while (i < map->height)
	{
		line = get_next_line(fd);
		set_numbers(line, map->map[i], map->length);
		free(line);
		reverse_line(map->map[i], map->length);
		i++;
	}
	close(fd);
	return (map->map);
}

int	**alloc_map(t_map *map)
{
	int	**tab;
	int	i;

	tab = malloc(sizeof(int *) * map->height);
	i = 0;
	while (i < map->height)
	{
		tab[i] = malloc(sizeof(int) * map->length);
		++i;
	}
	return (tab);
}
