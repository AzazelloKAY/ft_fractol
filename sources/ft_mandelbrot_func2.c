/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot_func2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 14:12:37 by akokoshk          #+#    #+#             */
/*   Updated: 2018/03/09 14:12:37 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

t_complex	ft_m_6(t_complex z, t_complex z2, t_complex c)
{
	t_complex res;

	res.im = ((z2.rl * 3.0) - z2.im) * z.im + c.im;
	res.rl = fabs(z2.rl - (z2.im * 3.0)) * fabs(z.rl) + c.rl;
	return (res);
}

t_complex	ft_m_7(t_complex z, t_complex z2, t_complex c)
{
	t_complex res;

	res.im = ((z2.rl * 3.0) - z2.im) * fabs(z.im) + c.im;
	res.rl = (z2.rl - (z2.im * 3.0)) * z.rl + c.rl;
	return (res);
}

t_complex	ft_m_8(t_complex z, t_complex z2, t_complex c)
{
	t_complex	res;
	double		zri;

	zri = z2.im * z2.rl;
	res.im = z.im * (5 * z2.rl * z2.rl - 10 * zri + z2.im * z2.im) + c.im;
	res.rl = z.rl * (z2.rl * z2.rl - 10 * zri + 5 * z2.im * z2.im) + c.rl;
	return (res);
}
