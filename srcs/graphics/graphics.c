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

void	graphic_launch(t_vector_map vector_map)
{
	t_mlx_info			mlx;
	t_image_info		main_window;
	t_projection_info	projection_info;

	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, WIDTH, HEIGHT, "fdf");
	main_window.img_ptr = mlx_new_image(mlx.mlx_ptr, WIDTH, HEIGHT);
	main_window.addr = mlx_get_data_addr(mlx.mlx_ptr,
			&main_window.bits_per_pixel, &main_window.line_length,
			&main_window.endian);
	projection_info = fill_projection_info();
	get_map_to_draw(&vector_map, &projection_info);
	(void)vector_map;
	mlx_loop(mlx.mlx_ptr);
}
