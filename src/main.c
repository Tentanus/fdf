/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/12 20:13:26 by mweverli      #+#    #+#                 */
/*   Updated: 2022/07/12 20:44:00 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include "../include/MLX42.h"
#include <stdlib.h>
#include <stdio.h>
#define WIDTH 256
#define HEIGHT 256

int32_t main(void)
{
	mlx_t	*mlx;

	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
