/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 03:46:31 by pnoronha          #+#    #+#             */
/*   Updated: 2022/05/02 21:53:40 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	if (!data)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	gen_pixel(void)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (++y < base()->mlxv.height)
	{
		x = -1;
		while (++x < base()->mlxv.width)
		{
			pixel_to_complex(x, y, &base()->view);
			my_pixel_put(&base()->img, x, y,
				base()->fractol_type(&base()->cplx));
		}
	}
}

int	print_pixel(t_structs *core)
{
	mlx_clear_window(core->mlxv.mlx, core->mlxv.win);
	mlx_put_image_to_window(core->mlxv.mlx, \
		core->mlxv.win, core->img.img, 0, 0);
	return (false);
}

void	reset_view(t_view *view)
{
	view->max_x = 2.0;
	view->min_x = -2.0;
	view->max_y = 2.0;
	view->min_y = -2.0;
	view->movex = -0.5;
	if (base()->fractol_type == julia)
		view->movex = 0;
	view->movey = 0;
	view->maxiter = 30;
	view->zoom = 1;
}

void	pixel_to_complex(int px, int py, t_view *view)
{
	base()->cplx.real_calc = 1.5 * (px - WIDTH / 2) \
		/ ((0.44) * view->zoom * WIDTH) + view->movex;
	base()->cplx.imag_calc = (py - HEIGHT / 2) \
		/ ((0.44) * view->zoom * HEIGHT) + view->movey;
}
