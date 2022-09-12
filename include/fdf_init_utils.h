/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_init_utils.h                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/31 17:03:00 by mweverli      #+#    #+#                 */
/*   Updated: 2022/09/03 14:13:59 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//FUNCTIONS

int		skiphex(char *str);
int		skipnumb(char *str);
int		return_fd(const char *f_name);
void	set_defaults(t_fdf fdf);
