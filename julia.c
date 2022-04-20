/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:40:46 by pnoronha          #+#    #+#             */
/*   Updated: 2022/04/20 17:11:06 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_julia(t_complex *z)
{
	z->new_im = z->imag_calc;
	z->new_re = z->real_calc;
	z->old_im = 0;
	z->old_re = 0;
	if (!z->real)
		z->real = -0.7;
	if (!z->imag)
		z->imag = 0.27015;
}

int	julia(t_complex z)
{
	unsigned int color;
	int count;

	init_julia(&z);
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
			(base()->view.maxiter - 1), 50, 255);
		base()->colors.blue = (color) * (1 - (color > 150));
		return (create_trgb(0, 50, 25, base()->colors.blue));
	}
}
