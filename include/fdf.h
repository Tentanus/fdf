/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/01 18:59:34 by mweverli      #+#    #+#                 */
/*   Updated: 2022/09/14 15:30:45 by mweverli      ########   odam.nl         */
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
# define WINDOW_BORDER 100

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

typedef struct s_def
{
	size_t	offset_x;
	size_t	offset_y;
}	t_def;

typedef struct s_3float
{
	float			x;
	float			y;
	float			z;
	unsigned int	col;
}	t_3float;

typedef struct s_point
{
	t_3float	p1;
	t_3float	p2;
	float		dx;
	float		dy;
	int			sx;
	int			xy;
}	t_point;

typedef struct s_fdf
{
	mlx_t		*mlx;
	void*		img;
	size_t		map_x;
	size_t		map_y;
	t_pval		*pval;
	t_def		def;
	int			scale;
	int			z_scale;

}	t_fdf;

// FUNCTIONS

void	fdf_exit(int error_id, const char *loc);
t_fdf	fdf_init(const char *f_name);
void	fdf_render(t_fdf fdf);
int		skiphex(char *str);
int		get_colour(t_pval *pval, char *str);

// LIBRARY FUNCTION

int		ft_printf(const char *str, ...);
char	*get_next_line(int fd);

#endif
