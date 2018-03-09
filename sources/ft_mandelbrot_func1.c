/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot_func1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 14:12:31 by akokoshk          #+#    #+#             */
/*   Updated: 2018/03/09 14:12:31 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

t_complex	ft_m_1(t_complex z, t_complex z2, t_complex c)
{
	t_complex res;

	res.im = 2 * z.rl * z.im + c.im;
	res.rl = z2.rl - z2.im + c.rl;
	return (res);
}

t_complex	ft_m_2(t_complex z, t_complex z2, t_complex c)
{
	t_complex res;

	res.im = z.rl * z.im * -2.0 + c.im;
	res.rl = z2.rl - z2.im + c.rl;
	return (res);
}

t_complex	ft_m_3(t_complex z, t_complex z2, t_complex c)
{
	t_complex res;

	res.im = ((z2.rl * 3.0) - z2.im) * z.im + c.im;
	res.rl = -(z2.rl - (z2.im * 3.0)) * z.rl + c.rl;
	return (res);
}

t_complex	ft_m_4(t_complex z, t_complex z2, t_complex c)
{
	t_complex res;

	res.im = fabs(z.rl) * z.im * -2.0 + c.im;
	res.rl = fabs(z2.rl - z2.im) + c.rl;
	return (res);
}

t_complex	ft_m_5(t_complex z, t_complex z2, t_complex c)
{
	t_complex res;

	res.im = z.rl * z.im * 2.0 + c.im;
	res.rl = fabs(z2.rl - z2.im) + c.rl;
	return (res);
}
