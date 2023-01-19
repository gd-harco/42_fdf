/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:08:01 by gd-harco          #+#    #+#             */
/*   Updated: 2023/01/16 17:45:34 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"
#include <fcntl.h>
#include "line_drawing.h"


void	ft_print_int_map(t_int_map map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			ft_printf("%d ", map.content[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void	ft_print_map(t_map map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			ft_printf("%d %d %d \n", map.content_display[i][j].x,
				map.content_display[i][j].y, map.content_display[i][j].z);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

t_map	get_t_map(t_int_map *int_map)
{
	t_map	map;
	size_t	x;
	size_t	y;

	map.content = malloc(sizeof(t_3dpoint *) * int_map->height);
	map.content_display = malloc(sizeof(t_3dpoint *) * int_map->height);
	y = -1;
	while (++y < int_map->height)
	{
		map.content[y] = malloc(sizeof(t_3dpoint) * int_map->width);
		map.content_display[y] = malloc(sizeof(t_3dpoint) * int_map->width);
		x = -1;
		while (++x < int_map->width)
		{
			map.content[y][x].y = (float)y - (float)int_map->height / 2.0f;
			map.content[y][x].x = (float)x - (float)int_map->width / 2.0f;
			map.content[y][x].z = (float)int_map->content[y][x];
		}
	}
	map.height = int_map->height;
	map.width = int_map->width;
	return (map);
}

void	free_int_map(t_int_map int_map)
{
	size_t	i;

	i = 0;
	while (i < int_map.height)
	{
		free(int_map.content[i]);
		i++;
	}
	free(int_map.content);
}

t_map	parsing_full(const char *file)
{
	int			fd;
	t_list		*linked_text;
	t_int_map	int_map;
	t_map		map;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error: file not found\n");
		exit(0);
	}
	linked_text = put_file_in_list(fd);
	close(fd);
	linked_to_array(*linked_text, &int_map);
	ft_lstclear(&linked_text, free);
	map = get_t_map(&int_map);
	free_int_map(int_map);
	return (map);
}
