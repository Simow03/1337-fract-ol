/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 23:59:23 by mstaali           #+#    #+#             */
/*   Updated: 2024/01/18 23:45:42 by mstaali          ###   ########.fr       */
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
# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define GREEN_DARK 0x006400
# define GREEN_MEDIUM 0x00FF00
# define GREEN_BRIGHT 0xADFF2F

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
# define NUM_OF_ITERS 100

typedef struct s_fractal
{
	char	*name;
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	image;
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

/* utils */
int			ft_strncmp(char *s1, char *s2, int n);
void		ft_putstr_fd(char *s, int fd);
double		scale(double unscaled, double min, double max, double MAX);
t_complex	sum_complex(t_complex C1, t_complex C2);
t_complex	power_complex(t_complex C);

#endif