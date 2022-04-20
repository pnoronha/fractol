/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:50:36 by pnoronha          #+#    #+#             */
/*   Updated: 2022/04/20 16:42:48 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mandelbrot(t_complex *z)
{
	z->new_im = 0;
	z->new_re = 0;
	z->old_im = 0;
	z->old_re = 0;
	z->real = z->real_calc;
	z->imag = z->imag_calc;
}

int	mandelbrot(t_complex z)
{
	unsigned int color;
	int count;

	init_mandelbrot(&z);
	count = -1;
	while (++count < base()->view.maxiter)
	{
		z.old_re = z.new_re;
		z.old_im = z.new_im;
		z.new_re = z.old_re * z.old_re - z.old_im * z.old_im + z.real;
		z.new_im = 2 * z.old_re * z.old_im + z.imag;
		if((z.new_re * z.new_re + z.new_im * z.new_im) > 4)
			break;
	}
	if (count == base()->view.maxiter)
		return (0);
	else
	{
		color = (unsigned int)map(count, 0,
			(base()->view.maxiter - 1), 0, 255);
		base()->colors.blue = (color) * (1 - (color > 150));
		return (create_trgb(0, color, 0, base()->colors.blue));
	}
}

