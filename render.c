/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 04:25:04 by mstaali           #+#    #+#             */
/*   Updated: 2024/02/14 18:13:14 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(int x, int y, t_img *image, int color)
{
	char	*dst;

	dst = image->addr + (y * image->line_length
			+ x * (image->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static void	which_fractal(int x, int y, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		fractal->z.re = (scale(x, fractal->start_x, fractal->end_x, WIDTH));
		fractal->z.im = (scale(y, fractal->start_y, fractal->end_y, HEIGHT));
		fractal->c.re = fractal->julia_x;
		fractal->c.im = fractal->julia_y;
	}
	else
	{
		fractal->c.re = (scale(x, fractal->start_x, fractal->end_x, WIDTH));
		fractal->c.im = (scale(y, fractal->start_y, fractal->end_y, HEIGHT));
		fractal->z.re = 0;
		fractal->z.im = 0;
	}
}

static void	pixel_handle(int x, int y, t_fractal *fractal)
{
	int			color;
	int			i;

	which_fractal(x, y, fractal);
	i = 0;
	while (i++ < fractal->iterations)
	{
		if (!ft_strncmp(fractal->name, "burning_ship", 12))
			fractal->z = sum_complex(fabs_imaginary(fractal->z), fractal->c);
		else
			fractal->z = sum_complex(power_complex(fractal->z), fractal->c);
		if (pow(fractal->z.re, 2) + pow(fractal->z.im, 2) > 4)
		{
			color = color_generator(i, fractal);
			my_mlx_pixel_put(x, y, &fractal->image, color);
			return ;
		}
		my_mlx_pixel_put(x, y, &fractal->image, 0x000000);
	}
}

void	render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			pixel_handle(x, y, fractal);
	}
	mlx_put_image_to_window(fractal->mlx_ptr,
		fractal->win_ptr, fractal->image.img, 0, 0);
}
