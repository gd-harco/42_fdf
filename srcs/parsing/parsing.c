/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:08:01 by gd-harco          #+#    #+#             */
/*   Updated: 2022/12/11 18:29:43 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

#include <fcntl.h>

// int	*fill_subtable(int *subtable, char **temp_table)
// {
// 	int	x;

// 	x = 0;
// 	while (temp_table[x][0])
// 	{
// 		subtable[x] = ft_atoi(temp_table[x]);
// 		x++;
// 	}
// 	return (subtable);
// }

// int	**get_int_table(int fd)
// {
// 	char	*temp;
// 	char	**temp_table;
// 	int		**final_tab;
// 	int		x;

// 	x = 0;
// 	temp = get_next_line(fd);
// 	while (temp)
// 	{
// 		temp_table = ft_split(temp, ' ');

// 		final_tab[x] = malloc(sizeof(int *));
// 		final_tab[x] = fill_subtable(final_tab[x], temp_table);
// 		free(temp);
// 		free(temp_table);
// 		temp = get_next_line(fd);
// 	}
// 	return (0);
// }

int **fill_map(t_map map, int fd, char **splited)
{
	int **
}

char *read_full_file(int fd, char *line)
{
	char	*temp;

	temp = line;
	while (temp)
	{

	}
}

size_t get_witdh(char **line)
{
	size_t	x;

	x = 0;
	while (line[x])
		x++;
	return x;
}

t_map	*create_map(int fd)
{
	char *line;
	char **splitted_line;
	t_map	current_map;

	current_map = {NULL, NULL, NULL};
	line = get_next_line(fd);
	splitted_line = ft_split(line, ' ');
	current_map.width = get_witdh(splitted_line);
	current_map.content = fill_map(current_map, fd, splitted_line);
}


int	main(int argc, char const *argv[])
{
	int	fd;
	map	*current_map;

	fd = open(argv[1], O_RDONLY);
	current_map = create_map(fd);

	return (0);
}

