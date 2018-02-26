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

int main(/*int ac, char **av*/)
{
	int stat;

	/*if (ac > 1)
		if (ft_strcmp(av[1],"mandelbrot"))*/
			stat = ft_mandelbrot ();



//	printf("%s<\n", ft_strjoin("123123","fsdgdfsgdh"));

	return 0;
}
