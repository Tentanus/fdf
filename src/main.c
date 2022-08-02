/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/12 20:13:26 by mweverli      #+#    #+#                 */
/*   Updated: 2022/08/02 15:22:35 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include <stdlib.h>
#include <stdio.h>
#define WIDTH 256
#define HEIGHT 256

static mlx_image_t	*g_img;

int32_t main(void)
{
	int i = 0;
	mlx_t	*mlx;

	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!mlx)
		exit(EXIT_FAILURE);

	g_img = mlx_new_image(mlx, WIDTH, HEIGHT); //creates a new image of WIDTHxHEIGT
	mlx_image_to_window(mlx, g_img, 0, 0);  // Adds an image to the render queue.

	while (i < WIDTH)
	{
		mlx_put_pixel(g_img, 64, i, 0x008080FF); // Single white pixel in the middle.
		i++;
	}
	mlx_loop(mlx);

	mlx_delete_image(mlx, g_img); // Once the application request an exit, cleanup.

	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
