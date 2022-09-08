/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_init_utils.h                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/31 17:03:00 by mweverli      #+#    #+#                 */
/*   Updated: 2022/09/08 14:35:28 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//FUNCTIONS

int	skiphex(char *str);
int	skipnumb(char *str);
int	return_fd(const char *f_name);
int	get_pval(t_fdf *fdf, const char *str, int index);
