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


void draw_line(t_data *data, t_line to_draw)
{
	float	e;
	float	m;
	t_vec3d current_pos;

	m = to_draw.slope;
	e = 0;

	current_pos.x = to_draw.l_start.x;
	current_pos.y = to_draw.l_start.y;
	while (current_pos.x < to_draw.l_end.x)
	{
		my_mlx_pixel_put(data, current_pos.x, current_pos.y, 0x00FFFFFF);
		e -= m;
		if (e < 0.5)
		{
			current_pos.y--;
			e += 1;
		}
		current_pos.x++;
	}
}
