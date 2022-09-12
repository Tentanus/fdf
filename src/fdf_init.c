/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_init.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/25 11:21:58 by mweverli      #+#    #+#                 */
/*   Updated: 2022/09/06 20:30:06 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdf_init_utils.h"
#include "MLX42.h"

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

void	init_pval(t_fdf *fdf, char *str)
{
	size_t	i;
	size_t	index_int;

	i = 0;
	index_int = 0;
	fdf->pval = malloc(sizeof(t_pval) * (fdf->map_x * fdf->map_y));
	if (!fdf->pval)
		fdf_exit(1, "fdf_init/init_pval");
	while (str[i])
	{
		if (ft_isdigit((int) str[i]) || str[i] == '-')
		{
			fdf->pval[index_int].x = (float) (index_int % fdf->map_x);
			fdf->pval[index_int].y = (float) (index_int / fdf->map_x);
			fdf->pval[index_int].z = (float) ft_atoi(&str[i]);
			i += skipnumb(&str[i]);
			if (str[i] == ',')
				i += get_colour(fdf->pval[index_int], &str[i]);
			else
				fdf->pval[index_int].col = 0xFFFFFF;
			index_int++;
		}
		else
			i++;
	}
}

t_fdf	fdf_init(const char *f_name)
{
	t_fdf			fdf;
	int				fd;
	char			*line_map;

	fd = return_fd(f_name);
	line_map = get_linemap(fd);
	get_mapdimention(&fdf, line_map);
	set_defaults(fdf);
	init_pval(&fdf, line_map);
	free(line_map);
	close(fd);
	return (fdf);
}
