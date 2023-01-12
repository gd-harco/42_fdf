/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 14:57:53 by gd-harco          #+#    #+#             */
/*   Updated: 2023/01/05 14:39:46 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include <math.h>

typedef struct s_map
{
	size_t	width;
	size_t	height;
	int		**content;
}	t_map;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

t_list	*put_file_in_list(int fd);
void	linked_to_array(t_list list, t_map *map);
t_map	parsing_full(const char *file);
#endif
