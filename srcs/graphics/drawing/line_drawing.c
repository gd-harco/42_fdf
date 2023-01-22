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

void	go_up(float *e, float slope, float *y_pos)
{
	*e -= slope;
	if (*e < 0.5)
	{
			*y_pos--;
			*e += 1;
	}
}

void	go_down(float	*e, float slope, float *y_pos)
{
	*e += slope;
	if (*e > 0.5f)
	{
		*y_pos++;
		*e -= 1;
	}
}
