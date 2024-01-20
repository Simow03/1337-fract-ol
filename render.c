/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 04:25:04 by mstaali           #+#    #+#             */
/*   Updated: 2024/01/20 07:54:03 by mstaali          ###   ########.fr       */
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

int	smooth_color(int color1, int color2, int i, int nums_of_iters)
{
    double smooth_factor;

    smooth_factor = pow((double)i / nums_of_iters, 0.5);

    int r = (int)((color1 >> 16 & 0xFF) * smooth_factor + (color2 >> 16 & 0xFF) * (1 - smooth_factor));
    int g = (int)((color1 >> 8 & 0xFF) * smooth_factor + (color2 >> 8 & 0xFF) * (1 - smooth_factor));
    int b = (int)((color1 & 0xFF) * smooth_factor + (color2 & 0xFF) * (1 - smooth_factor));
    return ((r << 16) | (g << 8) | b);
}

static void	pixel_handle(int x, int y, t_fractal *fractal)
{
	int			color;
	int			i;
	t_complex	z;
	t_complex	c;

	z.re = 0;
	z.im = 0;
	c.re = (scale(x, -2, +2, WIDTH) * fractal->zoom) + fractal->shift_x;
	c.im = (scale(y, +2, -2, HEIGHT) * fractal->zoom) + fractal->shift_y;
	i = 0;
	while (i++ < NUM_OF_ITERS)
	{
		z = sum_complex(power_complex(z), c);
		if (pow(z.re, 2) + pow(z.im, 2) > ESCAPE_VALUE)
		{
			color = smooth_color(GOLD_YELLOW, BROWN_DARK, i, NUM_OF_ITERS);
			my_mlx_pixel_put(x, y, &fractal->image, color);
			return ;
		}
		my_mlx_pixel_put(x, y, &fractal->image, BLACK);
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
