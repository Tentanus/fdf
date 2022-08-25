/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/01 18:32:50 by mweverli      #+#    #+#                 */
/*   Updated: 2022/08/25 18:15:23 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
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

int32_t main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc != 2)
		fdf_exit(1, "main");
	else
	{
		check_input(argv[1]);
		fdf = fdf_init(argv[1]);
	}
	
}
