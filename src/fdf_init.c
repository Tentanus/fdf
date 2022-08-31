/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_init.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/25 11:21:58 by mweverli      #+#    #+#                 */
/*   Updated: 2022/08/31 19:49:42 by mweverli      ########   odam.nl         */
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
		tmp = ft_strjoin_fs1(line_map, buf);
		if (!tmp)
			return (free(line_map), NULL);
		line_map = tmp;
		read_ret = read(fd, buf, 10000);
	}
	free(tmp);
	return (line_map);
}

void	get_mapdimention(t_fdf *fdf, char *line_map)
{
	size_t	i;

	fdf->map_x = 0;
	fdf->map_y = 0;
	if (line_map == NULL)
		fdf_exit(4, "fdf_init/mapdimention");
	i = 0;
	while (line_map[i] != '\n' && line_map[i])
	{
		if (ft_isdigit(line_map[i]))
			fdf->map_x++;
		if (line_map[i] == ',')
			i += skiphex(&line_map[i]);
		i++;
	}
	while (line_map[i])
	{
		if (line_map[i] == '\n')
			fdf->map_y++;
		i++;
	}
}

void	init_map(t_fdf *fdf, char *line_map)
{
	size_t i;
	size_t x;
	size_t y;

	i = 0;
	x = 0;
	y = 0;
	fdf->dimmap = malloc(sizeof(t_dimmap) * (fdf->map_x * fdf->map_y));
	fdf->intmap = malloc(sizeof(int) * (fdf->map_x * fdf->map_y));
	line_map = NULL;
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

	free(line_map);
	close(fd);
	return (fdf);
}
