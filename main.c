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

#include "sources/ft_fractol.h"

//static int	ft_select1(char *s)
//{
//	if (ft_strequ(s, "mandelbrot"))
//		if (fork() == 0)
//			ft_mandelbrot(1);
//	else if (ft_strequ(s, "mandelbrot1"))
//		if (fork() == 0)
//			ft_mandelbrot(1);
//	else if (ft_strequ(s, "mandelbrot2"))
//		if (fork() == 0)
//			ft_mandelbrot(2);
//	else if (ft_strequ(s, "mandelbrot3"))
//		if (fork() == 0)
//			ft_mandelbrot(3);
//	else if (ft_strequ(s, "mandelbrot4"))
//		if (fork() == 0)
//			ft_mandelbrot(4);
//	else if (ft_strequ(s, "mandelbrot5"))
//		if (fork() == 0)
//			ft_mandelbrot(5);
//	else if (ft_strequ(s, "mandelbrot6"))
//		if (fork() == 0)
//			ft_mandelbrot(6);
//	else if (ft_strequ(s, "mandelbrot7"))
//		if (fork() == 0)
//			ft_mandelbrot(7);
//	else if (ft_strequ(s, "mandelbrot8"))
//		ft_mandelbrot(8);
//	else if (ft_strequ(s, "julia"))
//		ft_julia();
//	else
//		return (0);
//	return (1);
//}
//
//static int	ft_select2(char *s)
//{
//	if (ft_strequ(s, "mandelbrot"))
//		ft_mandelbrot(1);
//	else if (ft_strequ(s, "mandelbrot1"))
//		ft_mandelbrot(1);
//	else if (ft_strequ(s, "mandelbrot2"))
//		ft_mandelbrot(2);
//	else if (ft_strequ(s, "mandelbrot3"))
//		ft_mandelbrot(3);
//	else if (ft_strequ(s, "mandelbrot4"))
//		ft_mandelbrot(4);
//	else if (ft_strequ(s, "mandelbrot5"))
//		ft_mandelbrot(5);
//	else if (ft_strequ(s, "mandelbrot6"))
//		ft_mandelbrot(6);
//	else if (ft_strequ(s, "mandelbrot7"))
//		ft_mandelbrot(7);
//	else if (ft_strequ(s, "mandelbrot8"))
//		ft_mandelbrot(8);
//	else if (ft_strequ(s, "julia"))
//		ft_julia();
//	else
//		return (0);
//	return (1);
//}

int			main(int ac, char **av)
{
	int i;
//	int num;
//	int flag;

	i = 1;
	//flag = 0;
//	if (ac > 1)
//		while (i < ac)
//		{
			if (fork() == 0)
				ft_mandelbrot(7);//ft_select(av[1]);
			if (fork() == 0)
				ft_julia();//ft_julia();//ft_select(av[2]);
//		}
//	if (flag == 0)
//		printf("You have made some error!\nUsage:\t1\t2\n");
	printf(">>>%d",i);
	return 0;
}
