/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:53:58 by mstaali           #+#    #+#             */
/*   Updated: 2024/01/18 23:58:51 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if (ac == 2 && (ft_strncmp(av[1], "mandelbrot", 10) == 0
			|| ft_strncmp(av[1], "julia", 5) == 0))
	{
		fractal.name = av[1];
		init(&fractal);
		render(&fractal);
		mlx_loop(fractal.mlx_ptr);
	}
	else
	{
		ft_putstr_fd("\n\n\033[1;31;4m! INVALIDE ARGUMENT !\033[0m"
			"\n\n\n\033[4mUSAGE:\033[0m\n\t./fractol [fractal_name]\n\n"
			"\033[4mFRACTALS:\033[0m\n\t-> mandelbrot\n\t-> julia\n"
			"\t-> bonus\n\n", STDERR_FILENO);
		exit(1);
	}
}
