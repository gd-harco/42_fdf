/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:28:27 by gd-harco          #+#    #+#             */
/*   Updated: 2023/01/26 19:27:55 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	initialisation(char *filename, t_fdf *fdf)
{
	fdf->mlx.mlx_ptr = mlx_init();

	fdf->mlx.win_ptr = mlx_new_window(fdf->mlx.mlx_ptr, HEIGHT, WIDTH, "fdf");
	parsing(filename, &fdf->map);
	fdf->img.img_ptr = mlx_new_image(fdf->mlx.mlx_ptr, WIDTH, HEIGHT);
	fdf->img.addr = mlx_get_data_addr()
}
