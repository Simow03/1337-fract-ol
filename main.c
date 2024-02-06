/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:53:58 by mstaali           #+#    #+#             */
/*   Updated: 2024/02/06 18:43:32 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	h()
{
	system("leaks fractol");
}

int	main(int ac, char **av)
{
	t_fractal	fractal;

	atexit(h);
	if (ac == 2 && (ft_strncmp(av[1], "mandelbrot", 10) == 0
			|| ft_strncmp(av[1], "julia", 5) == 0
			|| ft_strncmp(av[1], "burning_ship", 12) == 0))
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
			"\t-> burning_ship\n\n\033[4mKEYS:\033[0m\n\tSPACE  = change"
			" color\n\tARROWS = move view\n\tMOUSE  = zoom in/out"
			"\n\tESC    = exit\n\n", STDERR_FILENO);
		exit(1);
	}
}
