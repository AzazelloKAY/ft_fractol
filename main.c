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

int main(int ac, char **av)
{
	int stat;

		//stat = ft_julia();
	if (ac > 1 && ft_strequ(av[1],"1")) //mandelbrot"))
		stat = ft_mandelbrot();
	else if (ac > 1 && ft_strequ(av[1],"2"))
		stat = ft_julia();
	else
		printf("You have made some error!\nUsage:\t1\t2\n");



//	printf("%s<\n", ft_strjoin("123123","fsdgdfsgdh"));

	return 0;
}
