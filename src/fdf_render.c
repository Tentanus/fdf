/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_render.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/05 18:46:20 by mweverli      #+#    #+#                 */
/*   Updated: 2022/09/14 15:30:51 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ternarie(int val, int a, int b)
{
	if (val)
		return (a);
	return (b);
}

void	get_cord_extend(t_fdf fdf, size_t index, t_point *point)
{
	point->dx = point->p2.x - point->p1.x;
	point->dy = point->p2.y - point->p1.y;
	point->sx = ternarie(dx >= 0, 1, -1);
	point->sy = ternarie(dy >= 0, 1, -1);
}

t_point	get_cord_y(t_fdf fdf, size_t x, size_t y)
{
	t_point	point;
	size_t	index;

	index = (y * fdf.map_x) + x;
	point.p1.x1 = fdf.pval[index].x;
	point.p1.y1 = fdf.pval[index].y;
	point.p1.z1 = fdf.pval[index].z;
	point.p1.col = fdf.pval[index].col;
	point.p2.x = fdf.pval[(index + fdf.map_x)].x;
	point.p2.y = fdf.pval[(index + fdf.map_x)].y;
	point.p2.z = fdf.pval[(index + fdf.map_x)].z;
	point.p2.col = fdf.pval[(index + fdf.map_x)].col;
	get_cord_extend(fdf, index, &point);
	return (point);
}

t_point	get_cord_x(t_fdf fdf, size_t x, size_t y)
{
	t_point	point;
	size_t	index;

	index = (y * fdf.map_x) + x;
	point.p1.x1 = fdf.pval[index].x;
	point.p1.y1 = fdf.pval[index].y;
	point.p1.z1 = fdf.pval[index].z;
	point.p1.col = fdf.pval[index].col;
	point.p2.x = fdf.pval[index + 1].x;
	point.p2.y = fdf.pval[index + 1].y;
	point.p2.z = fdf.pval[index + 1].z;
	point.p2.col = fdf.pval[index + 1].col;
	get_cord_extend(fdf, index, &point);
	return (point);
}

void	fdf_render(t_fdf fdf)
{
	size_t	x;
	size_t	y;
	t_point	point;

	x = 0;
	while (x < fdf.map_x)
	{
		y = 0;
		while (y < fdf.map_y)
		{
			point = get_cord_x(fdf, x, y);
			draw_line(fdf, point);
			point = get_cord_y(fdf, x, y);
			draw_line(fdf, point);
			y++;
		}
		x++;
	}
}
