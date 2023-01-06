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

#include "fdf.h"

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

static size_t	get_nb_word(char const *s, char c)
{
	size_t	nb_word;
	size_t	x;

	x = 0;
	nb_word = 0;
	while (s[x])
	{
		if (s[x] != c)
			nb_word++;
		while (s[x] && s[x] != c)
			x++;
		if (s[x])
			x++;
	}
	return (nb_word);
}

void	linked_to_array(t_list list, t_map *map)
{
	int		**map_array;
	size_t	i;

	map->height = ft_lstsize(&list);
	map->width = get_nb_word(list.content, ' ');
	map_array = ft_calloc(sizeof(int *), map->height);
	i = 0;
	while (i < map->height)
	{
		map_array[i] = create_array_line(i, &list);
		i++;
	}
	map->content = map_array;
}
