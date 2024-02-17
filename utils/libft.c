/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:52:38 by mstaali           #+#    #+#             */
/*   Updated: 2024/02/16 22:07:20 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	if (!s1 || !s2 || n <= 0)
		return (0);
	while (n && *s1 == *s2 && *s1 != '\0')
	{
		s1++;
		s2++;
		n--;
	}
	return (*s1 - *s2);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	while (*s++)
		write(fd, s, 1);
}

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static void	parse(char *s)
{
	while (*s)
	{
		if (*s == '+' || *s == '-')
			s++;
		if (*s == '+' || *s == '-')
			exit_fail();
		while (*s && ft_isdigit(*s))
			s++;
		if (*s == '.')
			s++;
		while (*s && ft_isdigit(*s))
			s++;
		if (*s && !ft_isdigit(*s))
			exit_fail();
	}
}

double	ft_atodouble(char *s)
{
	int		integer;
	double	fractional;
	double	pow;
	int		sign;

	integer = 0;
	fractional = 0;
	sign = 1;
	pow = 1;
	parse(s);
	if (*s++ == '-')
		sign = (-1);
	while (*s != '.' && *s)
		integer = (integer * 10) + (*s++ - '0');
	if (*s == '.')
		++s;
	while (*s)
	{
		pow /= 10;
		fractional = fractional + (*s++ - '0') * pow;
	}
	return ((integer + fractional) * sign);
}
