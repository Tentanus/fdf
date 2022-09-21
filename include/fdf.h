/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/01 18:59:34 by mweverli      #+#    #+#                 */
/*   Updated: 2022/09/21 17:52:42 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

//INCLUDES

# include <unistd.h>	// close read write
# include <stdlib.h>	// malloc free exit
# include <errno.h>		// errno
# include <limits.h>
//	# include <fcntl.h>		// open
//	# include <stdio.h>		// perror
//	# include <string.h>	// strerror
//	# include <math.h>		// math functions

# include <MLX42.h>
# include <libft.h>

//DEFINITIONS / MACROS

# define WINDOW_WIDTH 1980
# define WINDOW_HEIGHT 1080
# define BORDER 10

// STRUCTURES & ENUMS

typedef struct s_pval
{
	float			x;
	float			y;
	float			z;
	unsigned int	col;
}	t_pval;

typedef struct s_cval
{
	int				r;
	int				g;
	int				b;
	unsigned int	col;
} t_cval;

typedef struct s_vval
{
	int		scale;
	int		z_scale;
	int		offset_x;
	int		offset_y;
	double	angle;
} t_vval;

typedef struct s_draw
{
	int	dx;
	int	dy;
	int	x_sign;
	int	y_sign;
	int	x_err;
	int	y_err;
} t_draw;

typedef struct s_fdf
{
	mlx_t		*mlx;
	void*		img;
	size_t		map_x;
	size_t		map_y;
	t_pval		*pval;
	t_cval		*cval;
	t_vval		vval;
}	t_fdf;

// FUNCTIONS

void	fdf_exit(int error_id, const char *loc);
void	fdf_render_init(t_fdf *fdf);
void	fdf_draw(t_fdf *fdf);
t_fdf	fdf_init(const char *f_name);

// LIBRARY FUNCTION

int		ft_printf(const char *str, ...);

#endif
