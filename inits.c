/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:05:03 by mstaali           #+#    #+#             */
/*   Updated: 2024/02/16 18:53:54 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	exit_fail(void)
{
	perror("! INVALID !");
	exit(EXIT_FAILURE);
}

static void	values_init(t_fractal *fractal)
{
	fractal->start_x = -2;
	fractal->end_x = 2;
	fractal->start_y = -2;
	fractal->end_y = 2;
	fractal->color = 0x640C32;
	fractal->move_factor = 0.2;
	fractal->zoom_factor = 0.5;
	fractal->iterations = 70;
}

int	julia(int x, int y, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		fractal->julia_x = (scale(x, fractal->start_x, fractal->end_x, WIDTH));
		fractal->julia_y = (scale(y, fractal->start_y, fractal->end_y, HEIGHT));
		render(fractal);
	}
	return (0);
}

static void	events_handle(t_fractal *fractal)
{
	mlx_hook(fractal->win_ptr,
		2, 0, &key_listener, fractal);
	mlx_hook(fractal->win_ptr,
		17, 0, &close_listener, fractal);
	mlx_hook(fractal->win_ptr,
		4, 0, &mouse_listener, fractal);
	mlx_hook(fractal->win_ptr,
		6, 0, &julia, fractal);
}

void	init(t_fractal *fractal)
{
	fractal->mlx_ptr = mlx_init();
	if (!fractal->mlx_ptr)
		exit_fail();
	fractal->win_ptr = mlx_new_window(fractal->mlx_ptr, WIDTH,
			HEIGHT, fractal->name);
	if (!fractal->win_ptr)
	{
		mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
		free(fractal->mlx_ptr);
		exit_fail();
	}
	fractal->image.img = mlx_new_image(fractal->mlx_ptr, WIDTH, HEIGHT);
	if (!fractal->image.img)
	{
		mlx_destroy_image(fractal->mlx_ptr, fractal->image.img);
		mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
		free(fractal->mlx_ptr);
		exit_fail();
	}
	fractal->image.addr = mlx_get_data_addr(fractal->image.img,
			&fractal->image.bits_per_pixel,
			&fractal->image.line_length, &fractal->image.endian);
	values_init(fractal);
	events_handle(fractal);
}
