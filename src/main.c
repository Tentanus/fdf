/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/01 18:32:50 by mweverli      #+#    #+#                 */
/*   Updated: 2022/09/06 20:30:20 by mweverli      ########   odam.nl         */
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
		check_idnput(argv[1]);
		fdf = fdf_init(argv[1]);
		fdf.mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, f_name, true);
		fdf.img = mlx_new_image(fdf.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
		if (!(fdf.mlx) || !(fdf.img))
			fdf_exit(1, "main @ mlx alloc");
	}


//	
//	//TESTS 
//	//INIT FDF: 
//		printf("int: %zu x %zu\n", fdf.map_x, fdf.map_y);
//		for (int i = 0; i < (int) (fdf.map_x * fdf.map_y); i++)
//		{
//	//		printf("int: %d\n", fdf.intmap[i]);
//			printf("dim:\t%d\t%f\t%f\t%f\n", i, fdf.pval[i].x, fdf.pval[i].y , fdf.pval[i].z);
//			printf("col:\t\t%X\n", fdf.pval[i].col);
//		}
//	
return (1);
}


