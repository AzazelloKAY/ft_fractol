/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 14:42:00 by akokoshk          #+#    #+#             */
/*   Updated: 2018/02/25 14:42:01 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

static int	ft_selectfract(char *s)
{
	if (ft_strequ(s, "mandelbrot"))
		return (1);
	else if (ft_strequ(s, "mandelbrot1"))
		return (1);
	else if (ft_strequ(s, "mandelbrot2"))
		return (2);
	else if (ft_strequ(s, "mandelbrot3"))
		return (3);
	else if (ft_strequ(s, "mandelbrot4"))
		return (4);
	else if (ft_strequ(s, "mandelbrot5"))
		return (5);
	else if (ft_strequ(s, "mandelbrot6"))
		return (6);
	else if (ft_strequ(s, "mandelbrot7"))
		return (7);
	else if (ft_strequ(s, "mandelbrot8"))
		return (8);
	else if (ft_strequ(s, "julia"))
		return (9);
	else
		return (0);
}

static void	ft_printusage(void)
{
	printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n", "[USAGE] Bad arguments",
		"-> ./fractol julia", "-> ./fractol mandelbrot",
		"-> ./fractol mandelbrot2", "-> ./fractol mandelbrot3",
		"-> ./fractol mandelbrot4", "-> ./fractol mandelbrot5",
		"-> ./fractol mandelbrot6", "-> ./fractal mandelbrot7",
		"-> ./fractal mandelbrot8");
}

int			main(int ac, char **av)
{
	int i;
	int num;
	int flag;

	i = 1;
	flag = 1;
	if (ac > 1)
		while (i < ac)
		{
			num = ft_selectfract(av[i++]);
			((num != 0) ? flag = 0 : 0);
			if (num > 0 && num <= 9)
				if (fork() == 0)
				{
					if (num == 9)
						ft_julia();
					else
						ft_mandelbrot(num);
					return (0);
				}
		}
	if (flag)
		ft_printusage();
	return (0);
}
