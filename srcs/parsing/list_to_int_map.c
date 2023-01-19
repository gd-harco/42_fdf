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

int	*create_array_line(int i, t_list *list)
{
	int		x;
	size_t	current_position;
	size_t	line_size;
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
	ft_free_split(current_line);
	return (int_line);
}

size_t	get_nb_word(void *vstr)
{
	size_t	nb_word;
	size_t	x;
	char	*str;
	char	c;

	str = (char *)vstr;
	x = 0;
	c = ' ';
	nb_word = 0;
	while (str[x])
	{
		if (str[x] != c)
			nb_word++;
		while (str[x] && str[x] != c)
			x++;
		if (str[x])
			x++;
	}
	return (nb_word);
}

void	get_int_map(t_list *list, t_int_map *int_map, t_vector_map *v_map)
{
	size_t	i;

	if (int_map == NULL)
		exit(1);
	int_map->height = ft_lstsize(list);
	int_map->width = get_nb_word(list->content);
	v_map->height = int_map->height;
	v_map->width = int_map->width;
	int_map->map = ft_calloc(sizeof (int *), int_map->height);
	v_map->map = ft_calloc(sizeof (t_vector3d *), int_map->height);
	i = -1;
	while (++i < int_map->height)
		int_map->map[i] = create_array_line((int)i, list);
}
