/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_ret.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:39:41 by pnoronha          #+#    #+#             */
/*   Updated: 2022/04/21 16:05:43 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	print_input(void)
{
	ft_printf("Error: Wrong program usage. \n\n\
	Try something like:\n \
		- ./fractol mandelbrot\n \
		- ./fractol julia\n");
	exit(EXIT_FAILURE);
}

void	check_input(char **argv, int argc)
{
	if (argc < 2)
		print_input();
	if (ft_strncmp(*argv, "mandelbrot", 10) == 0)
		base()->fractol_type = mandelbrot;
	else if (ft_strncmp(*argv, "julia", 5) == 0)
	{
		base()->fractol_type = julia;
		if (argc == 4)
		{
			if (argv++ != NULL)
				base()->cplx.real = ft_atod(*argv);
			if (argv++ != NULL)
				base()->cplx.imag = ft_atod(*argv);
		}
	}
	else
		print_input();
}

