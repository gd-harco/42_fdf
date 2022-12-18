/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:08:01 by gd-harco          #+#    #+#             */
/*   Updated: 2022/12/18 14:57:04 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"
#include <fcntl.h>

int	main(int argc, char const *argv[])
{
	int				fd;
	t_list			*s_linked_text;
	t_map			map;

	if (argc != 2)
	{
		ft_printf("No map provided\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	s_linked_text = put_file_in_list(fd);
	close(fd);
	map.content = linked_to_array(*s_linked_text);
	ft_lstclear(&s_linked_text, free);
	map.height = ft_array_length((void *)map.content);
	ft_printf("map.height : %d\n", map.height);
	map.width = ft_array_length((void **)map.content);
	ft_printf("map.width : %d\n", map.width);
	return (0);
}
