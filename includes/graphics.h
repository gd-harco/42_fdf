/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:23:00 by gd-harco          #+#    #+#             */
/*   Updated: 2023/01/06 16:23:00 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H
# include "mlx.h"
# define SIZE_X 1280
# define SIZE_Y 720
# include <fcntl.h>
# ifndef FDF_H
#  include "../includes/fdf.h"
# endif
# include <math.h>

typedef struct s_projection_info
{
	float	f_near;
	float	f_far;
	float	f_fov;
	float	f_aspect;
	float	f_fov_rad;
}	t_projection_info;

typedef struct s_mat
{
	float	m[4][4];
}				t_mat;

typedef struct s_vec3d
{
	float	x;
	float	y;
	float	z;
}				t_vec3d;

typedef struct s_line
{
	t_vec3d	l_start;
	t_vec3d	l_end;
	float 	slope;
}				t_line;

typedef struct s_map
{
	size_t	width;
	size_t	height;
	t_vec3d	**content;
	t_vec3d	**content_display;
}	t_map;

void	graphics_init(t_map *map);
void	graphics_test(void);
void	fill_projection_struct(t_projection_info *projection);
void	fill_mat_struct(t_mat	*mat, t_projection_info *projection);
t_vec3d	multiply_vec_mat(t_vec3d *input_vec, t_mat *mat);
#endif
