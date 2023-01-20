/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_to_vector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:39:00 by gd-harco          #+#    #+#             */
/*   Updated: 2023/01/20 00:21:55 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	int_map_to_v_map(t_int_map *int_map, t_vector_map *v_map)
{
	size_t	y;
	size_t	x;

	y = -1;
	while (++y < int_map->height)
	{
		v_map->map[y] = malloc(sizeof(t_vector3d) * int_map->width);
		if (!v_map->map[y])
			exit(1);
		x = -1;
		while (++x < int_map->width)
		{
			v_map->map[y][x].y = (float)y;
			v_map->map[y][x].x = (float)x;
			v_map->map[y][x].z = (float)int_map->map[y][x];
		}
	}
}
