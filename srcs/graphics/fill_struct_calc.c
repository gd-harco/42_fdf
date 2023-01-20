/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_projection_matrix.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:30:00 by gd-harco          #+#    #+#             */
/*   Updated: 2023/01/20 11:30:00 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vector3d	multiply_matrix_vector(t_projection_matrix matrix,
		t_vector3d vector)
{
	t_vector3d	result;

	result.x = vector.x
	return (result);
}

void	get_map_to_draw(t_vector_map *vector_map, t_projection_info *projection_info)
{
	size_t	x;
	size_t	y;

	y = -1;
	while (++y < vector_map->height)
	{
		x = -1;
		while (++x < vector_map->width)
		{
			vector_map->map_to_draw[y][x] = multiply_matrix_vector
				(projection_info->projection_matrix, vector_map->map[y][x]);
		}
	}
}

// Initialize and fill the world info
t_projection_info fill_projection_info(void)
{
	t_projection_info	*projection;

	projection = malloc(sizeof(t_projection_info));
	projection->fov = 90.0f;
	projection->near = 0.1f;
	projection->far = 1000.0f;
	projection->aspect_ratio = (float)WIDTH / (float)HEIGHT;
	projection->fov_rad = 1.0f / tanf(projection->fov * 0.5f / 180.0f * 3.14159f);
	projection->projection_matrix = get_projection_matrix();
	projection->projection_matrix.mat4x4[0][0]
		= projection->aspect_ratio * projection->fov_rad;
	projection->projection_matrix.mat4x4[1][1] = tanf(projection->fov / 2);
	projection->projection_matrix.mat4x4[2][2] = projection->fov_rad;
	projection->projection_matrix.mat4x4[2][3] = 1.0f;
	projection->projection_matrix.mat4x4[3][2] = (-projection->far
			* projection->near) / (projection->far - projection->near);
	return (*projection);
}

// Initialize the projection matrix with 0
t_projection_matrix	get_projection_matrix(void)
{
	t_projection_matrix	matrix_projection;
	int					x;
	int					y;

	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
		{
			matrix_projection.mat4x4[y][x] = 0.0f;
		}
	}
	return (matrix_projection);
}
