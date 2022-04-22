/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 03:46:31 by pnoronha          #+#    #+#             */
/*   Updated: 2022/04/21 16:46:49 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map(double in, double inMin, double inMax, double outMin, double outMax)
{
	return ((((in - inMin)/(inMax - inMin)*(outMax - outMin))) + outMin);
}

void	reset_view(t_view *view)
{
	view->max_X = 2.0;
	view->min_X = -2.0;
	view->max_Y = 2.0;
	view->min_Y = -2.0;
	view->moveX = -0.5;
	if (base()->fractol_type == julia)
		view->moveX = 0;
	view->moveY = 0;
	view->maxiter = 30;
	view->zoom = 1;
}

void	pixel_to_complex(int px, int py, t_view *view)
{
	base()->cplx.real_calc = 1.5 * (px - WIDTH / 2) /
		((0.44) * view->zoom * WIDTH) + view->moveX;
	base()->cplx.imag_calc = (py - HEIGHT / 2) /
		((0.44) * view->zoom * HEIGHT) + view->moveY;
}
