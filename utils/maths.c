/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 04:52:27 by mstaali           #+#    #+#             */
/*   Updated: 2024/01/20 07:26:30 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double	scale(double unscaled, double min, double max, double MAX)
{
	return ((max - min) * (unscaled) / (MAX) + min);
}

t_complex	sum_complex(t_complex c1, t_complex c2)
{
	t_complex	result;

	result.re = c1.re + c2.re;
	result.im = c1.im + c2.im;
	return (result);
}

t_complex	power_complex(t_complex c)
{
	t_complex	result;

	result.re = pow(c.re, 2) - pow(c.im, 2);
	result.im = 2 * c.re * c.im;
	return (result);
}
