/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/01 18:59:34 by mweverli      #+#    #+#                 */
/*   Updated: 2022/09/06 20:30:08 by mweverli      ########   odam.nl         */
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

typedef struct s_pval
{
	float	x;
	float	y;
	float	z;
	int				r;
	int				g;
	int				b;
	unsigned int	col;
}	t_pval;

typedef struct s_fdf
{
	mlx_t		*mlx;
	mlx_image_t	img;
	size_t		map_x;
	size_t		map_y;
	t_pval		*pval;
}	t_fdf;

// FUNCTIONS

void	fdf_exit(int error_id, const char *loc);
t_fdf	fdf_init(const char *f_name);
int		skiphex(char *str);

int		get_colour(t_pval pval, char *str);

// LIBRARY FUNCTION

int		ft_printf(const char *str, ...);
char	*get_next_line(int fd);

#endif
