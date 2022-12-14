/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:08:01 by gd-harco          #+#    #+#             */
/*   Updated: 2022/12/14 14:52:17 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

// t_map	*create_map(int fd)
// {
// 	char	*line;
// 	char	**splitted_line;
// 	t_map	current_map;

// 	line = get_next_line(fd);
// 	splitted_line = ft_split(line, ' ');
// 	current_map.width = array_length((void **)splitted_line);
// 	current_map.content = fill_map(current_map, fd, splitted_line);
// }

int	main(int argc, char const *argv[])
{
	int				fd;
	t_list			*s_text_in_list;

	if (argc != 2)
	{
		ft_printf("No map provided\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	s_text_in_list = put_file_in_list(fd);
	return (0);
}
