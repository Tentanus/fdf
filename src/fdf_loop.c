/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_loop.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/22 18:10:06 by mweverli      #+#    #+#                 */
/*   Updated: 2022/09/22 19:12:09 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

/*
void	key_hook()
*/

void	fdf_loop(t_fdf *fdf, mlx_image_t* img)
{
	ft_bzero(img->pixels, (img->width * img->height * sizeof(uint32_t)));
	fdf_render(fdf);
	
}
