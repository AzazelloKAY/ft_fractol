/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <akokoshk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 21:55:04 by akokoshk          #+#    #+#             */
/*   Updated: 2017/12/16 15:51:06 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_thisprint(long n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = FTABS(n);
	}
	if (n < 10)
		ft_putchar((char)(n + '0'));
	else
	{
		ft_thisprint(n / 10);
		ft_thisprint(n % 10);
	}
}

void		ft_putnbr(int n)
{
	ft_thisprint((long)n);
}
