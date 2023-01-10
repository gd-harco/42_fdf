/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3dpoint_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:44:00 by gd-harco          #+#    #+#             */
/*   Updated: 2023/01/10 11:44:00 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/graphics.h"
#include "../../includes/fdf.h"

void	graphics_test(void)
{
	void	*mlx;
	void	*window;

	mlx = mlx_init();
	window = mlx_new_window(mlx, SIZE_X, SIZE_Y, "3D Point Test");
	mlx_loop(mlx);
}
