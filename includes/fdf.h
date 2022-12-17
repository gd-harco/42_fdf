/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 14:57:53 by gd-harco          #+#    #+#             */
/*   Updated: 2022/12/17 17:01:05 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/includes/libft.h"
# define MAP_DATA int[11][19] = {{1  2  3  4  5  6  7  8  9  8  7  6  5  4  3  2  1  0  10}}

typedef struct s_map
{
	size_t	width;
	size_t	height;
	int		**content;
}			t_map;

t_list	*put_file_in_list(int fd);
int		**linked_to_array(t_list list);


#endif
