/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_render.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/15 19:09:27 by mweverli      #+#    #+#                 */
/*   Updated: 2022/09/16 16:16:20 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

void	render_isometric(t_fdf *fdf, int index)
{
	float	tmp_x;
	float	tmp_y;

	tmp_x = (index % fdf->map_x);
	tmp_y = (index / fdf->map_x);
	fdf->pval[index].x = (tmp_x - tmp_y) * cos(0.523599) * fdf->scale;
	fdf->pval[index].y = -(fdf->pval[index].z * fdf->z_scale) +
		(tmp_x + tmp_y) * sin(0.523599) * fdf->scale;
}

void	render_topdown(t_fdf *fdf, int index)
{
	fdf->pval[index].x = (index % fdf->map_x) * fdf->scale;
	fdf->pval[index].y = (index / fdf->map_x) * fdf->scale;
}

get_function(t_fdf *fdf, int index)
{
	if (fdf->pov == ISOMETRIC)
		render_isometric(fdf, index);
	if (fdf->pov == TOPDOWN)
		render_topdown(fdf, index);
}

void	fdf_render(t_fdf *fdf)
{
	size_t	x;
	size_t	y;
	size_t	index;

	y = 0;
	while (y < fdf->map_y)
	{
		x = 0;
		while (x < fdf->map_x)
		{
			index = (x * fdf->map_x) + y;
			get_function(fdf, index);
			draw(fdf->pval[index]);
		}
	}

}
