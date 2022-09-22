/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_draw.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/14 12:00:25 by mweverli      #+#    #+#                 */
/*   Updated: 2022/09/22 19:12:14 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <fdf_utils.h>

int	ft_ternary(int bol, int t, int f)
{
	if (bol)
		return (t);
	return (f);
}

t_draw	setup_draw(t_pval p0, t_pval p1)
{
	t_draw	draw;

	draw.dx = ft_abs(p1.x - p0.x);
	draw.dy = ft_abs(p1.y - p0.y);
	draw.x_sign = ft_ternary(p0.x < p1.x, 1, -1);
	draw.y_sign = ft_ternary(p0.y < p1.y, 1, -1);
	draw.x_err = p0.x;
	draw.y_err = p0.y;
	return (draw);
}
// p0 & p1 are unclear but 
void	draw_line(t_fdf *fdf, t_pval p0, t_pval p1)
{
	t_draw	draw;
	int		check;

	draw = setup_draw(p0, p1);
	check = 2 * (draw.dy - draw.dx);
	while (1)
	{
		mlx_put_pixel(fdf->img, draw.x_err, draw.y_err,
			(get_col_gradient(p0, p1, draw)));
		if (draw.x_err == p1.x || draw.y_err == p1.y)
			break;
		if (check >= 0)
		{
			draw.y_err += draw.y_sign;
			check += 2 * draw.dx;
		}
		if (check < 0)
		{
			draw.x_err += draw.x_sign;
			check += 2 * draw.dy;
		}
	}
}

void	fdf_draw(t_fdf *fdf)
{
	size_t	x;
	size_t	y;
	size_t	index;

	y = 0;
	while (y < fdf->map_y)
	{
		x = 0;
		while (x < (fdf->map_x - 1))
		{
			index = (y * fdf->map_x) * x++;
			draw_line(fdf, fdf->pval[index], fdf->pval[index + 1]);
			if (y < (fdf->map_y - 1))
				draw_line(fdf, fdf->pval[index],
					fdf->pval[index + fdf->map_x]);
		}
		if (y < (fdf->map_y - 1))
			draw_line(fdf, fdf->pval[index + 1],
				fdf->pval[index + fdf->map_x + 1]);
		y++;
	}
}
