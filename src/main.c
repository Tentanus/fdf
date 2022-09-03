/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/01 18:32:50 by mweverli      #+#    #+#                 */
/*   Updated: 2022/09/04 01:26:21 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static mlx_image_t	*g_img;

void	hook(void *param)
{
	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
		mlx_close_window(param);
	if (mlx_is_key_down(param, MLX_KEY_UP))
		g_img->instances[0].y -= 5;
	if (mlx_is_key_down(param, MLX_KEY_DOWN))
		g_img->instances[0].y += 5;
	if (mlx_is_key_down(param, MLX_KEY_LEFT))
		g_img->instances[0].x -= 5;
	if (mlx_is_key_down(param, MLX_KEY_RIGHT))
		g_img->instances[0].x += 5;
}

void	check_input(const char *f_name)
{
	size_t		len;

	len = ft_strlen(f_name) - 4;
	if (len <= 0 || ft_strncmp(&f_name[len], ".fdf", 4))
		fdf_exit(3, "check_input");
}

int32_t main(int argc, char **argv)
{
	t_fdf	fdf;

	if (argc != 2)
		fdf_exit(2, "main");
	else
	{
		check_input(argv[1]);
		fdf = fdf_init(argv[1]);
	}
	for (int i = 0; i < (int) (fdf.map_x * fdf.map_y); i++)
	{
//		printf("int: %d\n", fdf.intmap[i]);
//		printf("dim: %f %f %f\n", fdf.dimmap[i].x, fdf.dimmap[i].y, fdf.dimmap[i].z);
		printf("dim:\t%f\t%f\t%f\n", fdf.dimmap[i].x, fdf.dimmap[i].y , fdf.dimmap[i].z);
	}
}


