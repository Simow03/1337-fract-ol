/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 04:25:04 by mstaali           #+#    #+#             */
/*   Updated: 2024/02/13 20:18:27 by mstaali          ###   ########.fr       */
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

static void	pixel_handle(int x, int y, t_fractal *fractal)
{
	int			color;
	int			i;
	t_complex	z;
	t_complex	c;

	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		z.re = (scale(x, fractal->start_x, fractal->end_x, WIDTH));
		z.im = (scale(y, fractal->start_y, fractal->end_y, HEIGHT));
		c.re = fractal->julia_x;
		c.im = fractal->julia_y;
	}
	else
	{
		c.re = (scale(x, fractal->start_x, fractal->end_x, WIDTH));
		c.im = (scale(y, fractal->start_y, fractal->end_y, HEIGHT));
		z.re = 0;
		z.im = 0;
	}
	i = 0;
	while (i++ < fractal->iterations)
	{
		if (!ft_strncmp(fractal->name, "burning_ship", 12))
			z = sum_complex(fabs_imaginary(z), c);
		else
			z = sum_complex(power_complex(z), c);
		if (pow(z.re, 2) + pow(z.im, 2) > 4)
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
