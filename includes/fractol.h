/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 21:01:04 by pnoronha          #+#    #+#             */
/*   Updated: 2022/04/20 00:04:48 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include "libft.h"

# define WIDTH 1240
# define HEIGHT 780

enum e_boolean
{
	false,
	true
};

enum e_events
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct s_colors
{
	int	alpha;
	int	red;
	int	green;
	int	blue;
	int	argb;
}	t_colors;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_complex
{
	double	real;
	double	imag;
	double	oldIm;
	double	oldRe;
	double	newIm;
	double	newRe;
}	t_complex;

typedef struct s_view
{
	double	max_X;
	double	min_X;
	double	moveX;
	double	max_Y;
	double	min_Y;
	double	moveY;
	double	zoom;
	int		maxiter;
}	t_view;


typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	int		height;
	int		width;
}	t_mlx;

typedef struct s_ctrl
{
}	t_ctrl;

typedef struct s_structs
{
	t_image		img;
	t_mlx		mlxv;
	t_colors	colors;
	t_view		view;
	int	(*fractol_type)(t_complex z);
}	t_structs;

t_structs	*base(void);
void	gen_pixel(void);
int		print_pixel(t_structs *b);
int		render_color(int px, int py, t_structs *vars);
int		create_trgb(int a, int r, int g, int b);
int		close_win(t_structs *b);
int		keys_control(int keycode, t_structs *b);
void	init_win_ctrl(void);
t_complex	pixel_to_complex(int px, int py, t_view *vi);
int		mandelbrot(t_complex z);
int		julia(t_complex z);

int		print_input(void);
void	check_input(char *argv);
void	reset_viewer(t_view *view);


#endif
