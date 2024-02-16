/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 04:16:47 by mstaali           #+#    #+#             */
/*   Updated: 2024/02/15 19:55:09 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_listener(int keycode, t_fractal *fractal)
{
	if (keycode == XK_ESCAPE)
		close_listener(fractal);
	render(fractal);
	return (0);
}

int	mouse_listener(int button, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (button == XK_POINTER_BUTTON5)
	{
		fractal->iterations += 10;
		fractal->start_x *= fractal->zoom_factor;
		fractal->end_x *= fractal->zoom_factor;
		fractal->start_y *= fractal->zoom_factor;
		fractal->end_y *= fractal->zoom_factor;
		fractal->move_factor /= 2;
	}
	if (button == XK_POINTER_BUTTON4)
	{
		fractal->iterations -= 10;
		fractal->start_x /= fractal->zoom_factor;
		fractal->end_x /= fractal->zoom_factor;
		fractal->start_y /= fractal->zoom_factor;
		fractal->end_y /= fractal->zoom_factor;
		fractal->move_factor *= 2;
	}
	render(fractal);
	return (0);
}

int	close_listener(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_ptr, fractal->image.img);
	mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
	fractal->mlx_ptr = NULL;
	exit(0);
}
