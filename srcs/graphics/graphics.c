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

void	graphic_launch(t_mlx_info mlx, t_vector_map vector_map)
{
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, WIDTH, HEIGHT, "fdf");
	mlx.img_ptr = mlx_new_image(mlx.mlx_ptr, WIDTH, HEIGHT);
	(void)vector_map;
	mlx_loop(mlx.mlx_ptr);
}
