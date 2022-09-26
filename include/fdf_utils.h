/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_utils.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/31 17:03:00 by mweverli      #+#    #+#                 */
/*   Updated: 2022/09/26 19:34:20 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_UTILS_H
# define FDF_UTILS_H

//DEFAULT MACROS 

# define SCALE 100 
# define ISOMETRIC 1 

//	FUNCTIONS

//	fdf_init
int				skiphex(char *str);
int				skipnumb(char *str);
int				return_fd(const char *f_name);
void			set_defaults(t_fdf *fdf);
int				get_pval(t_fdf *fdf, const char *str, int index);

//	fdf_render
t_pval			render_isometric(t_fdf *fdf, int index);

//	fdf_col
int				get_cval(t_pval *pval, char *str);
uint32_t		get_col_gradient(t_pval p0, t_pval p1, t_draw draw);

#endif
