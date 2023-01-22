/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:58:00 by gd-harco          #+#    #+#             */
/*   Updated: 2023/01/22 15:28:12 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_vector_map	vector_map;

	if (argc != 2)
	{
		ft_printf("Usage: ./fdf <filename>\n");
		return (0);
	}
	vector_map = parsing(argv[1]);
	ft_printf("2");
	(void)vector_map;
	ft_free_array((void **)vector_map.map);
	printf("%f %f %f\n", vector_map.map[0][0].x,vector_map.map[0][0].y, vector_map.map[0][0].z);
	// graphic_launch(vector_map);

	return (0);
}
