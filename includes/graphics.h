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
#if defined(__APPLE__)
#  include "../lib/mlx/macos/mlx.h"
# endif
# if defined(__linux__)
#  include <mlx.h>
# endif
# ifndef SIZE_X
#  define SIZE_X 1280
# endif
# ifndef SIZE_Y
#  define SIZE_Y 720
# endif
# include <fcntl.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


#endif
