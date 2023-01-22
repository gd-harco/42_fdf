/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:18:00 by gd-harco          #+#    #+#             */
/*   Updated: 2023/01/22 12:52:49 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	create_vector(
				t_vector3d *vector, size_t position, int line, char *z);

//TODO Creer directement une map de vecteur pour opti
t_vector3d	*create_line(int line_index, t_list *list)
{
	int			x;
	size_t		current_position;
	size_t		line_size;
	t_vector3d	*current_v_line;
	char		**current_c_line;

	x = 0;
	while (x++ < line_index && list->content)
		list = list->next;
	current_c_line = ft_split((char *)list->content, ' ');
	if (current_c_line == NULL)
		exit(1);
	line_size = ft_array_length((void **)current_c_line);
	current_v_line = malloc(sizeof (t_vector3d) * line_size);
	if (current_v_line == NULL)
		exit(1);
	current_position = -1;
	while (++current_position < line_size)
		create_vector(&current_v_line[current_position],
			current_position, line_index, current_c_line[current_position]);
	ft_free_split(current_c_line);
	return (current_v_line);
}

static void	create_vector(
				t_vector3d *vector, size_t position, int line, char *z)
{
	vector->x = (float)position;
	vector->y = (float)line;
	vector->z = (float)ft_atoi(z);
}
