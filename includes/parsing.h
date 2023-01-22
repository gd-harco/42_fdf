/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:55:00 by gd-harco          #+#    #+#             */
/*   Updated: 2023/01/22 12:52:20 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include "fdf.h"
# include <fcntl.h>

// parsing.c
t_vector_map	parsing(char *filename);

// map_operations.c
t_vector3d		*create_line(int line_index, t_list *list);

#endif
