/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_exit.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/19 15:26:10 by mweverli      #+#    #+#                 */
/*   Updated: 2022/09/01 21:51:07 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "fdf.h"

void	fdf_exit(int error_id, const char *loc)
{
	if (error_id == 1)
		ft_printf("Error in %s: %s\n", loc, strerror(errno));
	else if (error_id == 2)
		ft_printf("Error in %s: Incorrect amount of arguments\n", loc);
	else if (error_id == 3)
		ft_printf("Error in %s: Inputfile incorrect\n", loc);
	else if (error_id == 4)
		ft_printf("Error in %s: Allocation error", loc);
	exit(EXIT_SUCCESS);
}
