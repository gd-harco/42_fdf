/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:55:00 by gd-harco          #+#    #+#             */
/*   Updated: 2023/01/20 14:15:07 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include "fdf.h"
# include <fcntl.h>

// parsing.c
t_vector_map	parsing(char *filename);

// map_operations.c
void			int_map_to_v_map(t_int_map *int_map, t_vector_map *v_map);
int				*create_int_line(int line_index, t_list *list);

#endif
