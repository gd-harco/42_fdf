/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_drawing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:56:55 by gd-harco          #+#    #+#             */
/*   Updated: 2023/01/22 21:21:05 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	go_up(float *e, t_line *to_draw, t_vector3d *current_pos)
{
	float	m;

	m = to_draw->slope;
	*e -= m;
	if (*e < 0.5)
	{
			current_pos->y--;
			*e += 1;
	}
}

void	go_down(float *e, t_line *to_draw, t_vector3d *current_position)
{
	*e += to_draw->slope;
	if (*e > 0.5f)
	{
		current_position->y++;
		*e -= 1;
	}
}
