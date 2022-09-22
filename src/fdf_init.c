/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_init.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/25 11:21:58 by mweverli      #+#    #+#                 */
/*   Updated: 2022/09/22 18:12:49 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <fdf_utils.h>

char	*get_linemap(int fd)
{
	char	*tmp;
	char	*line_map;
	char	buf[10001];
	size_t	read_ret;

	line_map = ft_calloc(1, 1);
	read_ret = read(fd, buf, 10000);
	buf[read_ret] = '\0';
	while (read_ret != 0)
	{
		buf[read_ret] = '\0';
		tmp = ft_strjoin(line_map, buf);
		if (!tmp)
			fdf_exit(1, "fdf_init/get_linemap");
		free(line_map);
		line_map = tmp;
		read_ret = read(fd, buf, 10000);
		buf[read_ret] = '\0';
	}
	return (line_map);
}

void	get_mapdimention(t_fdf *fdf, char *str)
{
	size_t	i;

	fdf->map_x = 0;
	fdf->map_y = 0;
	i = 0;
	while (str[i] != '\n')
	{
		if (ft_isdigit(str[i]))
		{
			fdf->map_x++;
			i += skipnumb(&str[i]);
		}
		else if (str[i] == ',')
			i += skiphex(&str[i]);
		else
			i++;
	}
	while (str[i])
	{
		if (str[i] == '\n')
			fdf->map_y++;
		i++;
	}
}

void	init_val(t_fdf *fdf, char *str)
{
	size_t	i;
	size_t	index;

	i = 0;
	index = 0;
	fdf->pval = ft_calloc(sizeof(t_pval), ((fdf->map_x * fdf->map_y) + 1));
	if (!fdf->pval)
		fdf_exit(1, "fdf_init/init_val");
	while (str[i])
	{
		if (ft_isdigit(str[i]) || str[i] == '-')
		{
			i += get_pval(fdf, &str[i], index);
			if (str[i] == ',')
				i += get_cval(&(fdf->pval[index]), &str[i]);
			else
				get_cval(&(fdf->pval[index]), "0xFFFFFF");
			index++;
		}
		else
			i++;
	}
}

t_fdf	fdf_init(const char *f_name)
{
	t_fdf	fdf;
	int		fd;
	char	*line_map;

	fd = return_fd(f_name); // add .fdf.fdf fix
	line_map = get_linemap(fd);
	close(fd);
	get_mapdimention(&fdf, line_map);
	init_val(&fdf, line_map);
	free(line_map);
	set_defaults(&fdf);
	fdf.mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, f_name, true);
	fdf.img = mlx_new_image(fdf.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
		if (!(fdf.mlx) || !(fdf.img))
			fdf_exit(1, "fdf_init @ mlx alloc");
	return (fdf);
}
