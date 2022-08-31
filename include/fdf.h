/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/01 18:59:34 by mweverli      #+#    #+#                 */
/*   Updated: 2022/08/31 19:49:43 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

//INCLUDES

# include <unistd.h>	// close read write
# include <fcntl.h>		// open
# include <stdlib.h>	// malloc free exit
# include <stdio.h>		// perror
# include <errno.h>		// errno
# include <string.h>	// strerror
# include <math.h>		// math functions
# include <limits.h>
# include "MLX42.h"
# include "libft.h"

//DEFINITIONS / MACROS

# define WINDOW_WIDTH 1980
# define WINDOW_HEIGHT 1080

// STRUCTURES

typedef struct s_dimmap
{
	float	x;
	float	y;
	float	z;
}	t_dimmap;

typedef struct s_fdf
{
	mlx_t		*mlx;
	size_t		map_x;
	size_t		map_y;
	t_dimmap	*dimmap;
	int			*intmap;
}	t_fdf;

// FUNCTIONS

void	fdf_exit(int error_id, const char *loc);
t_fdf	fdf_init(const char *f_name);

// LIBRARY FUNCTION

int		ft_printf(const char *str, ...);
char	*get_next_line(int fd);

#endif
