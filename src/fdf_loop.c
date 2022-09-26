/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_loop.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/22 18:10:06 by mweverli      #+#    #+#                 */
/*   Updated: 2022/09/26 20:27:49 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
/*
void	fdf_clean_up(t_fdf *fdf)
{
	mlx_close_window(fdf->mlx);
	mlx_terminate(fdf->mlx);
	mlx_delete_image(fdf->mlx, fdf->img);
}


static void	fdf_key_move(mlx_key_data_t keydata, t_fdf *fdf)
{
	
}
*/
static void	fdf_key_zoom(mlx_key_data_t keydata, t_fdf *fdf)
{
	if (keydata.action == MLX_RELEASE)
		return ;
	if (keydata.key == MLX_KEY_EQUAL)
	{
		fdf->vval.scale += 5;
		fdf->vval.z_scale += 2;
	}
	if (keydata.key == MLX_KEY_MINUS)
	{
		fdf->vval.scale -= 5;
		fdf->vval.z_scale -= 2; 
	}
	if (keydata.key == MLX_KEY_P)
		fdf->vval.z_scale += 2;
	if (keydata.key == MLX_KEY_O)
		fdf->vval.z_scale -= 2; 
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(fdf->mlx);
}

static void	fdf_key_hook(mlx_key_data_t keydata, void *fdf)
{
	t_fdf	*fdf_cast;

	fdf_cast = fdf;
	fdf_key_zoom(keydata, fdf_cast);
	ft_bzero(fdf_cast->img->pixels,
		(fdf_cast->img->width * fdf_cast->img->height * sizeof(uint32_t)));
	fdf_render(fdf);
	fdf_draw(fdf);
	mlx_image_to_window(fdf_cast->mlx, fdf_cast->img, 0, 0);
}

void	fdf_loop(t_fdf *fdf, mlx_image_t *img)
{
	ft_bzero(img->pixels, (img->width * img->height * sizeof(uint32_t)));
	fdf_render(fdf);
	mlx_image_to_window(fdf->mlx, fdf->img, 0, 0);
	fdf_draw(fdf);
	mlx_key_hook(fdf->mlx, &fdf_key_hook, (void *)fdf);
	mlx_loop(fdf->mlx);
}
