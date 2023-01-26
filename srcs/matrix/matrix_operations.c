/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:52:19 by gd-harco          #+#    #+#             */
/*   Updated: 2023/01/26 14:21:25 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vector3d	multiply_matrix_vector(t_matrix matrix,
		t_vector3d vector)
{
	t_vector3d	result;

	result.x = vector.x * matrix.mat4x4[0][0] + vector.y * matrix.mat4x4[1][0]
		+ vector.z * matrix.mat4x4[2][0] + vector.w * matrix.mat4x4[3][0];
	result.y = vector.x * matrix.mat4x4[0][1] + vector.y * matrix.mat4x4[1][1]
		+ vector.z * matrix.mat4x4[2][1] + vector.w * matrix.mat4x4[3][1];
	result.x = vector.x * matrix.mat4x4[0][2] + vector.y * matrix.mat4x4[1][2]
		+ vector.z * matrix.mat4x4[2][2] + vector.w * matrix.mat4x4[3][2];
	result.w = vector.x * matrix.mat4x4[0][3] + vector.y * matrix.mat4x4[1][3]
		+ vector.z * matrix.mat4x4[2][3] + vector.w * matrix.mat4x4[3][3];
	return (result);
}

t_matrix	m_make_identity(void)
{
	t_matrix	matrix;

	matrix.mat4x4[0][0] = 1.0f;
	matrix.mat4x4[1][1] = 1.0f;
	matrix.mat4x4[2][2] = 1.0f;
	matrix.mat4x4[3][3] = 1.0f;
	return (matrix);
}

t_matrix	m_make_rotation_x(float angle)
{
	t_matrix	matrix;

	matrix = m_make_identity();
	matrix.mat4x4[1][1] = cosf(angle);
	matrix.mat4x4[1][2] = sinf(angle);
	matrix.mat4x4[2][1] = -sinf(angle);
	matrix.mat4x4[2][2] = cosf(angle);
	return (matrix);
}

t_matrix	m_make_rotation_y(float angle)
{
	t_matrix	matrix;

	matrix.mat4x4[0][0] = cosf(angle);
	matrix.mat4x4[0][2] = sinf(angle);
	matrix.mat4x4[2][0] = -sinf(angle);
	matrix.mat4x4[1][1] = 1.0f;
	matrix.mat4x4[2][2] = cosf(angle);
	matrix.mat4x4[3][3] = 1.0f;
	return (matrix);
}

t_matrix	m_make_rotation_z(float angle)
{
	t_matrix	matrix;

	matrix.mat4x4[0][0] = cosf(angle);
	matrix.mat4x4[0][1] = sinf(angle);
	matrix.mat4x4[1][0] = -sinf(angle);
	matrix.mat4x4[1][1] = cosf(angle);
	matrix.mat4x4[2][2] = 1.0f;
	matrix.mat4x4[3][3] = 1.0f;
	return (matrix);
}
