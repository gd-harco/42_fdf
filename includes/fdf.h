/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 14:57:53 by gd-harco          #+#    #+#             */
/*   Updated: 2022/12/28 19:16:19 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../lib/libft/includes/libft.h"
# if defined(__APPLE__)
#  include "../lib/mlx/macos/mlx.h"
# endif
# if defined(__linux__)
#  define MLXH "/usr/include/mlx.h"
# endif
# ifndef SIZE_X
#  define SIZE_X 1280
# endif
# ifndef SIZE_Y
#  define SIZE_Y 720
# endif
# include <fcntl.h>

typedef struct s_data{
	void	*img;
	char	*addr;
	int		line_length;
	int		bits_per_pixel;
	int		endian;
}	t_data;

typedef struct s_map
{
	int	width;
	int	height;
	int	**content;
}	t_map;

t_list	*put_file_in_list(int fd);
int		**linked_to_array(t_list list);
t_map	parsing_full(const char *file);


#endif
