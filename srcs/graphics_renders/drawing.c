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


void draw_line(t_data *data, t_vec3d p1, t_vec3d p2)
{
	float	e;
	float	m;
	t_vec3d current_pos;

	m = fabsf((p2.y - p1.y)) / fabsf((p2.x - p1.x));
	e = 0;

	current_pos.x = p1.l_start.x;
	current_pos.y = p1.l_start.y;
	while (current_pos.x < p1.l_end.x)
	{
		my_mlx_pixel_put(data, current_pos.x, current_pos.y, 0x00FFFFFF);
		e -= p1.slope;
		if (e < 0.5)
		{
			current_pos.y--;
			e += 1;
		}
		current_pos.x++;
	}
}
