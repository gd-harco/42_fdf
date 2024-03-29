/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct_calc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:30:00 by gd-harco          #+#    #+#             */
/*   Updated: 2023/01/26 12:02:41 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//Prototype

static t_matrix	get_projection_matrix(void);

//Function body

// Initialize and fill the world info
t_projection_info	fill_projection_info(void)
{
	t_projection_info	projection;

	projection.fov = 90.0f;
	projection.near = 0.1f;
	projection.far = 1000.0f;
	projection.aspect_ratio = (float)HEIGHT / (float)WIDTH;
	projection.fov_rad = 1.0f
		/ tanf(projection.fov * 0.5f / 180.0f * 3.14159f);
	projection.projection_matrix = get_projection_matrix();
	projection.projection_matrix.mat4x4[0][0]
		= projection.aspect_ratio * projection.fov_rad;
	projection.projection_matrix.mat4x4[1][1] = projection.fov_rad;
	projection.projection_matrix.mat4x4[2][2] = projection.far
		/ (projection.far - projection.near);
	projection.projection_matrix.mat4x4[2][3] = 1.0f;
	projection.projection_matrix.mat4x4[3][2] = (-projection.far
			* projection.near) / (projection.far - projection.near);
	projection.projection_matrix.mat4x4[3][3] = 0.0f;
	return (projection);
}

void	get_map_to_draw(t_vector_map *map,
						t_projection_info *projection_info)
{
	size_t	x;
	size_t	y;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		map->map_to_draw[y] = malloc(sizeof(t_vector3d) * map->width);
		while (++x < map->width)
		{
			map->map[y][x].z -= 5.0f;
			map->map_to_draw[y][x] = multiply_matrix_vector(
					projection_info->projection_matrix, map->map[y][x]);
			map->map_to_draw[y][x].x = (map->map_to_draw[y][x].x + 1.0f)
				* (float)WIDTH / 2.0f + 0.5f;
			map->map_to_draw[y][x].y = (map->map_to_draw[y][x].y + 1.0f)
				* (float)HEIGHT / 2.0f + 0.5f;
		}
	}
}

// Initialize the projection matrix with 0
static t_matrix	get_projection_matrix(void)
{
	t_matrix	matrix_projection;

	ft_bzero(&matrix_projection, sizeof(t_matrix));
	return (matrix_projection);
}
