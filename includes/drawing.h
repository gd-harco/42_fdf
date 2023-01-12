/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:47:00 by gd-harco          #+#    #+#             */
/*   Updated: 2023/01/11 15:47:00 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAWING_H
# define DRAWING_H
# ifndef FDF_H
#  include "../includes/fdf.h"
# endif
# ifndef GRAPHICS_H
#  include "../includes/graphics.h"
# endif

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void draw_line(t_data *data, t_vec3d p1, t_vec3d p2);


#endif
