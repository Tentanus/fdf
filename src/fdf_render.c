/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_render.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/15 19:09:27 by mweverli      #+#    #+#                 */
/*   Updated: 2022/09/19 18:53:26 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

t_pval	render_isometric(t_fdf *fdf, int index)
{
	t_pval	p;
	float	tmp_x;
	float	tmp_y;

	tmp_x = (index % fdf->map_x);
	tmp_y = (index / fdf->map_x);
	p.x = (tmp_x - tmp_y) * cos(0.523599) * fdf->scale;
	p.y = -(fdf->pval[index].z * fdf->z_scale) + (tmp_x + tmp_y) 
		* sin(0.523599) * fdf->scale;
	p.z = fdf->pval[index].z;
	p.x += fdf->offset_x;
	p.y += fdf->offset_y;
	return (p);
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
			index = (y * fdf->map_x) + x++;
			fdf->pval[index] = render_isometric(fdf, index);
		}
		y++;
	}
}
