/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_info_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:44:00 by gd-harco          #+#    #+#             */
/*   Updated: 2023/01/11 12:44:00 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/graphics.h"

//fill the projection_info matrix
void	fill_projection_struct(t_projection_info *projection)
{
	projection->f_near = 0.1f;
	projection->f_far = 1000.0f;
	projection->f_fov = 90.0f;
	projection->f_aspect = (float)SIZE_X / (float)SIZE_Y;
	projection->f_fov_rad = 1.0f / tanf(projection->f_fov
			* 0.5f / 180.0f * 3.14159f);
}

//fill the mat matrix with 0, then add the required data
// at the right place using the projection_info matrix
void	fill_mat_struct(t_mat *mat, t_mat *trans_matrix, t_projection_info *projection)
{
	int	x;
	int	y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			mat->m[y][x++] = 0;
			trans_matrix->m[y][x++] = 0;
		}
		y++;
	}
	mat->m[0][0] = projection->f_aspect * projection->f_fov_rad;
	trans_matrix->m[0][0] = 1;
	mat->m[1][1] = projection->f_fov_rad;
	trans_matrix->m[1][1] = 1;
	mat->m[2][2] = projection->f_far / (projection->f_far - projection->f_near);
	trans_matrix->m[2][2] = 1;
	mat->m[3][2] = (-projection->f_far * projection->f_near)
		/ (projection->f_far - projection->f_near);
	trans_matrix->m[3][2] = POS_Z;
	mat->m[2][3] = 1.0f;
	mat->m[3][3] = 0.0f;
}

//multiply the 3d point vector by the mat matrix
t_3dpoint	multiply_vec_mat(t_3dpoint *input_vec, t_mat *mat)
{
	t_3dpoint	output_vec;
	float		w;

	output_vec.x = input_vec->x * mat->m[0][0] + input_vec->y * mat->m[1][0]
		+ input_vec->z * mat->m[2][0] + mat->m[3][0];
	output_vec.y = input_vec->x * mat->m[0][1] + input_vec->y * mat->m[1][1]
		+ input_vec->z * mat->m[2][1] + mat->m[3][1];
	output_vec.z = input_vec->x * mat->m[0][2] + input_vec->y * mat->m[1][2]
		+ input_vec->z * mat->m[2][2] + mat->m[3][2];
	w = input_vec->x * mat->m[0][3] + input_vec->y * mat->m[1][3]
		+ input_vec->z * mat->m[2][3] + mat->m[3][3];
	if (w != 0)
	{
		output_vec.x /= w;
		output_vec.y /= w;
		output_vec.z /= w;
	}
	return (output_vec);
}
