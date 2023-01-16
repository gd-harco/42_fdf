/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:08:01 by gd-harco          #+#    #+#             */
/*   Updated: 2022/12/18 16:19:21 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"
#include <fcntl.h>
#include "line_drawing.h"


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
			ft_printf("%d ", map.content[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

t_map	get_t_map(t_int_map *int_map)
{
	t_map	map;
	t_vec3d	**vec_map;
	t_vec3d	**vec_map_display;
	size_t	x;
	size_t	y;

	vec_map = malloc(sizeof(t_vec3d *) * int_map->height);
	vec_map_display = malloc(sizeof(t_vec3d *) * int_map->height);
	y = -1;
	while (++y < int_map->height)
	{
		vec_map[y] = malloc(sizeof(t_vec3d) * int_map->width);
		vec_map_display[y] = malloc(sizeof(t_vec3d) * int_map->width);
		x = -1;
		while (++x < int_map->width)
		{
			vec_map[y][x].y = y;
			vec_map[y][x].x = x;
			vec_map[y][x].z = int_map->content[y][x];
		}
	}
	map.height = int_map->height;
	map.width = int_map->width;
	map.content = vec_map;
	return (map);
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
	return (map);
}
