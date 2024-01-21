/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 23:59:23 by mstaali           #+#    #+#             */
/*   Updated: 2024/01/21 02:05:46 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h> //!!REMOVE AFTER!!
# include <stdlib.h> 
# include <unistd.h>
# include <math.h>
# include "mlx.h"

/* window */
# define WIDTH 800
# define HEIGHT 800

/* colors */
typedef struct s_color
{
	int current;
}		t_color;

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define GREEN_DARK 0x003D00
# define GREEN_BRIGHT 0xA1ffA1
# define FIRE_LOW 0xFF4500
# define BROWN_DARK 0x401102
# define GOLD_YELLOW  0xFFD700
# define PURPLE_DARK 0x00000C
#define PSY_PURPLE 0x6415C8
# define DARK_BLUE 0x08087B
# define YELLOW_BRIGHT 0xFAEE09

/* image comps */
typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_img;


/* fractal def */
# define ESCAPE_VALUE 4
# define NUM_OF_ITERS 300

typedef struct s_fractal
{
	char	*name;
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	image;
	t_color color;
	double	shift_x;
	double	shift_y;
	double	zoom;
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
double		scale(double unscaled, double min, double max, double MAX);
t_complex	sum_complex(t_complex C1, t_complex C2);
t_complex	power_complex(t_complex C);
int			switch_colors(int i, t_color *color);
int			color_generator(int color1, int color2, int i, int nums_of_iters);

#endif