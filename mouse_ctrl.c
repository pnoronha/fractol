/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_ctrl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:15:03 by pnoronha          #+#    #+#             */
/*   Updated: 2022/04/22 12:52:50 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	zoom_mouse(int keycode, t_view *view);

int	mouse_ctrl(int keycode, t_structs *vars)
{
	(void)vars;
	if (keycode == 5 || keycode == 4)
		zoom_mouse(keycode, &vars->view);
	printf("keycode >> %d\n", keycode);
	return (0);
}

void	zoom_mouse(int keycode, t_view *view)
{
	view->zoom += (1) * ((keycode == 5) - (keycode == 4));
}
