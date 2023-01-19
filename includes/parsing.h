/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:55:00 by gd-harco          #+#    #+#             */
/*   Updated: 2023/01/19 13:55:00 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#ifndef PARSING_H
# define PARSING_H
# include "fdf.h"
# include <fcntl.h>

t_list			*put_file_in_list(int fd);
t_vector_map	parsing_full(char *filename);
void			get_int_map(t_list *list, t_int_map *int_map,
					t_vector_map *v_map);
void			int_map_to_v_map(t_int_map *int_map, t_vector_map *v_map);
#endif
