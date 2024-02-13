/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 04:16:47 by mstaali           #+#    #+#             */
/*   Updated: 2024/02/11 19:21:37 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_listener(int keycode, t_fractal *fractal)
{
	if (keycode == XK_ESCAPE)
		close_listener(fractal);
	if (keycode == XK_UP)
	{
		fractal->start_y -= fractal->move_factor;
		fractal->end_y -= fractal->move_factor;
	}
	if (keycode == XK_DOWN)
	{
		fractal->start_y += fractal->move_factor;
		fractal->end_y += fractal->move_factor;
	}
	if (keycode == XK_RIGHT)
	{
		fractal->start_x += fractal->move_factor;
		fractal->end_x += fractal->move_factor;
	}
	if (keycode == XK_LEFT)
	{
		fractal->start_x -= fractal->move_factor;
		fractal->end_x -= fractal->move_factor;
	}
	if (keycode == XK_SPACE)
		fractal->color += 10;
	return (render(fractal), 0);
}

void	zoom_in(double x1, double y1, t_fractal *fractal)
{
	fractal->iterations += 10;
	fractal->start_x += x1;
	fractal->end_x += x1;
	fractal->start_y += y1;
	fractal->end_y += y1;
	fractal->start_x *= fractal->zoom_factor;
	fractal->end_x *= fractal->zoom_factor;
	fractal->start_y *= fractal->zoom_factor;
	fractal->end_y *= fractal->zoom_factor;
	fractal->move_factor /= 2;
	render(fractal);
}

void	zoom_out(double x1, double y1, t_fractal *fractal)
{
	fractal->iterations -= 10;
	fractal->start_x /= fractal->zoom_factor;
	fractal->end_x /= fractal->zoom_factor;
	fractal->start_y /= fractal->zoom_factor;
	fractal->end_y /= fractal->zoom_factor;
	fractal->start_x -= x1;
	fractal->end_x -= x1;
	fractal->start_y -= y1;
	fractal->end_y -= y1;
	fractal->move_factor *= 2;
	render(fractal);
}

int	mouse_listener(int button, int x, int y, t_fractal *fractal)
{
	double	x1;
	double	y1;

	x1 = scale(x, fractal->start_x, fractal->end_x, WIDTH);
	y1 = scale(y, fractal->start_y, fractal->end_y, HEIGHT);
	if (button == XK_POINTER_BUTTON5)
		zoom_in(x1, y1, fractal);
	if (button == XK_POINTER_BUTTON4)
		zoom_out(x1, y1, fractal);
	return (0);
}

int	close_listener(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_ptr, fractal->image.img);
	mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
	fractal->mlx_ptr = NULL;
	exit(0);
}
