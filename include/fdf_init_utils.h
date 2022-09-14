/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_init_utils.h                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/31 17:03:00 by mweverli      #+#    #+#                 */
/*   Updated: 2022/09/14 12:38:50 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_INIT_UTILS_H
# define FDF_INIT_UTILS_H
//DEFAULT MACROS 

# define SCALE 1
# define Z_SCALE 1
# define PIXEL_X 1600
# define PIXEL_Y 900

//FUNCTIONS

int		skiphex(char *str);
int		skipnumb(char *str);
int		return_fd(const char *f_name);
void	set_defaults(t_fdf *fdf);
int		get_pval(t_fdf *fdf, const char *str, int index);

#endif
