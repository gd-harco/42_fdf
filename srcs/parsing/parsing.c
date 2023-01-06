/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:08:01 by gd-harco          #+#    #+#             */
/*   Updated: 2022/12/18 16:19:21 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

void	ft_print_map(t_map map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			ft_printf("%d ", map.content[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

t_map	parsing_full(const char *file)
{
	int		fd;
	t_list	*linked_text;
	t_map	map;

	fd = open(file, O_RDONLY);
	linked_text = put_file_in_list(fd);
	close(fd);
	linked_to_array(*linked_text, &map);
	ft_lstclear(&linked_text, free);
	return (map);
}
