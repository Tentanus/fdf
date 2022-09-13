/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_defaults.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/13 17:37:32 by mweverli      #+#    #+#                 */
/*   Updated: 2022/09/13 17:55:07 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdf_init_utils.h"

void	set_defaults(t_fdf *fdf)
{
	fdf->scale = SCALE;
	fdf->z_scale = Z_SCALE;
	fdf->def.offset_x = (PIXEL_X / 2);
	fdf->def.offset_y = (PIXEL_Y / 2);
}

