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
	size_t	c_height;
	size_t	c_width;

	c_width = -1;
	while (++c_width < int_map->width)
	{
		v_map->map[c_width] = malloc(sizeof(t_vector3d) * int_map->width);
		c_height = -1;
		while (++c_height < int_map->height)
		{
			v_map->map[c_width][c_height].y = (float)c_width;
			v_map->map[c_width][c_height].x = (float)c_height;
			//TODO fix this, cause a sigabort
			v_map->map[c_width][c_height].z
				= (float)int_map->map[c_width][c_height];
		}
	}
}
