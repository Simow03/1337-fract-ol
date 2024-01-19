/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 04:16:47 by mstaali           #+#    #+#             */
/*   Updated: 2024/01/19 06:07:06 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_listener(int keycode, t_fractal *fractal)
{
	if (keycode == XK_Escape)
		close_listener(fractal);
	if (keycode == XK_Left)
		fractal->shift_x += 0.2;
	else if (keycode == XK_Right)
		fractal->shift_x -= 0.2;
	else if (keycode == XK_Up)
		fractal->shift_y += 0.2;
	else if (keycode == XK_Down)
		fractal->shift_y -= 0.2;
	render(fractal);
	return 0;
}

// int	mouse_listener(int button, int x, int y, t_fractal *fractal)
// {
	
// }

int	close_listener(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_ptr, fractal->image.img);
	mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
	free(fractal->mlx_ptr);
	exit(0);
}
