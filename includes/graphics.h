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
# ifndef SIZE_X
#  define SIZE_X 1280
# endif
# ifndef SIZE_Y
#  define SIZE_Y 720
# endif
# include <fcntl.h>
# ifndef FDF_H
#  include "../includes/fdf.h"
# endif
# include <math.h>

typedef struct s_projection_info{
	float	f_near;
	float	f_far;
	float	f_fov;
	float	f_aspect;
	float	f_fov_rad;
}	t_projection_info;

typedef struct s_mat{
	float	m[4][4];
}				t_mat;

typedef struct s_vec3d {
	float	x;
	float	y;
	float	z;
}				t_vec3d;

typedef struct s_vec2d {
	float 	x;
	float 	y;
}				t_vec2d;

void	graphics_init(t_map *map);
void	graphics_test(void);
void	fill_info_struct(t_projection_info *proj);
void	fill_mat_struct(t_mat	*mat, t_projection_info *projection);

#endif
