/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_defaults.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/13 17:37:32 by mweverli      #+#    #+#                 */
/*   Updated: 2022/09/19 18:53:28 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdf_init.h"
#include "libft.h"

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

	fdf_max = fdf->map_x * fdf->map_y;
	while (1)
	{
		min = render_isometric(fdf, 0);
		max = render_isometric(fdf, fdf_max);
		fdf->offset_x = (WINDOW_WIDTH / 2) - (ft_abs(min.x - max.x) / 2);
		fdf->offset_y = (WINDOW_HEIGHT / 2) - (ft_abs(min.y - max.y) / 2);
		if (ft_abs(min.x - max.x) > WINDOW_WIDTH 
				|| ft_abs(min.y - max.y) > WINDOW_HEIGHT)
		{
			fdf->scale -= 1;
			continue;
		}
		break;
	}
}

void	set_defaults(t_fdf *fdf)
{
	fdf->scale = SCALE;
	fdf->z_scale = get_z_scale(fdf);
	get_offset(fdf);
	fdf->pov = ISOMETRIC;
}

