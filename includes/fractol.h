/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 21:01:04 by pnoronha          #+#    #+#             */
/*   Updated: 2022/03/24 02:01:36 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>

enum e_boolean
{
	false,
	true
};

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_vars
{
	t_data	data;
	void	*mlx;
	void	*win;
	int		height;
	int		width;
}	t_vars;

t_vars	*base(void);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	gen_pixel(void);
int		print_pixel(t_vars	*b);
int		render_color(int px, int py);

#endif
