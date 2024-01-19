/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 04:25:04 by mstaali           #+#    #+#             */
/*   Updated: 2024/01/19 05:37:53 by mstaali          ###   ########.fr       */
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

	z.re = 0;
	z.im = 0;
	c.re = scale(x, -2, +2, WIDTH) + fractal->shift_x;
	c.im = scale(y, +2, -2, HEIGHT) + fractal->shift_y;
	i = 0;
	while (i++ < NUM_OF_ITERS)
	{
		z = sum_complex(power_complex(z), c);
		if (pow(z.re, 2) + pow(z.im, 2) > ESCAPE_VALUE)
		{
			color = scale(i, BLACK, WHITE, NUM_OF_ITERS);
			my_mlx_pixel_put(x, y, &fractal->image, color);
			return ;
		}
		my_mlx_pixel_put(x, y, &fractal->image, GREEN_DARK);
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
