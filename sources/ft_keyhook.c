/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyhook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 14:12:03 by akokoshk          #+#    #+#             */
/*   Updated: 2018/03/09 14:12:03 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

static void		ft_key1(int keycode, t_fract *f)
{
	if (keycode == 126)
		f->mov_y -= (f->mov_y > -FT_MOVLIM) ? f->step : 0;
	else if (keycode == 125)
		f->mov_y += (f->mov_y < FT_MOVLIM) ? f->step : 0;
	else if (keycode == 123)
		f->mov_x -= (f->mov_x < FT_MOVLIM) ? f->step : 0;
	else if (keycode == 124)
		f->mov_x += (f->mov_x > -FT_MOVLIM) ? f->step : 0;
	else if (keycode == 82)
		f->fract_init(f);
	else if (keycode == 91)
		f->maxiter += (f->maxiter < 500) ? 1 : 0;
	else if (keycode == 84)
		f->maxiter -= (f->maxiter > 20) ? 1 : 0;
	else if (keycode == 76)
		f->live_mouse = (f->live_mouse == 0) ? 1 : 0;
	else if (keycode == 67)
		f->acid_color = (f->acid_color == 0) ? 1 : 0;
	else if (keycode == 86)
		f->colorshift -= (f->colorshift > 1) ? 1 : 0;
	else if (keycode == 88)
		f->colorshift += (f->colorshift < 30) ? 1 : 0;
}

static int		ft_mouse_mov(int x, int y, t_fract *f)
{
	if (f->live_mouse == 1 && f->live_mouse_move == 1)
	{
		f->mouse.im = y;
		f->mouse.rl = x;
		f->mmoved = 1;
		f->fract_lonch(f);
	}
	return (0);
}

static int		ft_keycatch(int keycode, t_fract *f)
{
	if (keycode == 53)
		ft_exit_x(f);
	else if (keycode == 24 || keycode == 69)
	{
		f->zoom *= (f->zoom < FT_ZOOMMAX) ? FT_ZOOMSTP : 1;
		f->step /= (f->step > 0.0000001) ? FT_ZOOMSTP : 1;
		f->maxiter *= (f->maxiter < 500) ? FT_ITERSTP : 1;
	}
	else if (keycode == 27 || keycode == 78)
	{
		f->zoom /= (f->zoom > 1) ? FT_ZOOMSTP : 1;
		f->step *= (f->step < 0.1) ? FT_ZOOMSTP : 1;
		f->maxiter /= (f->maxiter > 20) ? FT_ITERSTP : 1;
	}
	ft_key1(keycode, f);
	f->fract_lonch(f);
	return (0);
}

static int		ft_mouse_hook(int mkeycode, int x, int y, t_fract *f)
{
	((mkeycode == 5) ? ft_keycatch(69, f) : 0);
	((mkeycode == 4) ? ft_keycatch(78, f) : 0);
	if (mkeycode == 5 || mkeycode == 4 || mkeycode == 2)
	{
		f->mouse.im = y;
		f->mouse.rl = x;
		f->mmoved = 2;
	}
	f->fract_lonch(f);
	return (0);
}

void			ft_keyhookloop(t_fract *f)
{
	mlx_hook(f->win, 2, 0, ft_keycatch, f);
	mlx_hook(f->win, 4, 5, ft_mouse_hook, f);
	mlx_hook(f->win, 6, 1L << 6, ft_mouse_mov, f);
	mlx_hook(f->win, 17, 1L << 17, ft_exit_x, f);
	mlx_loop(f->mlx);
}
