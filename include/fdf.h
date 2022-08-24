/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/24 20:32:44 by mweverli      #+#    #+#                 */
/*   Updated: 2022/08/24 22:15:21 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/01 18:59:34 by mweverli      #+#    #+#                 */
/*   Updated: 2022/08/24 20:25:54 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

//INCLUDES

# include <limits.h>
# include <stdlib.h>	// malloc free exit
# include <unistd.h>	// close read write
# include <fcntl.h>		// open
# include <stdio.h>		// perror
# include <errno.h>		// errno
# include <string.h>	// strerror
# include <math.h>		// math functions

//DEFINITIONS / MACROS

# define WINDOW_WIDTH 1980
# define WINDOW_HEIGHT 1080

// STRUCTURES

typedef struct s_fdf
{
	mlx_t	*mlx;

}	t_fdf;

// FUNCTIONS

void	fdf_exit(int error_id, const char *loc);
void	check_input(const char *str);

// LIBRARY FUNCTION

int		ft_printf(const char *str, ...);

#endif
