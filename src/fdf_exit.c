/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_exit.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/19 15:26:10 by mweverli      #+#    #+#                 */
/*   Updated: 2022/08/24 22:15:33 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "fdf.h"

void	fdf_exit(int error_id, const char *loc)
{
	if (error_id == 1)
		ft_printf("Error in %s: incorrect amount of arguments\n", loc);
	else if (error_id == 2)
		ft_printf("Error in %s: inputfile incorrect\n", loc);
	else if (error_id == 3)
		ft_printf("Error in %s: ", loc);
}
