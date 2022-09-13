/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_init_utils.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/31 16:58:55 by mweverli      #+#    #+#                 */
/*   Updated: 2022/09/13 17:25:39 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	skiphex(char *str)
{
	size_t i;

	i = 0;
	if (str[i] == ',')
		i++;
	while (ft_isalnum(str[i]))
		i++;
	return (i);
}

int	skipnumb(char *str)
{
	size_t i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
		i++;
	return (i);
}

int	return_fd(const char *f_name)
{
	int			fd;
	const char	*dir;
	char		*path;

	path = NULL;
	dir = "maps/";
	if (!ft_strnstr(f_name, "maps/", 7))
	{
		path = ft_strjoin(dir, f_name);
		if (!path)
			fdf_exit(1, "fdf_init_utils/return_fd");
		fd = open(path, O_RDONLY);
		free(path);
	}
	else
		fd = open(f_name, O_RDONLY);
	if (fd == -1)
		fdf_exit(1, "fdf_init/return_fd");
	return (fd);
}

int	get_pval(t_fdf *fdf, char *str, int index)
{
	int i;

	fdf->pval[index].x = (float) (index % fdf->map_x);
	fdf->pval[index].y = (float) (index / fdf->map_x);
	fdf->pval[index].z = (float) ft_atoi(str);
	i = skipnumb(str);
	return (i);
}
