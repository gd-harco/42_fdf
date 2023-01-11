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

//TODO: remove this function
#include <stdio.h>
void	print_mat(t_mat *mat)
{
	int	x;
	int	y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			printf("%f ", mat->m[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
}

//fill the projection_info matrix
void	fill_info_struct(t_projection_info *proj)
{
	proj->f_near = 0.1;
	proj->f_far = 1000.0 ;
	proj->f_fov = 90.0;
	proj->f_aspect = (float)SIZE_X / (float)SIZE_Y;
	proj->f_fov_rad = 1.0 / tanf(proj->f_fov * 0.5 / 180.0 * 3.14159);
}

//fill the mat matrix with 0, then add the required data at the right place using the projection_info matrix
void	fill_mat_struct(t_mat	*mat, t_projection_info *projection)
{
	int	x;
	int y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
			mat->m[y][x++] = 0;
		y++;
	}
	//TODO remove print_mat usage
	print_mat(mat);
	mat->m[0][0] = projection->f_aspect * projection->f_fov_rad;
	mat->m[1][1] = projection->f_fov_rad;
	mat->m[2][2] = projection->f_far/(projection->f_far - projection->f_near);
	mat->m[3][2] = (-projection->f_far * projection->f_near) / (projection->f_far - projection->f_near);
	mat->m[2][3] = 1.0;
	mat->m[3][3] = 0.0;
	printf("\n\n");
	print_mat(mat);
}

//multiply the 3d point vector by the mat matrix
t_vec3d	multiply_vec_mat(t_vec3d *input_vec, t_mat *mat)
{
	t_vec3d	output_vec;
	float	w;

	output_vec.x = input_vec->x * mat->m[0][0] + input_vec->y * mat->m[1][0] + input_vec->z * mat->m[2][0] + mat->m[3][0];
	output_vec.y = input_vec->x * mat->m[0][1] + input_vec->y * mat->m[1][1] + input_vec->z * mat->m[2][1] + mat->m[3][1];
	output_vec.z = input_vec->x * mat->m[0][2] + input_vec->y * mat->m[1][2] + input_vec->z * mat->m[2][2] + mat->m[3][2];
	w = input_vec->x * mat->m[0][3] + input_vec->y * mat->m[1][3] + input_vec->z * mat->m[2][3] + mat->m[3][3];
	if (w != 0)
	{
		output_vec.x /= w;
		output_vec.y /= w;
		output_vec.z /= w;
	}
	return (output_vec);
}
