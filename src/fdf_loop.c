/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_loop.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/22 18:10:06 by mweverli      #+#    #+#                 */
/*   Updated: 2022/09/28 14:48:29 by mweverli      ########   odam.nl         */
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
*/

static void	fdf_key_move(mlx_key_data_t keydata, t_fdf *fdf)
{
	if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		fdf->vval.offset_x += 10;
	if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		fdf->vval.offset_x -= 10;
	if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		fdf->vval.offset_y -= 10;
	if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		fdf->vval.offset_y += 10;
}

static void	fdf_key_zoom(mlx_key_data_t keydata, t_fdf *fdf)
{
	if (keydata.key == MLX_KEY_EQUAL)
		fdf->vval.scale += 5;
	if (keydata.key == MLX_KEY_MINUS)
		fdf->vval.scale -= 5;
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

	if (keydata.action == MLX_RELEASE)
		return ;
	fdf_cast = fdf;
	fdf_key_zoom(keydata, fdf_cast);
	fdf_key_move(keydata, fdf_cast);
	fdf_compute(fdf);
	ft_bzero(fdf_cast->img->pixels,
		(fdf_cast->img->width * fdf_cast->img->height * sizeof(uint32_t)));
	fdf_render(fdf);
}

void	fdf_loop(t_fdf *fdf)
{
	fdf_compute(fdf);
	fdf_render(fdf);
	mlx_image_to_window(fdf->mlx, fdf->img, 0, 0);
	mlx_key_hook(fdf->mlx, &fdf_key_hook, (void *)fdf);
	mlx_loop(fdf->mlx);
}
