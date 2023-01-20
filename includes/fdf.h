/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:04:00 by gd-harco          #+#    #+#             */
/*   Updated: 2023/01/20 00:09:10 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../lib/libft/includes/libft.h"
# include "structs.h"
# include "parsing.h"
# include "graphics.h"
# include <math.h>
# ifdef __APPLE__
#  include "../lib/mlx/mlx.h"
# endif
# ifdef __linux__
#  include <mlx.h>
# endif
# ifndef HEIGHT
#  define HEIGHT 720
# endif
# ifndef WIDTH
#  define WIDTH 1280
# endif
#endif
