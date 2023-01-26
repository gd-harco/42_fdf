/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:55:12 by gd-harco          #+#    #+#             */
/*   Updated: 2023/01/26 14:25:27 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

t_vector3d	multiply_matrix_vector(t_matrix matrix,
				t_vector3d vector);
t_matrix	m_make_identity(void);
t_matrix	m_make_rotation_x(float angle);
t_matrix	m_make_rotation_y(float angle);
t_matrix	m_make_rotation_z(float angle);
t_matrix	m_make_translation(float x, float y, float z);

#endif
