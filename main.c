/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 20:57:57 by pnoronha          #+#    #+#             */
/*   Updated: 2022/04/20 00:04:58 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mlx_core(t_structs	*core)
{
	core->mlxv.width = WIDTH;
	core->mlxv.height = HEIGHT;
	core->mlxv.mlx = mlx_init();
	core->mlxv.win = mlx_new_window(core->mlxv.mlx,
		core->mlxv.width, core->mlxv.height, "fractol");
	core->img.img = mlx_new_image(core->mlxv.mlx,
		core->mlxv.width, core->mlxv.height);
	core->img.addr = mlx_get_data_addr(core->img.img, &core->img.bpp,
		&core->img.line_length, &core->img.endian);
}

void	loop(t_structs *core)
{
	mlx_loop_hook(core->mlxv.mlx, print_pixel, core);
	mlx_hook(core->mlxv.win, ON_KEYDOWN, 1L<<0, keys_control, core);
	mlx_loop(core->mlxv.mlx);
}

t_structs	*base(void)
{
	static t_structs	base;

	return (&base);
}

int	main(int argc, char **argv)
{
	t_structs	*core;

	if (argc < 2)
		print_input();
	check_input(argv[1]);
	core = base();
	init_mlx_core(core);
	reset_viewer(&core->view);
	gen_pixel();
	loop(core);
}
