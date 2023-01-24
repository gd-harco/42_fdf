/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:10:00 by gd-harco          #+#    #+#             */
/*   Updated: 2023/01/22 21:26:27 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//Prototype
static t_line	get_line_start(t_vector3d *p1, t_vector3d *p2);
static void		my_mlx_pixel_put(t_image_info *data, int x, int y, int color);
static void		draw_sloped_line(t_image_info *data, t_line to_draw);
static void		draw_straight_line(t_image_info *data, t_line to_draw, char c);

//Function body
void	draw_line(t_image_info *data, t_vector3d p1, t_vector3d p2)
{
	t_line	to_draw;

	to_draw = get_line_start(&p1, &p2);
	if (to_draw.start->x == to_draw.end->x)
		draw_straight_line(data, to_draw, 'v');
	else if (to_draw.start->y == to_draw.end->y)
		draw_straight_line(data, to_draw, 'h');
	else
		draw_sloped_line(data, to_draw);
}

static void	my_mlx_pixel_put(t_image_info *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length
			+ x * (data->bits_per_pixel / 8));
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	*(unsigned int *)dst = color;
}

static void	draw_sloped_line(t_image_info *data, t_line to_draw)
{
	float		e;
	t_vector3d	pos;

	e = 0;
	pos.x = to_draw.start->x - 1;
	pos.y = to_draw.start->y;
	while (++pos.x < to_draw.end->x)
	{
		if ((pos.x >= 0 && pos.y >= 0)
			&& (pos.x < HEIGHT && pos.y < WIDTH))
			my_mlx_pixel_put(data, (int)pos.x, (int)pos.y, 0x00FFFFFF);
		if (to_draw.start->y < to_draw.end->y)
			go_up(&e, &to_draw, &pos);
		else
			go_down(&e, &to_draw, &pos);
	}
}

static void	draw_straight_line(t_image_info *data, t_line to_draw, char c)
{
	t_vector3d	current_pos;

	current_pos.x = to_draw.start->x - 1;
	current_pos.y = to_draw.start->y;
	if (c == 'h')
	{
		while (++current_pos.x < to_draw.end->x)
		{
			if ((current_pos.x >= 0 && current_pos.y >= 0)
				&& (current_pos.x < WIDTH && current_pos.y < HEIGHT))
				my_mlx_pixel_put(
					data, (int)current_pos.x, (int)current_pos.y, 0x00FFFFFF);
		}
	}
	else
	{
		while (current_pos.y < to_draw.end->y)
		{
			if ((current_pos.x >= 0 && current_pos.y >= 0)
				&& (current_pos.x < WIDTH && current_pos.y < HEIGHT))
				my_mlx_pixel_put(
					data, (int)current_pos.x, (int)current_pos.y, 0x00FFFFFF);
			current_pos.y++;
		}
	}
}

static t_line	get_line_start(t_vector3d *p1, t_vector3d *p2)
{
	t_line	result;

	if (p1->x > p2->x)
	{
		result.start = p2;
		result.end = p1;
	}
	else
	{
		result.start = p1;
		result.end = p2;
	}
	result.slope = fabsf((result.end->y - result.start->y)
			/ (result.end->x - result.start->x));
	return (result);
}
