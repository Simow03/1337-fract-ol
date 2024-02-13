/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 23:59:23 by mstaali           #+#    #+#             */
/*   Updated: 2024/02/12 20:37:49 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "mlx.h"

/* window */
# define WIDTH 500
# define HEIGHT 500

/* image comps */
typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_img;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	image;
	int		color;
	double	start_x;
	double	end_x;
	double	start_y;
	double	end_y;
	double	move_factor;
	double	zoom_factor;
	double	julia_x;
	double	julia_y;
	int		iterations;
}		t_fractal;

/* complex number */
typedef struct s_complex
{
	double	re;
	double	im;
}		t_complex;

/* mlx inits */
void		init(t_fractal *fractal);
void		render(t_fractal *fractal);

/* events */
# define XK_ESCAPE 53
# define XK_LEFT 123
# define XK_RIGHT 124
# define XK_DOWN 125
# define XK_UP 126
# define XK_POINTER_BUTTON4 4
# define XK_POINTER_BUTTON5 5
# define XK_SPACE 49

int			key_listener(int keycode, t_fractal *fractal);
int			mouse_listener(int button, int x, int y, t_fractal *fractal);
int			close_listener(t_fractal *fractal);

/* utils */
int			ft_strncmp(char *s1, char *s2, int n);
void		ft_putstr_fd(char *s, int fd);
double		ft_atodouble(char *s);
double		scale(double unscaled, double min, double max, double size);
t_complex	sum_complex(t_complex C1, t_complex C2);
t_complex	power_complex(t_complex C);
t_complex	fabs_imaginary(t_complex c);
int			color_generator(int i, t_fractal *fractal);

#endif