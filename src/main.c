/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/01 18:32:50 by mweverli      #+#    #+#                 */
/*   Updated: 2022/09/26 14:40:12 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	check_input(const char *f_name)
{
	size_t		len;

	len = ft_strlen(f_name) - 4;
	if (len <= 0 || ft_strncmp(&f_name[len], ".fdf", 4))
		fdf_exit(3, "main.c @ check_input");
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
		fdf_loop(&fdf, fdf.img);
	}
	mlx_close_window(fdf.mlx);
	mlx_terminate(fdf.mlx);
	free(fdf.pval);
return (1);
}
