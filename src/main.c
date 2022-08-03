/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/12 20:13:26 by mweverli      #+#    #+#                 */
/*   Updated: 2022/08/03 14:30:07 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include <stdlib.h>
#include <stdio.h>
#define WIDTH 256
#define HEIGHT 256

static mlx_image_t	*g_img;

void	hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
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

int32_t main(void)
{
	int y = 0;
	int x = 0;
	int a = 150;
	mlx_t	*mlx;

	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!mlx)
		exit(EXIT_FAILURE);

	g_img = mlx_new_image(mlx, WIDTH, HEIGHT); //creates a new image of WIDTHxHEIGT
	
	while ((x + 64) < HEIGHT && (x - a) <= 0) // x <= a
	{
		while ((y + 64) < WIDTH && (y - a) <= 0)
		{
			mlx_put_pixel(g_img, 64 + x, 64 + y, 0x00000080); // Single white pixel in the middle.
			y++;
		}
		y = 0;
		x++;
	}

	mlx_image_to_window(mlx, g_img, 0, 0);  // Adds an image to the render queue.
	mlx_loop_hook(mlx, &hook, mlx);
	mlx_loop(mlx);

	mlx_delete_image(mlx, g_img); // Once the application request an exit, cleanup.

	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
