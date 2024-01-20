/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 00:45:38 by mstaali           #+#    #+#             */
/*   Updated: 2024/01/21 00:48:08 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	color_generator(int color1, int color2, int i, int nums_of_iters)
{
	double	smooth_factor;

	smooth_factor = pow((double)i / nums_of_iters, 0.5);

	int r = (int)((color1 >> 16 & 0xFF) * smooth_factor + (color2 >> 16 & 0xFF) * (1 - smooth_factor));
	int g = (int)((color1 >> 8 & 0xFF) * smooth_factor + (color2 >> 8 & 0xFF) * (1 - smooth_factor));
	int b = (int)((color1 & 0xFF) * smooth_factor + (color2 & 0xFF) * (1 - smooth_factor));
	return ((r << 16) | (g << 8) | b);
}

int	switch_colors(int i, t_color *color)
{
	if (color->current == 1)
		return (color_generator(GREEN_BRIGHT, GREEN_DARK, i, NUM_OF_ITERS));
	else if (color->current == 2)
		return (color_generator(FIRE_LOW, BLACK, i, NUM_OF_ITERS));
	else if (color->current == 3)
		return (color_generator(WHITE, WHITE, i, NUM_OF_ITERS));
	else if (color->current == 4)
		return (color_generator(GOLD_YELLOW, BROWN_DARK, i, NUM_OF_ITERS));
	else if (color->current == 5)
		return (color_generator(YELLOW_BRIGHT, DARK_BLUE, i, NUM_OF_ITERS));
	else if (color->current == 6)
		return (color_generator(PSY_PURPLE, ORANGE_BRIGHT, i, NUM_OF_ITERS));
	else
	{
		color->current = 1;
		return (color_generator(GREEN_BRIGHT, GREEN_DARK, i, NUM_OF_ITERS));
	}
}
