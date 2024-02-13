/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 00:45:38 by mstaali           #+#    #+#             */
/*   Updated: 2024/02/11 00:08:24 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	color_generator(int i, t_fractal *fractal)
{
	int	r;
	int	g;
	int	b;

	if (i >= fractal->iterations)
		return (0);
	r = i * (1 - sin(fractal->color));
	b = 4 * i * (2 + cos(fractal->color));
	g = 3 * i * (1 + cos(fractal->color));
	return (r << 16 | g << 8 | b);
}
