/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:05:03 by mstaali           #+#    #+#             */
/*   Updated: 2024/01/20 04:02:23 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	failed_malloc(void)
{
	perror("! FAILED MALLOC !");
	exit(1);
}

void	values_init(t_fractal *fractal)
{
	fractal->shift_x = 0;
	fractal->shift_y = 0;
	fractal->zoom = 1;
}

static void	events_handle(t_fractal *fractal)
{
	mlx_hook(fractal->win_ptr,
		2, 0, &key_listener, fractal);
	mlx_hook(fractal->win_ptr,
		17, 0, &close_listener, fractal);
	mlx_mouse_hook(fractal->win_ptr, mouse_listener, fractal);
}

void	init(t_fractal *fractal)
{
	fractal->mlx_ptr = mlx_init();
	if (!fractal->mlx_ptr)
		failed_malloc();
	fractal->win_ptr = mlx_new_window(fractal->mlx_ptr, WIDTH,
			HEIGHT, fractal->name);
	if (!fractal->win_ptr)
	{
		mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
		free(fractal->mlx_ptr);
		failed_malloc();
	}
	fractal->image.img = mlx_new_image(fractal->mlx_ptr, WIDTH, HEIGHT);
	if (!fractal->image.img)
	{
		mlx_destroy_image(fractal->mlx_ptr, fractal->image.img);
		mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
		free(fractal->mlx_ptr);
		failed_malloc();
	}
	fractal->image.addr = mlx_get_data_addr(fractal->image.img,
			&fractal->image.bits_per_pixel,
			&fractal->image.line_length, &fractal->image.endian);
	values_init(fractal);
	events_handle(fractal);
}
