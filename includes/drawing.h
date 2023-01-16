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

void	my_mlx_pixel_put(t_data *data, float x, float y, int color);
void draw_line_upward(t_data *data, t_line to_draw);
void draw_line_downward(t_data *data, t_line to_draw);
void draw_line(t_data *data, t_line to_draw);



#endif
