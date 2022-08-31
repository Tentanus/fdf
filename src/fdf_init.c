/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_init.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/25 11:21:58 by mweverli      #+#    #+#                 */
/*   Updated: 2022/08/31 13:30:12 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	return_fd(const char *f_name)
{
	int			fd;
	const char	*dir;
	char		*path;

	dir = "./maps/";
	path = ft_strjoin(dir, f_name);
	fd = open(path, O_RDONLY);
	free(path);
	if (fd == -1)
		fdf_exit(3, "fddf_init");
	return (fd);
}

char	*get_linemap(int fd, t_fdf *fdf)
{
	char	*tmp;
	char	*line_map;
	char	buf[10001];
	size_t	read_ret;

	fdf->map_height = 0;
	fdf->map_width = 0;
	line_map = ft_calloc(1, 1);
	read_ret = read(fd, buf, 10000);
	while (read_ret != 0)
	{
		buf[read_ret] = '\0';
		tmp = ft_strjoin_fs1(line_map, buf);
		if (!tmp)
			return (NULL);
		free(line_map);
		line_map = tmp;
		read_ret = read(fd, buf, 10000);
	}
	return (line_map);
}

t_fdf	fdf_init(const char *f_name)
{
	t_fdf	fdf;
	int		fd;

	fd = return_fd(f_name);
	fdf.line_map = get_linemap(fd, &fdf);
	close(fd);
	return (fdf);
}
