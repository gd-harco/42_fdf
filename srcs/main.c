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

#include "fdf.h"

int	main(int argc, char const *argv[])
{
	t_map	map;

	if (argc != 2)
	{
		ft_printf("No map provided\n");
		return (0);
	}
	map = parsing_full(argv[1]);
	//TODO graphics rendering code
	graphics_init(&map);
	ft_free_array((void *)map.content);
	return (0);
}
