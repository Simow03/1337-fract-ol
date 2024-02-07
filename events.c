/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 04:16:47 by mstaali           #+#    #+#             */
/*   Updated: 2024/02/07 20:14:46 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_listener(int keycode, t_fractal *fractal)
{
	if (keycode == XK_ESCAPE)
		close_listener(fractal);
	else if (keycode == XK_RIGHT)
		fractal->shift_x += (0.2 * fractal->zoom);
	if (keycode == XK_LEFT)
		fractal->shift_x -= (0.2 * fractal->zoom);
	else if (keycode == XK_UP)
		fractal->shift_y += (0.2 * fractal->zoom);
	else if (keycode == XK_DOWN)
		fractal->shift_y -= (0.2 * fractal->zoom);
	else if (keycode == XK_SPACE)
		fractal->color.current += 1;
	render(fractal);
	return (0);
}

int	mouse_listener(int button, int x, int y, t_fractal *fractal)
{
	if (button == XK_POINTER_BUTTON5)
	{
		fractal->zoom *= 1.1;
		fractal->shift_x += (scale(x, +2, -2, WIDTH) - fractal->shift_x) * 0.1 / fractal->zoom;
		fractal->shift_y += (scale(y, -2, +2, HEIGHT) - fractal->shift_y) * 0.1 / fractal->zoom;
	}
	else if (button == XK_POINTER_BUTTON4)
	{
		fractal->zoom /= 1.1;
		fractal->shift_x += (scale(x, +2, -2, WIDTH) - fractal->shift_x) * -0.1 / fractal->zoom;
		fractal->shift_y += (scale(y, -2, +2, HEIGHT) - fractal->shift_y) * -0.1 / fractal->zoom;
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
