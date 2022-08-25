/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_init.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/25 11:21:58 by mweverli      #+#    #+#                 */
/*   Updated: 2022/08/25 18:15:06 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "fdf.h"
#include "libft.h"

t_fdf	*fdf_init(const char *f_name)
{
	int			fd;
	const char	*dir;
	char		*paht;


	dir = "./maps/";
	path = ft_strjoin(dir, f_name);
	fd = open(path, O_RDONLY);
	free(path);
	if (fd == -1)
		fdf_exit(3, "fdf_init");

	close(fd);
	return (NULL);
}
