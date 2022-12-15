/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chained_to_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:12:38 by gd-harco          #+#    #+#             */
/*   Updated: 2022/12/15 14:49:14 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	*create_array_line(int i, t_list *list)
{
	int		x;
	int		current_position;
	int		line_size;
	int		*int_line;
	char	**current_line;

	x = 0;
	while (x++ < i && list->content)
		list = list->next;
	current_line = ft_split((char *)list->content, ' ');
	line_size = ft_array_length((void **)current_line);
	int_line = malloc(sizeof (int) * line_size);
	current_position = 0;
	while (current_position < line_size)
	{
		int_line[current_position] = ft_atoi(current_line[current_position]);
		current_position++;
	}
	free(current_line);
	return (int_line);
}

int	**linked_to_array(t_list list)
{
	int	array_height;
	int	**map_array;
	int	i;

	array_height = ft_lstsize(&list);
	map_array = malloc(sizeof(int *) * array_height);
	i = 0;
	while (i < array_height)
	{
		map_array[i] = create_array_line(i, &list);
		i++;
	}
	return (map_array);
}
