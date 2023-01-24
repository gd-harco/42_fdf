/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:09:00 by gd-harco          #+#    #+#             */
/*   Updated: 2023/01/20 00:14:01 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <printf.h>

static void	draw_map(t_vector_map vector_map, t_image_info *img_info);

void	graphic_launch(t_vector_map vector_map)
{
	t_mlx_info			mlx;
	t_image_info		main_window;
	t_projection_info	projection_info;

	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, WIDTH, HEIGHT, "fdf");
	main_window.img_ptr = mlx_new_image(mlx.mlx_ptr, WIDTH, HEIGHT);
	main_window.addr = mlx_get_data_addr(main_window.img_ptr,
			&main_window.bits_per_pixel, &main_window.line_length,
			&main_window.endian);
	projection_info = fill_projection_info();
	get_map_to_draw(&vector_map, &projection_info);
	ft_printf("map calculated\n");
	draw_map(vector_map, &main_window);
	mlx_put_image_to_window(
		mlx.mlx_ptr, mlx.win_ptr, main_window.img_ptr, 0, 0);
	mlx_loop(mlx.mlx_ptr);
}

static void	draw_map(t_vector_map vector_map, t_image_info *img_info)
{
	size_t	y;
	size_t	x;

	y = -1;
	while (++y < vector_map.height)
	{
		x = -1;
		while (++x < vector_map.width)
		{
			if (x + 1 < vector_map.width)
			{
				draw_line(img_info, vector_map.map_to_draw[y][x],
					vector_map.map_to_draw[y][x + 1]);
				ft_printf("drawed line %d - %d\n", y, x);
			}
			if (y + 1 < vector_map.height)
				draw_line(img_info, vector_map.map_to_draw[y][x],
					vector_map.map_to_draw[y + 1][x]);
		}
	}
}
