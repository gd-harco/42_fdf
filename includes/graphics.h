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

void	graphics_test(void);
typedef struct s_mat4x4{
	float	m[4][4];
}				t_mat4x4;

#endif
