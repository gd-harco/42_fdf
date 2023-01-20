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

static t_vector3d			multiply_matrix_vector(
								t_projection_matrix matrix, t_vector3d vector);
static t_projection_matrix	get_projection_matrix(void);

// Initialize and fill the world info
t_projection_info	fill_projection_info(void)
{
	t_projection_info	projection;

	projection.fov = 90.0f;
	projection.near = 0.1f;
	projection.far = 1000.0f;
	projection.aspect_ratio = (float)WIDTH / (float)HEIGHT;
	projection.fov_rad = 1.0f
		/ tanf(projection.fov * 0.5f / 180.0f * 3.14159f);
	projection.projection_matrix = get_projection_matrix();
	projection.projection_matrix.mat4x4[0][0]
		= projection.aspect_ratio * projection.fov_rad;
	projection.projection_matrix.mat4x4[1][1] = tanf(projection.fov / 2);
	projection.projection_matrix.mat4x4[2][2] = projection.fov_rad;
	projection.projection_matrix.mat4x4[2][3] = 1.0f;
	projection.projection_matrix.mat4x4[3][2] = (-projection.far
			* projection.near) / (projection.far - projection.near);
	return (projection);
}

void	get_map_to_draw(t_vector_map *vector_map,
						t_projection_info *projection_info)
{
	size_t	x;
	size_t	y;

	y = -1;
	while (++y < vector_map->height)
	{
		x = -1;
		while (++x < vector_map->width)
		{
			vector_map->map_to_draw[y][x] = multiply_matrix_vector(
					projection_info->projection_matrix, vector_map->map[y][x]);
		}
	}
}

static t_vector3d	multiply_matrix_vector(t_projection_matrix matrix,
		t_vector3d vector)
{
	t_vector3d	result;
	float		w;

	result.x = vector.x * matrix.mat4x4[0][0] + vector.y * matrix.mat4x4[1][0]
		+ vector.z * matrix.mat4x4[2][0] + matrix.mat4x4[3][0];
	result.y = vector.x * matrix.mat4x4[0][1] + vector.y * matrix.mat4x4[1][1]
		+ vector.z * matrix.mat4x4[2][1] + matrix.mat4x4[3][1];
	result.x = vector.x * matrix.mat4x4[0][2] + vector.y * matrix.mat4x4[1][2]
		+ vector.z * matrix.mat4x4[2][2] + matrix.mat4x4[3][2];
	w = vector.x * matrix.mat4x4[0][3] + vector.y * matrix.mat4x4[1][3]
		+ vector.z * matrix.mat4x4[2][3] + matrix.mat4x4[3][3];
	if (w != 0)
	{
		result.x /= w;
		result.y /= w;
		result.z /= w;
	}
	return (result);
}

// Initialize the projection matrix with 0
static t_projection_matrix	get_projection_matrix(void)
{
	t_projection_matrix	matrix_projection;

	ft_bzero(&matrix_projection, sizeof(t_projection_matrix));
	return (matrix_projection);
}
