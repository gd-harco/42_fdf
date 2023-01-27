/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:04:00 by gd-harco          #+#    #+#             */
/*   Updated: 2023/01/26 17:30:43 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../lib/libft/includes/libft.h"
# include "structs.h"
# include "parsing.h"
# include "graphics.h"
# include "matrix.h"
# include <math.h>
# include <stdio.h>

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

void	initialisation(char *filename, t_fdf *fdf);

#endif
