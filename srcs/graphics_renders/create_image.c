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

#include "../../includes/fdf.h"
#include "../../includes/graphics.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	create_line(t_data *data)
{
	int	i;

	i = 20;
	while (i < 150)
	{
		my_mlx_pixel_put(data, 2 * i, i, 0xFFF2CC);
		i++;
	}
}

void	graphics_init(t_map *map)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	(void )map;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, SIZE_X, SIZE_Y, "FDF");
	img.img = mlx_new_image(mlx, SIZE_X, SIZE_Y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
	&img.line_length,&img.endian);
	create_line(&img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
