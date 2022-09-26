/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/01 18:59:34 by mweverli      #+#    #+#                 */
/*   Updated: 2022/09/26 19:39:50 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

//INCLUDES

# include <unistd.h>	// close read write
//# include <stdlib.h>	// malloc free exit
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

// STRUCTURES & ENUMS

typedef struct s_pval
{
	int			x;
	int			y;
	int			z;
	uint32_t	col;
}	t_pval;

typedef struct s_cval
{
	int		r;
	int		g;
	int		b;
}	t_cval;

typedef struct s_vval
{
	int		scale;
	int		z_scale;
	int		offset_x;
	int		offset_y;
	double	angle;
}	t_vval;

typedef struct s_draw
{
	int		dx;
	int		dy;
	int		x_sign;
	int		y_sign;
	int		x_err;
	int		y_err;
	int		err;
}	t_draw;

typedef struct s_fdf
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	size_t		map_x;
	size_t		map_y;
	t_pval		*pval;
	t_vval		vval;
}	t_fdf;

// FUNCTIONS

void	fdf_exit(int error_id, const char *loc);
void	fdf_render(t_fdf *fdf);
void	fdf_draw(t_fdf *fdf);
void	fdf_loop(t_fdf *fdf, mlx_image_t *img);
t_fdf	fdf_init(const char *f_name);


// LIBRARY FUNCTION

int		ft_printf(const char *str, ...);

#endif
