/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:11:07 by gd-harco          #+#    #+#             */
/*   Updated: 2023/01/02 19:59:10 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/graphics.h"
#include ".././includes/drawing.h"

void	my_mlx_pixel_put(t_data *data, float x, float y, int color)
{
	char	*dst;
	int		int_x;
	int		int_y;

	int_x = (int)x;
	int_y = (int)y;
	dst = data->addr + (int_y * data->line_length + int_x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

t_line	get_line_start(t_vec3d p1, t_vec3d p2) {
	t_line result;

	if (p1.x > p2.x) {
		result.l_start = p2;
		result.l_end = p1;
	} else {
		result.l_start = p1;
		result.l_end = p2;
	}
	result.slope = fabsf((result.l_end.y - result.l_start.y) / (result.l_end.x - result.l_start.x));
	return (result);
}

	void graphics_init(t_map *map)
	{
		void *mlx;
		void *mlx_win;
		t_data img;
		t_projection_info proj;
		t_mat matrix;
		t_vec3d p1;
		t_vec3d p2;
		t_line line;

		(void) map;
		p1.x = SIZE_X - 1;
		p1.y = SIZE_Y - 1;
		p2.x = 0;
		p2.y = 0;
		mlx = mlx_init();
		mlx_win = mlx_new_window(mlx, SIZE_X, SIZE_Y, "FDF");
		img.img = mlx_new_image(mlx, SIZE_X, SIZE_Y);
		img.addr = mlx_get_data_addr(img.img, (int *)(&img.bits_per_pixel), &img.line_length, &img.endian);
		fill_info_struct(&proj);
		fill_mat_struct(&matrix, &proj);
		line = get_line_start(p1, p2);
		draw_line(&img, line);
		mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
		mlx_loop(mlx);
	}