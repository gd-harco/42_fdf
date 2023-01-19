/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:11:07 by gd-harco          #+#    #+#             */
/*   Updated: 2023/01/16 17:44:22 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
#include "../../includes/graphics.h"
#include ".././includes/line_drawing.h"

void	my_mlx_pixel_put(t_data *data, float x, float y, int color)
{
	char	*dst;
	int		int_x;
	int		int_y;

	int_x = (int)x;
	int_y = (int)y;
	dst = data->addr + (int_y * data->line_length
			+ int_x * (data->bits_per_pixel / 8));
	if (int_x < 0 || int_x >= SIZE_X || int_y < 0 || int_y >= SIZE_Y)
		return ;
	*(unsigned int *)dst = color;
}

t_line	get_line_start(t_3dpoint p1, t_3dpoint p2)
{
	t_line	result;

	if (p1.x > p2.x)
	{
		result.l_start = p2;
		result.l_end = p1;
	}
	else
	{
		result.l_start = p1;
		result.l_end = p2;
	}
	result.slope = fabsf((result.l_end.y - result.l_start.y)
			/ (result.l_end.x - result.l_start.x));
	return (result);
}

void	apply_matrix(t_map *map, t_mat *proj_matrix, t_mat *trans_matrix)
{
	size_t	y;
	size_t	x;

	(void)trans_matrix;
	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			map->content_display[y][x]
				= multiply_vec_mat(&map->content[y][x], proj_matrix);
//				map->content_display[y][x] = vector_divide(&map->content_display[y][x],
//					map->content_display[y][x].w);
			map->content_display[y][x].x = (map->content_display[y][x].x + 1.0f)
				* (float)SIZE_X / 2.0f + 0.5f;
			map->content_display[y][x].y = (map->content_display[y][x].y + 1.0f)
				* (float)SIZE_Y / 2.0f + 0.5f;
		}
	}
}

//TODO remove this and its usage
void print_matrix(t_mat *mat) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%.2f ", mat->m[i][j]);
		}
		printf("\n");
	}
}

//TODO remove this and it's usage
void print_map_content(t_map *map) {
	for (size_t i = 0; i < map->height; i++) {
		for (size_t j = 0; j < map->width; j++) {
			printf("%.2f %.2f %.2f\n", map->content[i][j].x, map->content[i][j].y, map->content[i][j].z);
		}
	}
}

void	graphics_init(t_map *map)
{
	t_mlx_info			mlx_info;
	t_data				img;
	t_projection_info	projection_info;
	t_mat				matrix;
	t_mat				trans_matrix;

	mlx_info.mlx = mlx_init();
	mlx_info.mlx_win = mlx_new_window(mlx_info.mlx, SIZE_X, SIZE_Y, "FDF");
	img.img = mlx_new_image(mlx_info.mlx, SIZE_X, SIZE_Y);
	img.addr = mlx_get_data_addr(img.img, (int *)(&img.bits_per_pixel),
			&img.line_length, &img.endian);
	ft_printf("img struct created\n");
	fill_projection_struct(&projection_info);
	ft_printf("projection struct created\n");
	fill_mat_struct(&matrix, &trans_matrix, &projection_info);
	ft_printf("matrix struct created\n");
	apply_matrix(map, &matrix, &trans_matrix);
	ft_printf("matrix applied\n");
	print_matrix(&matrix);
	print_matrix(&trans_matrix);
	print_map_content(map);
	draw_all_line(map, &img);
	ft_printf("all lines drawn\n");
	mlx_put_image_to_window(mlx_info.mlx, mlx_info.mlx_win, img.img, 0, 0);
	mlx_loop(mlx_info.mlx);
}
