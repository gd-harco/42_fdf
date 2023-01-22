/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:10:00 by gd-harco          #+#    #+#             */
/*   Updated: 2023/01/21 15:47:45 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_image_info *data, int x, int y, int color)
{
	char	*dst;
		
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned	int*)dst = color;
}
