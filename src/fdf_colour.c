/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_colour.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/03 13:54:25 by mweverli      #+#    #+#                 */
/*   Updated: 2022/09/19 14:28:47 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

int	get_rgb(int r, int g, int b)
{
	return (r << 24 | g << 16 | b << 8 | 0x00);
}

int	get_cval(t_cval *cval, char *str)
{
	int i;

	i = skiphex(str);
	if (*str == ',')
		str++;
	cval->r = (ft_htoi(str) >> 16 & 0xFF);
	cval->g = ((ft_htoi(str) >> 8) & 0xFF);
	cval->b = (ft_htoi(str) & 0xFF);
	cval->col = get_rgb(cval->r, cval->g, cval->b);
	return (i);
}
