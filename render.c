/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 03:46:31 by pnoronha          #+#    #+#             */
/*   Updated: 2022/04/19 23:49:36 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map(double in, double inMin, double inMax, double outMin, double outMax)
{
	return ((((in - inMin)/(inMax - inMin)*(outMax - outMin))) + outMin);
}

void	reset_viewer(t_view *view)
{
	view->max_X = 2.0;
	view->min_X = -2.0;
	view->max_Y = 2.0;
	view->min_Y = -2.0;
	view->moveX = -0.5;
	view->moveY = 0;
	view->maxiter = 30;
	view->zoom = 10;
	// base()->is_print = 0;
}

t_complex	pixel_to_complex(int px, int py, t_view *vi)
{
	t_complex	z;

	z.newIm = 0;
	z.newRe = 0;
	z.oldIm = 0;
	z.oldRe = 0;
	z.real = 1.5 * (px - WIDTH / 2) / ((0.025) * vi->zoom * WIDTH) + vi->moveX;
	z.imag = (py - HEIGHT / 2) / ((0.025) * vi->zoom * HEIGHT) + vi->moveY;
	return (z);
}
int	mandelbrot(t_complex z)
{
	unsigned int color;
	int count;

	count = -1;
	while (++count < base()->view.maxiter)
	{
		z.oldRe = z.newRe;
		z.oldIm = z.newIm;
		z.newRe = z.oldRe * z.oldRe - z.oldIm * z.oldIm + z.real;
		z.newIm = 2 * z.oldRe * z.oldIm + z.imag;
		if((z.newRe * z.newRe + z.newIm * z.newIm) > 4)
			break;
	}
	if (count == base()->view.maxiter)
		return (0);
	else
	{
		color = (unsigned int)map(count, 0,
			(base()->view.maxiter - 1), 0, 255);
		base()->colors.blue = 0x55 + (color);
		return (create_trgb(0, base()->colors.red, color, color));
		// return (create_trgb(0, base()->colors.red, 0, 0));
	}
}
