/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/01 18:59:34 by mweverli      #+#    #+#                 */
/*   Updated: 2022/09/19 14:55:26 by mweverli      ########   odam.nl         */
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
//# include <math.h>		// math functions
# include <limits.h>
# include "MLX42.h"
# include "libft.h"

//DEFINITIONS / MACROS

# define WINDOW_WIDTH 1980
# define WINDOW_HEIGHT 1080
# define BORDER 10

# define ISOMETRIC 0
# define TOPDOWN 1

// STRUCTURES & ENUMS

typedef struct s_pval
{
	float			x;
	float			y;
	float			z;
}	t_pval;

typedef struct s_cval
{
	int				r;
	int				g;
	int				b;
	unsigned int	col;
} t_cval;

typedef struct s_fdf
{
	mlx_t		*mlx;
	void*		img;
	size_t		map_x;
	size_t		map_y;
	t_pval		*pval;
	t_cval		*cval;
	int			scale;
	int			z_scale;
	int			offset_x;
	int			offset_y;
	int			pov;
}	t_fdf;

// FUNCTIONS

void	fdf_exit(int error_id, const char *loc);
void	fdf_render(t_fdf *fdf);
void	fdf_draw(t_fdf *fdf);
t_fdf	fdf_init(const char *f_name);
t_pval	render_isometric(t_fdf *fdf, int index);
int		skiphex(char *str);
int		get_cval(t_cval *cval, char *str);

// LIBRARY FUNCTION

int		ft_printf(const char *str, ...);

#endif
