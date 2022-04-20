/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_ctrl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:00:38 by pnoronha          #+#    #+#             */
/*   Updated: 2022/04/20 17:05:47 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	move_screen(int keycode, t_view *view);
static void	zoom_screen(int keycode, t_view *view);
static void	fract_iters(int keycode, t_view *view);
static void	julia_shape(int keycode, t_complex *cplx);

int	keys_control(int keycode, t_structs *vars)
{
	if (keycode == 53)
		close_win(vars);
	else if (keycode >= 123 && keycode <= 126)
		move_screen(keycode, &vars->view);
	else if (keycode == 69 || keycode == 78)
		zoom_screen(keycode, &vars->view);
	else if (keycode == 116 || keycode == 121)
		fract_iters(keycode, &vars->view);
	else if (keycode == 82)
		reset_viewer(&vars->view);
	else if (base()->fractol_type == julia && (keycode == 91 ||
		keycode == 84 || keycode == 86 || keycode == 88))
		julia_shape(keycode, &vars->cplx);
	gen_pixel();
	return (0);
}

int	close_win(t_structs *b)
{
	if (b->img.img)
		mlx_destroy_image(b->mlxv.mlx, b->img.img);
	mlx_destroy_window(b->mlxv.mlx, b->mlxv.win);
	exit(EXIT_SUCCESS);
}

static void	move_screen(int keycode, t_view *view)
{
	view->moveX += (0.05) * ((keycode == 124) - (keycode == 123));
	view->moveY += (0.05) * ((keycode == 125) - (keycode == 126));
}

static void	zoom_screen(int keycode, t_view *view)
{
	float	change;

	if (view->zoom <= 0 && keycode == 78)
		return ;
	change = (0.1 * (view->zoom <= 1)) + (view->zoom > 1);
	view->zoom += change * ((keycode == 69) - (keycode == 78));
}

static void	fract_iters(int keycode, t_view *view)
{
	if (view->maxiter == 1 && keycode == 121)
		return ;
	view->maxiter += 1 * ((keycode == 116) - (keycode == 121));
}

static void	julia_shape(int keycode, t_complex *cplx)
{
	cplx->real += 0.0255 * ((keycode == 91) - (keycode == 84));
	cplx->imag += 0.0255 * ((keycode == 88) - (keycode == 86));
}
