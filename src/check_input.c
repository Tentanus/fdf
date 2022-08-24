/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_input.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/24 20:32:37 by mweverli      #+#    #+#                 */
/*   Updated: 2022/08/24 22:15:28 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

void	check_input(const char *f_name)
{
	size_t		len;

	inc = "./maps/";
	len = ft_strlen(f_name) - 4;
	if (len == 0 || ft_strncmp(&f_name[len], ".fdf", 4))
		fdf_exit(2, "check_input");
}
