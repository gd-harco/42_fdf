/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:18:00 by gd-harco          #+#    #+#             */
/*   Updated: 2023/01/20 15:18:00 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
//TODO Creer directement une map de vecteur pour opti
int	*create_int_line(int line_index, t_list *list)
{
	int		x;
	size_t	current_position;
	size_t	line_size;
	int		*int_line;
	char	**current_line;

	x = 0;
	while (x++ < line_index && list->content)
		list = list->next;
	current_line = ft_split((char *)list->content, ' ');
	if (current_line == NULL)
		exit(1);
	line_size = ft_array_length((void **)current_line);
	int_line = malloc(sizeof (int) * line_size);
	if (int_line == NULL)
		exit(1);
	current_position = 0;
	while (current_position < line_size)
	{
		int_line[current_position] = ft_atoi(current_line[current_position]);
		current_position++;
	}
	ft_free_split(current_line);
	return (int_line);
}

void	int_map_to_v_map(t_int_map *int_map, t_vector_map *v_map)
{
	size_t	y;
	size_t	x;

	y = -1;
	while (++y < int_map->height)
	{
		v_map->map[y] = malloc(sizeof(t_vector3d) * int_map->width);
		if (!v_map->map[y])
			exit(1);
		x = -1;
		while (++x < int_map->width)
		{
			v_map->map[y][x].y = (float)y;
			v_map->map[y][x].x = (float)x;
			v_map->map[y][x].z = (float)int_map->map[y][x];
		}
	}
}
