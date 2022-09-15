/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_render.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/15 19:09:27 by mweverli      #+#    #+#                 */
/*   Updated: 2022/09/15 19:34:38 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

static 

t_pval	render_isometric(t_pval	pval, index)
{
	float	tmp_x;
	float	tmp_y;

	tmp_x = (index % fdf->map_x);
	tmp_y = (index / fdf->map_x);
	pval.x = (tmp_x - tmp_y) * cos(0.523599);
	pval.y = -pval.OG_z + (tmp_x + tmp_y) * sin(0.523599);
}

t_pval	render_topdown(t_pval pval, index)
{
	pval.x = 
}

fdf_render(t_fdf *fdf, int index)
{
	if (fdf->pov == ISOMETRIC)
		render_isometric(fdf->pval[index], index);
	if (fdf->pov == TOPDOWN)
		render_topdown(fdf->pval[index], index);
}
