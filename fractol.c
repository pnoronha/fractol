/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 20:57:57 by pnoronha          #+#    #+#             */
/*   Updated: 2022/03/24 02:35:02 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_vars	*base(void)
{
	static t_vars	base;

	return (&base);
}

int	close_win(int keycode, t_vars *b)
{
	if (keycode == 53)
	{
		if (b->data.img)
			mlx_destroy_image(b->mlx, b->data.img);
		mlx_destroy_window(b->mlx, b->win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	main(void)
{
	t_data	*img;
	
	base()->width = 1920;
	base()->height = 1080;
	img = &base()->data;
	base()->mlx = mlx_init();
	(base()->win) = mlx_new_window(base()->mlx,
		base()->width, base()->height, "fractol");
	(base()->data.img) = mlx_new_image(base()->mlx,
		base()->width, base()->height);
	img->addr = mlx_get_data_addr(img->img, &img->bpp,
		&img->line_length, &img->endian);
	gen_pixel();
	mlx_loop_hook(base()->mlx, print_pixel, base());
	mlx_key_hook(base()->win, close_win, base());
	mlx_loop(base()->mlx);
}
