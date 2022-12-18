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

#include "../../includes/fdf.h"
#include <fcntl.h>

t_map	parsing_full(const char *file)
{
	int		fd;
	t_list	*s_linked_text;
	t_map	map;

	fd = open(file, O_RDONLY);
	s_linked_text = put_file_in_list(fd);
	close(fd);
	map.content = linked_to_array(*s_linked_text);
	ft_lstclear(&s_linked_text, free);
	map.height = ft_array_length((void *)map.content);
	map.width = ft_array_length((void **)map.content);
	return (map);
}
