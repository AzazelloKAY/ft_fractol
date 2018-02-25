/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <akokoshk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 22:12:36 by akokoshk          #+#    #+#             */
/*   Updated: 2018/01/15 23:08:59 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_thisprint(long n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = FTABS(n);
	}
	if (n < 10)
		ft_putchar_fd((char)(n + '0'), fd);
	else
	{
		ft_thisprint(n / 10, fd);
		ft_thisprint(n % 10, fd);
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	ft_thisprint((long)n, fd);
}
