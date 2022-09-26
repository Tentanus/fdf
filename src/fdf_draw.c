/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_draw.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/14 12:00:25 by mweverli      #+#    #+#                 */
/*   Updated: 2022/09/26 20:17:58 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <fdf_utils.h>

t_draw	setup_draw(t_pval p0, t_pval p1)
{
	t_draw	draw;

	draw.dx = ft_abs(p1.x - p0.x);
	draw.dy = -ft_abs(p1.y - p0.y);
	draw.x_sign = ft_ternary(p0.x < p1.x, 1, -1);
	draw.y_sign = ft_ternary(p0.y < p1.y, 1, -1);
	draw.x_err = p0.x;
	draw.y_err = p0.y;
	draw.err = draw.dx + draw.dy;
	return (draw);
}

void	draw_line(t_fdf *fdf, t_pval p0, t_pval p1)
{
	t_draw	draw;
	int		err2;

	draw = setup_draw(p0, p1);
	while (1)
	{
		if ((draw.x_err < WINDOW_WIDTH && draw.x_err > 0) &&
			(draw.y_err < WINDOW_HEIGHT && draw.y_err > 0))
			mlx_put_pixel(fdf->img, draw.x_err, draw.y_err, 0xFFFFFFFF);
		if (draw.x_err == p1.x && draw.y_err == p1.y)
			break ;
		err2 = 2 * draw.err;
		if (err2 >= draw.dy)
		{
			draw.err += draw.dy;
			draw.x_err += draw.x_sign;
		}
		if (err2 <= draw.dx)
		{
			draw.err += draw.dx;
			draw.y_err += draw.y_sign;
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
			index = (y * fdf->map_x) + x++;
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
