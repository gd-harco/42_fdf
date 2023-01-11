/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:47:00 by gd-harco          #+#    #+#             */
/*   Updated: 2023/01/11 15:47:00 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/drawing.h"

//We draw lines from left to right.
//x1 < x2 and y1< y2
//		Slope of the line is between 0 and 1. We draw a line from lower left to upper right.

//Bresenham's line algorithm
void	draw_line(t_data *data, t_vec2d p1, t_vec2d p2)
{
	float	x_start;
	float	y_start;
	float	x_end;
	float	y_end;
	float	m;

	m = (y_end - y_start) / (x_end - x_start);

}
