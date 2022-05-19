/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_ctrl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:00:38 by pnoronha          #+#    #+#             */
/*   Updated: 2022/05/19 13:07:38 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_shape(int key, t_complex *cplx);
void	move_screen(int key, t_view *view);
void	zoom_screen(int key, t_view *view);
void	fract_iters(int key, t_view *view);

int	keys_control(int key, t_structs *vars)
{
	if (key == ESC)
		close_win(vars);
	if (key == ZERO)
		reset_view(&vars->view);
	move_screen(key, &vars->view);
	zoom_screen(key, &vars->view);
	fract_iters(key, &vars->view);
	julia_shape(key, &vars->cplx);
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
