/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 03:46:31 by pnoronha          #+#    #+#             */
/*   Updated: 2022/04/20 16:38:13 by pnoronha         ###   ########.fr       */
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
}

void	pixel_to_complex(int px, int py, t_view *vi)
{
	base()->cplx.real_calc = 1.5 * (px - WIDTH / 2) /
		((0.025) * vi->zoom * WIDTH) + vi->moveX;
	base()->cplx.imag_calc = (py - HEIGHT / 2) /
		((0.025) * vi->zoom * HEIGHT) + vi->moveY;
}
