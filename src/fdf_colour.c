/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_colour.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/03 13:54:25 by mweverli      #+#    #+#                 */
/*   Updated: 2022/09/05 18:34:28 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

int	get_rgb(int r, int g, int b)
{
	return (r << 24 | g << 16 | b << 8 | 0x00);
}

int	get_colour(t_pval pval, char *str)
{
	int i;

	i = 0;
	if (*str == ',')
	{
		str++;
		i++;
	}
	i = skiphex(str);
	pval.r = (ft_htoi(str) >> 16 & 0xFF);
	pval.g = ((ft_htoi(str) >> 8) & 0xFF);
	pval.b = (ft_htoi(str) & 0xFF);
	pval.col = get_rgb(pval.r, pval.g, pval.b);
//	printf("r: %X\tg: %X\tb: %X\tcol: %X\n", pval.r, pval.g, pval.b, pval.col);
	return (i);
}
