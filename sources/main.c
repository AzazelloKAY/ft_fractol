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

static int		ft_selectfract(char *s)
{
	if (ft_strequ(s, "1"))
		return (1);
	else if (ft_strequ(s, "2"))
		return (2);
	else if (ft_strequ(s, "3"))
		return (3);
	else if (ft_strequ(s, "4"))
		return (4);
	else if (ft_strequ(s, "5"))
		return (5);
	else if (ft_strequ(s, "6"))
		return (6);
	else if (ft_strequ(s, "7"))
		return (7);
	else if (ft_strequ(s, "8"))
		return (8);
	else if (ft_strequ(s, "julia"))
		return (9);
	else
		return (0);
}

static void		ft_lonchfract(char *s)
{
	if (ft_strequ(s, "1"))
		ft_mandelbrot(1);
	else if (ft_strequ(s, "2"))
		ft_mandelbrot(2);
	else if (ft_strequ(s, "3"))
		ft_mandelbrot(3);
	else if (ft_strequ(s, "4"))
		ft_mandelbrot(4);
	else if (ft_strequ(s, "5"))
		ft_mandelbrot(5);
	else if (ft_strequ(s, "6"))
		ft_mandelbrot(6);
	else if (ft_strequ(s, "7"))
		ft_mandelbrot(7);
	else if (ft_strequ(s, "8"))
		ft_mandelbrot(8);
	else if (ft_strequ(s, "julia"))
		ft_julia();
}

static void		ft_printusage(void)
{
	printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n", "[USAGE] Bad arguments",
		"-> ./fractol julia", "-> ./fractol 1",
		"-> ./fractol 2", "-> ./fractol 3",
		"-> ./fractol 4", "-> ./fractol 5",
		"-> ./fractol 6", "-> ./fractal 7",
		"-> ./fractal 8");
}

static void		ft_lonchprocess(char *av0, char *av1)
{
	char *av[3];

	av[0] = av0;
	av[1] = av1;
	av[2] = NULL;
	execve(av[0], av, NULL);
}

int				main(int ac, char **av)
{
	int i;
	int flag;

	flag = 1;
	i = 1;
	if (ac == 2)
		ft_lonchfract(av[1]);
	else if (ac > 2)
		while (i < ac)
		{
			if (ft_selectfract(av[i]) > 0)
			{
				flag = 0;
				if (fork() == 0)
				{
					ft_lonchprocess(av[0], av[i]);
					return (0);
				}
			}
			i++;
		}
	if (flag)
		ft_printusage();
	return (0);
}
