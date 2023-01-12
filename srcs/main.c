/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:59:38 by gd-harco          #+#    #+#             */
/*   Updated: 2023/01/04 15:49:50 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/graphics.h"

int	main(int argc, char const *argv[])
{
	t_map	map;

	if (argc != 2)
	{
		ft_printf("No map provided\n");
		return (0);
	}
	ft_printf("%d, %d\n", SIZE_X, SIZE_Y);
	map = parsing_full(argv[1]);
	graphics_init(&map);
	ft_free_array((void *)map.content);
	return (0);
}

/*
 * world_matrix = rot_y_m * rot_x_m * rot_z_m * trans_m
 * proj_m = get_proj_mat()
 *
 * while lines_left_to_draw:
 * 		vec1 = vec1 * world_matrix
 * 		vec1 = vec1 * matrix
 * 		vec1.x = (vec1.x + 1.0f) * (float)taille_ecran_x / 2 + 0.5f
 * 		vec1.y = (vec1.x + 1.0f) * (float)taille_ecran_y / 2 + 0.5f
 *
 * 		vec2 = vec2 * world_matrix
 * 		vec2 = vec2 * matrix
 * 		vec2.x = (vec2.x + 1.0f) * (float)taille_ecran_x / 2 + 0.5f
 * 		vec2.y = (vec2.x + 1.0f) * (float)taille_ecran_y / 2 + 0.5f
 *
 * 		draw_line(vec1, vec2)
 */
