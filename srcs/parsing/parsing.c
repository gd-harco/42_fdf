/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:08:01 by gd-harco          #+#    #+#             */
/*   Updated: 2022/12/13 20:22:25 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

#include <fcntl.h>

// size_t	**fill_map(t_map map, int fd, char **splited)
// {
// 	size_t	*line_int;
// 	size_t	**tab_int;
// 	size_t	x;

// 	line_int = malloc(sizeof(int) * map.width);
// 	x = 0;
// 	while (x < map.width)
// 	{
// 		line_int[x] = ft_atoi(splited[x]);
// 		x++;
// 	}
// 	tab_int = malloc(sizeof(int *));
// 	tab_int[0] = line_int;
// 	return (tab_int);
// }

t_map	*create_map(int fd)
{
	char	*line;
	char	**splitted_line;
	t_map	current_map;

	line = get_next_line(fd);
	splitted_line = ft_split(line, ' ');
	current_map.width = array_length((void **)splitted_line);
	current_map.content = fill_map(current_map, fd, splitted_line);
}

int	main(int argc, char const *argv[])
{
	int		fd;
	t_map	*current_map;

	fd = open(argv[1], O_RDONLY);
	current_map = create_map(fd);
	return (0);
}
