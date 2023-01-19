/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:30:00 by gd-harco          #+#    #+#             */
/*   Updated: 2023/01/19 13:30:00 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_int_map
{
	int		**map;
	size_t	width;
	size_t	height;
}				t_int_map;

typedef struct s_vector3d
{
	float	x;
	float	y;
	float	z;
}				t_vector3d;

typedef struct s_vector_map
{
	t_vector3d	**map;
	size_t		width;
	size_t		height;
}				t_vector_map;

#endif
