/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_colour.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/03 13:54:25 by mweverli      #+#    #+#                 */
/*   Updated: 2022/09/28 18:35:34 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <fdf_utils.h>

int	get_gradient(int c0, int c1, float per)
{
	return ((int)((1 - per) * c0 + (per * c1)));
}

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
		return (1.0);
	return (dist / max_dist);
}

uint32_t	get_col_gradient(t_pval p0, t_pval p1, t_draw draw)
{
	float			per;
	t_cval			cval;
	uint32_t		ret;

	if (p0.col == p1.col)
		return (p0.col | 0xFF);
	if (draw.dx > draw.dy)
		per = get_percent(p0.x, p1.x, draw.x_err);
	else
		per = get_percent(p0.y, p1.y, draw.y_err);
	cval.r = get_gradient(((p0.col >> 24) & 0xFF),
			((p1.col >> 24) & 0xFF), per);
	cval.g = get_gradient(((p0.col >> 16) & 0xFF),
			((p1.col >> 16) & 0xFF), per);
	cval.b = get_gradient(((p0.col >> 8) & 0xFF),
			((p1.col >> 8) & 0xFF), per);
	ret = get_rgb(cval.r, cval.g, cval.b) | 0xFF;
	return (ret);
}

int	get_cval(t_pval *pval, char *str)
{
	t_cval		cval;
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
