/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_ctrl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:00:38 by pnoronha          #+#    #+#             */
/*   Updated: 2022/04/22 12:51:39 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move_screen(int keycode, t_view *view);
void	zoom_screen(int keycode, t_view *view);
void	fract_iters(int keycode, t_view *view);
void	julia_shape(int keycode, t_complex *cplx);

int	keys_control(int keycode, t_structs *vars)
{
	if (keycode == 53)
		close_win(vars);
	else if (keycode >= 123 && keycode <= 126)
		move_screen(keycode, &vars->view);
	else if (keycode == 69 || keycode == 78)
		zoom_screen(keycode, &vars->view);
	else if (keycode == 116 || keycode == 121 ||
		keycode == 115 || keycode == 119)
		fract_iters(keycode, &vars->view);
	else if (keycode == 82)
		reset_view(&vars->view);
	else if (base()->fractol_type == julia && (keycode == 91 ||
		keycode == 84 || keycode == 86 || keycode == 88))
		julia_shape(keycode, &vars->cplx);
	// printf("keycode >> %d\n", keycode);
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

void	move_screen(int keycode, t_view *view)
{
	view->moveX += (1 / (view->zoom * 20)) * ((keycode == 124) - (keycode == 123));
	view->moveY += (1 / (view->zoom * 20)) * ((keycode == 125) - (keycode == 126));
}

void	zoom_screen(int keycode, t_view *view)
{
	view->zoom += (0.001) * (view->zoom == 0);
	view->zoom -= (view->zoom / 10) * ((keycode == 78) && (view->zoom <= 1));
	view->zoom += (view->zoom / 10) * ((keycode == 69) && (view->zoom <= 1));
	view->zoom -= (view->zoom / 2) * ((keycode == 78) && (view->zoom >= 50));
	view->zoom += (view->zoom) * ((keycode == 69) && (view->zoom >= 50));
	if (view->zoom > 1 && view->zoom < 50)
		view->zoom += 1 * ((keycode == 69) - (keycode == 78));
	// printf("view.zoom >>> %f\n", view->zoom);
}

void	fract_iters(int keycode, t_view *view)
{
	if (view->maxiter == 1 && keycode == 121)
		return ;
	if (view->maxiter <= 11 && keycode == 119)
		return ;
	view->maxiter += 1 * ((keycode == 116) - (keycode == 121));
	view->maxiter += 10 * ((keycode == 115) - (keycode == 119));
	// printf("ITERATIONS >> %i\n", view-> maxiter);
}

void	julia_shape(int keycode, t_complex *cplx)
{
	cplx->real += 0.015 * ((keycode == 91) - (keycode == 84));
	cplx->imag += 0.015 * ((keycode == 88) - (keycode == 86));
}
