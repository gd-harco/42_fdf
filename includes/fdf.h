/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 14:57:53 by gd-harco          #+#    #+#             */
/*   Updated: 2022/12/18 16:28:52 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/includes/libft.h"

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
