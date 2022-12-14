/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 14:57:53 by gd-harco          #+#    #+#             */
/*   Updated: 2022/12/14 16:52:18 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/includes/libft.h"

typedef struct s_map
{
	size_t	width;
	size_t	height;
	int		**content;
}			t_map;

t_list	*put_file_in_list(int fd);

#endif