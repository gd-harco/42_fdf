/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:03:00 by gd-harco          #+#    #+#             */
/*   Updated: 2023/01/16 15:03:00 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/line_drawing.h"

void draw_all_line(t_map *map, t_data *data)
{
	size_t	y;
	size_t	x;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (x + 1 < map->width)
				draw_line(data, map->content_display[y][x], map->content_display[y][x + 1]);
			if (y + 1 < map->height)
				draw_line(data, map->content_display[y][x], map->content_display[y + 1][x]);
		}
	}
}
