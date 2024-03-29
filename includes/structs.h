/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:30:00 by gd-harco          #+#    #+#             */
/*   Updated: 2023/01/26 17:18:07 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_vector3d	t_vector3d;

// Structs require for the parsing
typedef struct s_int_map
{
	int		**map;
	size_t	width;
	size_t	height;
}				t_int_map;

// Structs containing info required for the projection
typedef struct s_matrix
{
	float	mat4x4[4][4];
}			t_matrix;

typedef struct s_projection_info
{
	float		fov;
	float		near;
	float		far;
	float		aspect_ratio;
	float		fov_rad;
	t_matrix	projection_matrix;
}						t_projection_info;

// Struct containing all information of the worlds in the 3D space
typedef struct s_vector_map
{
	size_t		width;
	size_t		height;
	t_vector3d	**map;
	t_vector3d	**map_to_draw;
}				t_vector_map;

struct s_vector3d
{
	float	x;
	float	y;
	float	z;
	float	w;
};

typedef struct s_line
{
	t_vector3d	*start;
	t_vector3d	*end;
	float		slope;
}				t_line;

// Structs require for the mlx, the window and the image

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}			t_mlx;

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_fdf
{
	t_mlx		*mlx;
	t_img		*img;
	t_vector3d	map;
	t-matrices	matrices;
}

#endif
