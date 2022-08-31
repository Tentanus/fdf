/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_init_utils.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/31 16:58:55 by mweverli      #+#    #+#                 */
/*   Updated: 2022/08/31 19:49:44 by mweverli      ########   odam.nl         */
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
		fdf_exit(1, "fdf_init/return_fd");
	return (fd);
}
