/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_init.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/25 11:21:58 by mweverli      #+#    #+#                 */
/*   Updated: 2022/09/04 01:19:22 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdf_init_utils.h"

char	*get_linemap(int fd)
{
	char	*tmp;
	char	*line_map;
	char	buf[10001];
	size_t	read_ret;

	line_map = ft_calloc(1, 1);
	read_ret = read(fd, buf, 10000);
	while (read_ret != 0)
	{
		buf[read_ret] = '\0';
		tmp = ft_strjoin(line_map, buf);
		if (!tmp)
			fdf_exit(1, "fdf_init/get_linemap");
		free(line_map);
		line_map = tmp;
		read_ret = read(fd, buf, 10000);
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
		if (str[i] == ',')
			i += skiphex(&str[i]);
		i++;
	}
	while (str[i])
	{
		if (str[i] == '\n')
			fdf->map_y++;
		i++;
	}
}

void	init_map(t_fdf *fdf, char *str)
{
	size_t	i;
	size_t	index_int;

	i = 0;
	index_int = 0;
	fdf->intmap = malloc(sizeof(int) * (fdf->map_x * fdf->map_y));
	fdf->dimmap = malloc(sizeof(t_dimmap) * (fdf->map_x * fdf->map_y));
	if (!fdf->intmap || !fdf->dimmap)
		fdf_exit(1, "fdf_init/init_map");
	while (str[i])
	{
		if (ft_isdigit((int) str[i]) || str[i] == '-')
		{
			fdf->intmap[index_int] = ft_atoi(&str[i]);
			fdf->dimmap[index_int].x = (float) (index_int % fdf->map_x);
			fdf->dimmap[index_int].y = (float) (index_int / fdf->map_y);
			fdf->dimmap[index_int].z = (float) fdf->intmap[index_int];
			printf("fdf->dim:%zu\t%f %f %f\n", index_int, fdf->dimmap[index_int].x, fdf->dimmap[index_int].y, fdf->dimmap[index_int].z);
			i += skipnumb(&str[i]);
			index_int++;
		}
		if (str[i] == ',')
			i += skiphex(&str[i]);
		i++;
	}
}

void	init_colmap(t_fdf *fdf, char *str)
{
	size_t	i;
	size_t	index_int;

	i = 0;
	index_int = 0;
	fdf->colmap = malloc(sizeof(int) * (fdf->map_x * fdf->map_y));
	if (!fdf->intmap || !fdf->dimmap)
		fdf_exit(1, "fdf_init/get_colmap");
	while (str[i])
	{
		if (ft_isdigit((int) str[i]))
		{
			index_int++;
			i += skipnumb(&str[i]);
		}
		if (str[i] == ',')
		{
			fdf->colmap[index_int] = 10;
			i += skiphex(&str[i]);
		}
		i++;
	}
}

t_fdf	fdf_init(const char *f_name)
{
	t_fdf	fdf;
	int		fd;
	char	*line_map;

	fd = return_fd(f_name);
	line_map = get_linemap(fd);
	get_mapdimention(&fdf, line_map);
	init_map(&fdf, line_map);
	init_colmap(&fdf, line_map);

	free(line_map);
	close(fd);
	return (fdf);
}
