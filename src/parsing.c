/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolecomt <jolecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:36:02 by jolecomt          #+#    #+#             */
/*   Updated: 2023/12/08 17:40:45 by jolecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int     get_length(char *map)
{
	int     fd;
	int     length;
	char    *s;
	int index;
	
	fd = open(map, O_RDONLY);
	s = get_next_line(fd);
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
	while (s != NULL)
		s = get_next_line(fd);
	close(fd);
	return (length + 1);
}

int     get_height(char *map)
{
	int     fd;
	int     height;
	char    *s;

	fd = open(map, O_RDONLY);
	s = get_next_line(fd);
	height = 0;
	while (s != NULL)
	{
		s = get_next_line(fd);
		height++;
	}
	close(fd);
	return(height);
}

void	reverse_line(int *s, int length)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = length - 1;
	while (i < length / 2 )
	{
		k = s[i];
		s[i] = s[j];
		s[j] = k;
		i++;
		j--;	
	}
}

int     **fill_map(int **tab, char *map, int height, int length)
{
	int     fd;
	char *line;
	int     i;

	fd = open(map, O_RDONLY);
	i = 0;
	
	while(i < height)
	{
		line = get_next_line(fd);
		set_numbers(line, tab[i], length);
		reverse_line(tab[i], length);
		i++;
	}
	return (tab);
}

int     **alloc_map(char *map)
{
	int     height;
	int     length;
	int     **tab;
	int     i;

	height = get_height(map);
	length = get_length(map);
	tab = malloc(sizeof(int*) * height);
	i = 0;
	while(i < height)
	{
		tab[i] = malloc(sizeof(int) * length);                
		++i;
	}
	fill_map(tab, map, height, length);
	return (tab);
}

// void    print_tab(int **tab, int length, int height)
// {
// 	int     i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while(i < height)
// 	{
// 		while (j < length)
// 			printf("%d ", tab[i][j++]);
// 		printf("\n");
// 		i++;
// 		j = 0;
// 	}
// }
