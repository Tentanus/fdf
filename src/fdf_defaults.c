/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_defaults.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/13 17:37:32 by mweverli      #+#    #+#                 */
/*   Updated: 2022/10/01 17:21:45 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <fdf_utils.h>

void	center_map_y(t_fdf *fdf)
{
	t_pval	min;
	t_pval	max;

	while (1)
	{
		min = compute_isometric(fdf, 0);
		max = compute_isometric(fdf, (fdf->map_x * fdf->map_y - 1));
		if (ft_abs(max.y - min.y) < (WINDOW_HEIGHT - 2 * BORDER))
			break ;
		fdf->vval.scale--;
	}
	fdf->vval.offset_y = (WINDOW_HEIGHT  / 2) - (ft_abs(max.y - min.y) / 2);
	while (min.y < BORDER || max.y > (WINDOW_HEIGHT - BORDER))
	{
		min = compute_isometric(fdf, 0);
		max = compute_isometric(fdf, (fdf->map_x * fdf->map_y - 1));
		if (max.y > (WINDOW_HEIGHT - BORDER))
			fdf->vval.offset_y -= 5;
		if (min.y < BORDER)
			fdf->vval.offset_y += 5;
	}
}

void	center_map_x(t_fdf *fdf)
{
	t_pval	left;
	t_pval	right;

	while (1)
	{
		left = compute_isometric(fdf, ((fdf->map_y - 1) * fdf->map_x));
		right = compute_isometric(fdf, fdf->map_x - 1);
		if (ft_abs(right.x - left.x) < (WINDOW_WIDTH - 2 * BORDER))
			break ;
		fdf->vval.scale--;
	}
	fdf->vval.offset_x = (WINDOW_WIDTH / 2);
	while (left.x < BORDER || right.x > (WINDOW_WIDTH - BORDER))
	{
		left = compute_isometric(fdf, ((fdf->map_y - 1) * fdf->map_x));
		right = compute_isometric(fdf, fdf->map_x - 1);
		if (right.x > (WINDOW_WIDTH - BORDER))
			fdf->vval.offset_x -= 5;
		if (left.x < BORDER)
			fdf->vval.offset_x += 5;
	}
}

void	set_defaults(t_fdf *fdf)
{
	fdf->vval.offset_x = 0;
	fdf->vval.offset_y = 0;
	fdf->vval.scale = SCALE;
	fdf->vval.z_scale = Z_SCALE;
	fdf->vval.angle = 0.523599;
	center_map_x(fdf);
	center_map_y(fdf);
}
