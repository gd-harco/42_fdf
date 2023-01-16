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

#include <printf.h>
#include "../../includes/drawing.h"


void draw_line_upward(t_data *data, t_line to_draw)
{
	float e;
	float m;

	t_vec3d current_pos;
	m = to_draw.slope;
	e = 0;
	current_pos.x = to_draw.l_start.x;
	current_pos.y = to_draw.l_start.y;
	while (current_pos.x < to_draw.l_end.x)
	{
		my_mlx_pixel_put(data, current_pos.x, current_pos.y, 0x00FFFFFF);
		e += m;
		printf("e = %f \n", e);
		if (e > 0.5) {
			current_pos.y++;
			e -= 1;
		}
		current_pos.x++;
	}
}

void draw_line_downward(t_data *data, t_line to_draw)
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
		printf("e = %f \n", e);
		if (e < 0.5)
		{
			current_pos.y--;
			e += 1;
		}
		current_pos.x++;
	}
}

void draw_line_horizontal(t_data *data, t_line to_draw)
{
	t_vec3d current_pos;
	current_pos.x = to_draw.l_start.x;
	current_pos.y = to_draw.l_start.y;
	while (current_pos.x < to_draw.l_end.x)
	{
		my_mlx_pixel_put(data, current_pos.x, current_pos.y, 0x00FFFFFF);
		current_pos.x++;
	}
}

void draw_line_vertical(t_data *data, t_line to_draw)
{
	t_vec3d current_pos;
	current_pos.x = to_draw.l_start.x;
	current_pos.y = to_draw.l_start.y;
	while (current_pos.y < to_draw.l_end.y)
	{
		my_mlx_pixel_put(data, current_pos.x, current_pos.y, 0x00FFFFFF);
		current_pos.y++;
	}
}

void draw_line(t_data *data, t_line to_draw)
{
	if (to_draw.l_start.x == to_draw.l_end.x)
		draw_line_vertical(data, to_draw);
	else if (to_draw.l_start.y == to_draw.l_end.y)
		draw_line_horizontal(data, to_draw);
	else if (to_draw.l_start.y > to_draw.l_end.y)
		draw_line_downward(data, to_draw);
	else
		draw_line_upward(data, to_draw);
}
