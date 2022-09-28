/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_defaults.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/13 17:37:32 by mweverli      #+#    #+#                 */
/*   Updated: 2022/09/28 18:36:54 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <fdf_utils.h>

void	get_offset(t_fdf *fdf)
{
	t_pval	min;
	t_pval	max;
	int		fdf_max;

	fdf_max = (fdf->map_x * fdf->map_y - 1);
	while (1)
	{
		min = compute_isometric(fdf, 0);
		max = compute_isometric(fdf, fdf_max);
		fdf->vval.offset_x = (WINDOW_WIDTH / 2) - (ft_abs(max.x - min.x) / 2);
		fdf->vval.offset_y = (WINDOW_HEIGHT / 2) - (ft_abs(max.y - min.y) / 2);
		if (ft_abs(max.x - min.x) > WINDOW_WIDTH
			|| ft_abs(max.y - min.y) > WINDOW_HEIGHT)
		{
			fdf->vval.scale--;
			continue ;
		}
		break ;
	}
}

void	center_map(t_fdf *fdf)
{
	t_pval	left;
	t_pval	right;

	while (1)
	{
		left = compute_isometric(fdf, fdf->map_x);
		right = compute_isometric(fdf, fdf->map_x - 1);
		fdf->vval.offset_x = (WINDOW_WIDTH / 2)
			- (ft_abs(right.x - left.x) / 2);
		if (ft_abs(right.x - left.x) > WINDOW_WIDTH)
		{
			fdf->vval.scale--;
			continue ;
		}
		break ;
	}
}

void	get_z_scale(t_fdf *fdf)
{
	t_pval	top;
	int		index;
	int		y_top;
	int		index_top;

	fdf->vval.z_scale = Z_SCALE;
	index = 0;
	y_top = 0;
	while (index < (int)(fdf->map_x * fdf->map_y))
	{
		top = compute_isometric(fdf, index);
		if (top.y < y_top)
		{
			y_top = top.y;
			index_top = index;
		}
		index++;
	}
	while (1)
	{
		top = compute_isometric(fdf, index_top);
		if (top.y > 0)
			break ;
		fdf->vval.z_scale--;
	}
}

void	set_defaults(t_fdf *fdf)
{
	fdf->vval.offset_x = WINDOW_WIDTH / 2;
	fdf->vval.offset_y = WINDOW_HEIGHT / 2;
	fdf->vval.scale = SCALE;
	fdf->vval.angle = 0.523599;
	center_map(fdf);
	get_offset(fdf);
	get_z_scale(fdf);
}
