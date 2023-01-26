/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:23:22 by gd-harco          #+#    #+#             */
/*   Updated: 2023/01/26 15:53:40 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrix	m_make_translation(float x, float y, float z)
{
	t_matrix	matrix;

	matrix = m_make_identity();
	matrix.mat4x4[3][0] = x;
	matrix.mat4x4[3][1] = y;
	matrix.mat4x4[3][2] = z;
	return (matrix);
}

t_matrix	multiply_matrix_matrix(t_matrix m1, t_matrix m2)
{
	t_matrix	matrix;
	int			column;
	int			row;

	column = -1;
	row = -1;
	while (++row < 4)
		while (++column < 4)
			matrix.mat4x4[row][column]
				= m1.mat4x4[row][0] * m2.mat4x4[0][column]
				+ m1.mat4x4[row][1] * m2.mat4x4[1][column]
				+ m1.mat4x4[row][2] * m2.mat4x4[2][column]
				+ m1.mat4x4[row][3] * m2.mat4x4[3][column];
	return (matrix);
}
