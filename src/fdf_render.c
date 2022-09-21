/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_render.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/15 19:09:27 by mweverli      #+#    #+#                 */
/*   Updated: 2022/09/21 17:52:38 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <fdf.h>

t_pval	render_isometric(t_fdf *fdf, int index)
{
	t_pval	p;
	float	tmp_x;
	float	tmp_y;

	tmp_x = (index % fdf->map_x);
	tmp_y = (index / fdf->map_x);
	p.x = (tmp_x - tmp_y) * cos(fdf->vval.angle) * fdf->vval.scale;
	p.y = -(fdf->pval[index].z * fdf->vval.z_scale) + (tmp_x + tmp_y) 
		* sin(fdf->vval.angle) * fdf->vval.scale;
	p.z = fdf->pval[index].z;
	p.x += fdf->vval.offset_x;
	p.y += fdf->vval.offset_y;
	return (p);
}

void	fdf_render_init(t_fdf *fdf)
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
