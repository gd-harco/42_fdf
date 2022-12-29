/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:59:38 by gd-harco          #+#    #+#             */
/*   Updated: 2022/12/28 19:51:28 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

void	init_map(t_map *map)
{
	const int	height = 11;
	const int	width = 19;
	int			wtf[11][19] = {
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 10, 10, 0, 0, 10, 10, 0, 0, 0, 10, 10, 10, 10, 10, 0, 0, 0},
				{0, 0, 10, 10, 0, 0, 10, 10, 0, 0, 0, 0, 0, 0, 0, 10, 10, 0, 0},
				{0, 0, 10, 10, 0, 0, 10, 10, 0, 0, 0, 0, 0, 0, 0, 10, 10, 0, 0},
				{0, 0, 10, 10, 10, 10, 10, 10, 0, 0, 0, 0, 10, 10, 10, 10, 0, 0, 0},
				{0, 0, 0, 10, 10, 10, 10, 10, 0, 0, 0, 10, 10, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 10, 10, 0, 0, 0, 10, 10, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 10, 10, 0, 0, 0, 10, 10, 10, 10, 10, 10, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
				};
  map->height = height;
  map->width = width;
  map->content = malloc(sizeof(int *) * map->height);
  for (int y = 0; y < map->height; y++)
  {
    map->content[y] = malloc(sizeof(int) * map->width);
    for (int x = 0; x < map->width; x++)
      map->content[y][x] = wtf[y][x];
  }
}

int	main(int argc, char const *argv[])
{
	t_map	map;
	void	*mlx;
	void	*window;

	(void)argv[1];
	if (argc != 2)
	{
		ft_printf("No map provided\n");
		return (0);
	}
	init_map(&map);
	mlx = mlx_init();
	window = mlx_new_window(mlx, SIZE_X, SIZE_Y, "test");
	mlx_loop(mlx);
	return (0);

}
