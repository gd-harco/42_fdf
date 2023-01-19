/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:58:00 by gd-harco          #+#    #+#             */
/*   Updated: 2023/01/19 12:58:00 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_vector_map	vector_map;
	t_mlx_info		mlx_infos;

	if (argc != 2)
	{
		ft_printf("Usage: ./fdf <filename>\n");
		return (0);
	}
	vector_map = parsing_full(argv[1]);
	mlx_infos.mlx_ptr = mlx_init();
	mlx_infos.win_ptr = mlx_new_window(mlx_infos.mlx_ptr, 1920, 1080, "fdf");
	graphic_launch(&mlx_infos, &vector_map);
	return (0);
}
