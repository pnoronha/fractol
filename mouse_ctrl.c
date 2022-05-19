/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_ctrl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:15:03 by pnoronha          #+#    #+#             */
/*   Updated: 2022/05/19 13:15:27 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	mouse_zoom(int key, t_view *view);

int	mouse_ctrl(int key)
{
	mouse_zoom(key, &base()->view);
	gen_pixel();
	return (0);
}

static void	mouse_zoom(int key, t_view *view)
{
	if (key == SCROLL_UP)
		view->zoom *= 1.1f;
	if (key == SCROLL_DOWN)
		view->zoom *= (1 / 1.1f);
}
