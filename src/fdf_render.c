/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_render.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/05 18:46:20 by mweverli      #+#    #+#                 */
/*   Updated: 2022/09/08 14:14:13 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	get_x(t_fdf fdf, size_t index)
{
	t_point	point;

	point.x1 = fdf.pval[index].x;
	point.y1 = fdf.pval[index].y;
	if ()
	point.x2 = fdf.pval[index + 1];
	return (point);
}

void	fdf_render(t_fdf fdf)
{
	size_t	index;
	t_point	point;

	index = 0;
	while (index < (fdf.map_x * fdf.map_y))
	{
		point = get_x(fdf, index);
	}
}
