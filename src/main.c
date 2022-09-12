/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/01 18:32:50 by mweverli      #+#    #+#                 */
/*   Updated: 2022/09/12 19:45:11 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
		printf("init ok\n");
		fdf.mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, argv[1], true);
		fdf.img = mlx_new_image(fdf.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
		if (!(fdf.mlx) || !(fdf.img))
			fdf_exit(1, "main @ mlx alloc");
//		fdf_render(fdf);
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
	mlx_close_window(fdf.mlx);
	mlx_terminate(fdf.mlx);
return (1);
}


