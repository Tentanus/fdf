/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_colour.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/03 13:54:25 by mweverli      #+#    #+#                 */
/*   Updated: 2022/09/26 20:18:01 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <fdf_utils.h>

int	get_gradient(int c0, int c1, float per)
{
	return ((int)((1 - per) * c0 + (per * c1)));
}

// get_rgb might be too large for data_type.
// check if mlx needs rgb vs. rgba

int	get_rgb(int r, int g, int b)
{
	return (r << 24 | g << 16 | b << 8);
}

float	get_percent(int p_min, int p_max, int p_cur)
{
	float	dist;
	float	max_dist;

	dist = p_cur - p_min;
	max_dist = p_max - p_min;
	if (max_dist == 0)
		return (1);
	return (dist / max_dist);
}

uint32_t	get_col_gradient(t_pval p0, t_pval p1, t_draw draw)
{
//	float			per;
	t_cval			cval;
	uint32_t		ret;

//	if (p0.col == p1.col)
//		return ((p0.col << 8) | 0x000000FF);
//	if (draw.dx > draw.dy)
//		per = get_percent(p0.x, p1.x, draw.dx);
//	else
//		per = get_percent(p0.y, p1.y, draw.dy);
//	per = 1;
//	ft_printf("%X\t%X\n", p0.col, p1.col);
	draw.dx = 0;
	p1.col = 0;
	cval.r = ((p0.col >> 16) & 0xFF);
	cval.g = ((p0.col >> 8) & 0xFF);
	cval.b = ((p0.col >> 0) & 0xFF);
	ret = get_rgb(cval.r, cval.g, cval.b) | 0xFF;
//	ft_printf("%X\t%X\t%X\t\t%X\n",cval.r, cval.g, cval.b, ret);
	return (ret);
}

int	get_cval(t_pval *pval, char *str)
{
	t_cval	cval;
	int			i;
	uint32_t	hex;

	i = skiphex(str);
	if (*str == ',')
		str++;
	hex = ft_htoi(str);
	cval.r = ((hex >> 16) & 0xFF);
	cval.g = ((hex >> 8) & 0xFF);
	cval.b = (hex & 0xFF);
	pval->col = get_rgb(cval.r, cval.g, cval.b);
	return (i);
}
