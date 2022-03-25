/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 03:46:31 by pnoronha          #+#    #+#             */
/*   Updated: 2022/03/25 15:20:53 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

float map(int in, int inMin, int inMax, int outMin, int outMax)
{
	float mapped;

	mapped = ((float)((in - inMin)*(outMax - outMin))/
		(float)(inMax - inMin)) + outMin;
	return (mapped);
}

int	render_color(int px, int py)
{
	float	tempa, tempb, a, b, ca, cb;
	int		count, maxiter;

	a = map(px, 0, base()->width, -4, 3);
	b = map(py, 0, base()->height, -2, 2);
	ca = a;
	cb = b;
	count = -1;
	maxiter = 50;
	while (++count < maxiter)
	{
		tempa = pow(a, 2) - pow(b, 2);
		tempb = 2 * a * b;
		a = tempa + ca;
		b = tempb + cb;
		if (a + b > 50)
			break ;
	}
	if (count == maxiter)
		return (0x00000000);
	else
	{
		count = map(count, 0, maxiter, 0, 255);
		return ((0x00000000 & 0x0000FF00) + (count * 5));
	}
}
