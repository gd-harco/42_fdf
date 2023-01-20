/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:58:00 by gd-harco          #+#    #+#             */
/*   Updated: 2023/01/20 00:05:06 by gd-harco         ###   ########lyon.fr   */
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
	vector_map = parsing_full(argv[1]);
	graphic_launch(vector_map);
	return (0);
}
