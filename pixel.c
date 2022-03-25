/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 23:16:19 by pnoronha          #+#    #+#             */
/*   Updated: 2022/03/25 15:16:49 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	gen_pixel(void)
{
	int				x;
	int				y;

	x = -1;
	y = -1;
	while (++y < base()->height)
	{
		x = -1;
		while (++x < base()->width)
			my_mlx_pixel_put(&base()->data, x, y, render_color(x, y));
	}
}

int	print_pixel(t_vars	*b)
{
	mlx_put_image_to_window(b->mlx, b->win, b->data.img, 0, 0);
	return (false);
}
