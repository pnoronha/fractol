/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 23:16:19 by pnoronha          #+#    #+#             */
/*   Updated: 2022/04/20 16:37:42 by pnoronha         ###   ########.fr       */
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
				base()->fractol_type(base()->cplx));
		}
	}
}

int	print_pixel(t_structs *b)
{
	mlx_put_image_to_window(b->mlxv.mlx, b->mlxv.win, b->img.img, 0, 0);
	return (false);
}
