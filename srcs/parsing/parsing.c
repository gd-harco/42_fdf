/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:08:01 by gd-harco          #+#    #+#             */
/*   Updated: 2022/12/09 15:59:57 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/includes/libft.h"
#include <fcntl.h>

int	*fill_subtable(int *subtable, char **temp_table)
{
	int	x;

	x = 0;
	while (temp_table[x][0])
	{
		subtable[x] = ft_atoi(temp_table[x]);
		x++;
	}
	return (subtable);
}

int	**get_int_table(int fd)
{
	char	*temp;
	char	**temp_table;
	int		**final_tab;
	int		x;

	x = 0;
	temp = get_next_line(fd);
	while (temp)
	{
		temp_table = ft_split(temp, ' ');

		final_tab[x] = malloc(sizeof(int *));
		final_tab[x] = fill_subtable(final_tab[x], temp_table);
		free(temp);
		free(temp_table);
		temp = get_next_line(fd);
	}
	return (0);
}

int	main(int argc, char const *argv[])
{
	int	fd;
	int	**int_table;

	fd = open(argv[1], O_RDONLY);
	int_table = get_int_table(fd);

	return (0);
}

