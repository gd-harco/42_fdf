/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:59:00 by gd-harco          #+#    #+#             */
/*   Updated: 2023/01/19 13:59:00 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	free_int_map(t_int_map int_map)
{
	size_t	i;

	i = 0;
	while (i < int_map.height)
	{
		free(int_map.map[i]);
		i++;
	}
	free(int_map.map);
}

t_list	*put_file_in_list(int fd)
{
	t_list	*list;
	char	*buff;

	buff = get_next_line(fd);
	list = ft_lstnew(buff);
	list->next = NULL;
	while (buff)
	{
		buff = get_next_line(fd);
		ft_lstadd_back(&list, ft_lstnew(buff));
	}
	return (list);
}

t_vector_map	parsing_full(char *filename)
{
	int				fd;
	t_list			*file_in_list;
	t_int_map		int_map;
	t_vector_map	vector_map;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("error opening the provided file\n");
		exit (1);
	}
	file_in_list = put_file_in_list(fd);
	get_int_map(file_in_list, &int_map, &vector_map);
	ft_lstclear(&file_in_list, free);
	int_map_to_v_map(&int_map, &vector_map);
	free_int_map(int_map);
	return (vector_map);
}
