/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:09:00 by gd-harco          #+#    #+#             */
/*   Updated: 2023/01/22 21:15:43 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H
# include "fdf.h"

void				graphic_launch(t_vector_map vector_map);
t_projection_info	fill_projection_info(void);
void				get_map_to_draw(t_vector_map *vector_map,
						t_projection_info *projection_info);

//line_drawing.c
void				go_up(float *e, float slope, float *y_pos);
void				go_down(float *e, float slope, float *y_pos);


#endif
