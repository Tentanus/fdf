/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_defaults.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/13 17:37:32 by mweverli      #+#    #+#                 */
/*   Updated: 2022/09/14 15:30:50 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdf_init_utils.h"

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
	return (abs(z_max) - abs(z_min));
}

void	set_defaults(t_fdf *fdf)
{
	fdf->scale = SCALE;
	fdf->z_scale = get_z_scale(fdf);
	fdf->def.offset_x = (WINDOW_WIDTH / 2);
	fdf->def.offset_y = (WINDOW_HEIGHT / 2);
}

