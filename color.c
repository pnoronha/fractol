/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 00:58:28 by pnoronha          #+#    #+#             */
/*   Updated: 2022/05/03 17:43:23 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

static double	map(double in, double inMax, double outMin, double outMax)
{
	return ((in / inMax * (outMax - outMin)) + outMin);
}

int	iter_to_color(int iterations)
{
	unsigned int	color;

	color = (unsigned int)map(iterations, \
		(base()->view.maxiter - 1), 0, 255);
	base()->colors.blue = 50;
	base()->colors.green = 0 + color / 4;
	base()->colors.red = 0 + color;
	return (create_trgb(0, base()->colors.red, \
		base()->colors.green, base()->colors.blue));
}
