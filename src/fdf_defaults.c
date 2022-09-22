/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_defaults.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/13 17:37:32 by mweverli      #+#    #+#                 */
/*   Updated: 2022/09/22 19:12:11 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <fdf_utils.h>

int	get_z_scale(t_fdf *fdf)
{
	int		z_min;
	int		z_max;
	size_t	i;

	z_min = 0;
	z_max = 0;
	i = 0;
	while (i < (fdf->map_x * fdf->map_y))
	{
		if (fdf->pval[i].z < z_min)
			z_min = fdf->pval[i].z;
		if (fdf->pval[i].z > z_max)
			z_max = fdf->pval[i].z;
		i++;
	}
	return (ft_abs(z_max - z_min));
}

void	get_offset(t_fdf *fdf)
{
	t_pval	min;
	t_pval	max;
	int		fdf_max;

	fdf_max = (fdf->map_x * fdf->map_y - 1);
	while (1)
	{
		min = render_isometric(fdf, 0);
		max = render_isometric(fdf, fdf_max);
		fdf->vval.offset_x = (WINDOW_WIDTH / 2) - (ft_abs(max.x - min.x) / 2);
		fdf->vval.offset_y = (WINDOW_HEIGHT / 2) - (ft_abs(max.y - min.y) / 2);
		if (ft_abs(max.x - min.x) > WINDOW_WIDTH 
				|| ft_abs(max.y - min.y) > WINDOW_HEIGHT)
		{
			fdf->vval.scale--;
			continue;
		}
		break;
	}
}

void	set_defaults(t_fdf *fdf)
{
	fdf->vval.scale = SCALE;
	fdf->vval.z_scale = get_z_scale(fdf);
	fdf->vval.angle = 0.523599;
	get_offset(fdf);
}

