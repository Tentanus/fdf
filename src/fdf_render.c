/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_render.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/05 18:46:20 by mweverli      #+#    #+#                 */
/*   Updated: 2022/09/13 18:00:41 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	get_x(t_fdf fdf, size_t index, int f)
{
	t_point	point;

	point.x1 = fdf.pval[index].x;
	point.y1 = fdf.pval[index].y;
	if (f == 0)
	{
		point.x2 = fdf.pval[index + 1].x;
		point.y2 = fdf.pval[index + 1].y;
	}
	if (f == 1)
	{
		point.x2 = fdf.pval[index + (fdf.map_x)].x;
		point.y2 = fdf.pval[index + (fdf.map_x)].y;
	}
	return (point);
}



void	fdf_render(t_fdf fdf)
{
	size_t	index;
	t_point	points;

	index = 0;
	while (index < fdf.map_x)
	{
		points = get_x(fdf, index, 0);
		draw();
	}
	index = 0;
	while (index < fdf.map_y)
	{
		points = get_x(fdf, index, 1);
		draw();
	}
}
