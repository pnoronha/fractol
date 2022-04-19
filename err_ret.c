/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_ret.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:39:41 by pnoronha          #+#    #+#             */
/*   Updated: 2022/04/19 16:52:27 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	print_input(void)
{
	ft_printf("Error: Wrong program usage. \nTry something like:\n \
		- ./fractol mandelbrot\n \
		- ./fractol julia\n");
	exit(EXIT_FAILURE);
}

void	check_input(char *argv)
{
	if (ft_strncmp(argv, "mandelbrot", 10) == 0)
		base()->fractol_type = mandelbrot;
	// else if (ft_strncmp(argv, "julia", 5) == 0)
		// base()->fractol_type = julia;
	else
		print_input();
}

