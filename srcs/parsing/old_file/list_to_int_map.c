/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:56:00 by gd-harco          #+#    #+#             */
/*   Updated: 2023/01/19 14:56:00 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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
