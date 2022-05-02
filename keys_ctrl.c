/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_ctrl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:00:38 by pnoronha          #+#    #+#             */
/*   Updated: 2022/05/02 22:07:50 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	julia_shape(int key, t_complex *cplx);
static void	move_screen(int key, t_view *view);
static void	zoom_screen(int key, t_view *view);
static void	fract_iters(int key, t_view *view);

int	keys_control(int key, t_structs *vars)
{
	ft_printf("%d\n", key);
	if (key == ESC)
		close_win(vars);
	else if (key >= ARROW_LEFT && key <= ARROW_UP)
		move_screen(key, &vars->view);
	else if (key == PLUS || key == MINUS)
		zoom_screen(key, &vars->view);
	else if (key == PAGE_UP || key == PAGE_DOWN \
		|| key == HOME || key == END)
		fract_iters(key, &vars->view);
	else if (base()->fractol_type == julia && (key == NUM_UP \
		|| key == NUM_DOWN || key == NUM_LEFT || key == NUM_RIGHT))
		julia_shape(key, &vars->cplx);
	else if (key == ZERO)
		reset_view(&vars->view);
	gen_pixel();
	return (0);
}

void	move_screen(int key, t_view *view)
{
	view->movex += (1 / (view->zoom * 20)) * \
		((key == ARROW_RIGHT) - (key == ARROW_LEFT));
	view->movey += (1 / (view->zoom * 20)) * \
		((key == ARROW_DOWN) - (key == ARROW_UP));
}

void	zoom_screen(int key, t_view *view)
{
	if (key == PLUS)
		view->zoom *= 1.1;
	if (key == MINUS)
		view->zoom *= (1 / 1.1);
}

void	fract_iters(int key, t_view *view)
{
	if (view->maxiter == 1 && key == PAGE_DOWN)
		return ;
	if (view->maxiter <= 11 && key == END)
		return ;
	view->maxiter += 1 * ((key == PAGE_UP) - (key == PAGE_DOWN));
	view->maxiter += 10 * ((key == HOME) - (key == END));
}

void	julia_shape(int key, t_complex *cplx)
{
	cplx->real += (1 / (base()->view.zoom * 50)) * \
		((key == NUM_UP) - (key == NUM_DOWN));
	cplx->imag += (1 / (base()->view.zoom * 50)) * \
		((key == NUM_RIGHT) - (key == NUM_LEFT));
}
