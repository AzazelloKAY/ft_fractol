//
// Created by Antonin KOKOSHKO on 2/25/18.
//

#include "ft_fractol.h"


static int		ft_exit_x(t_fract *f)
{
	if (f->img.ptr)
		mlx_destroy_image(f->mlx, f->img.ptr);
	mlx_destroy_window(f->mlx, f->win);
	exit(0);
}

static void		ft_key1(int keycode, t_fract *f)
{
	if (keycode == 24 || keycode == 69)
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
	else if (keycode == 126)
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
//	printf("keycode = %d im=%10f rl=%10f\n", keycode , f->mouse.im, f->mouse.rl);
}

static int			ft_mouse_hook(int mkeycode, int x, int y, t_fract *f)
{
	((mkeycode == 5) ?	ft_key1(69, f) : 0);
	((mkeycode == 4) ?	ft_key1(78, f) : 0);

	if ((mkeycode == 5 || mkeycode == 4 || mkeycode == 2) && f->live_mouse == 1)
	{
		f->mouse.im = y;
		f->mouse.rl = x;
		f->mouse_moved = 1;
	}
//	printf("mov_y= %10f\tmov_x=%10f\t zoom=%f f->maxiter=%f\n", f->mov_y, f->mov_x, f->zoom, f->maxiter);
//	printf("y dlt= %10f\tx dlt=%10f\tzoom = %10f\n", m->mb_im_shft, m->mb_rl_shft, f->zoom);
//	printf("keycode = %d im=%10f rl=%10f\n", mkeycode , f->mouse.im, f->mouse.rl);
	f->fract_func(f);
	return (0);
}

static int 			ft_mouse_mov(int x, int y, t_fract *f)
{
//	printf("flag =%5d y=%5d x=%5d fp=%p\n", f->live_mouse , y, x, f);
	if (f->live_mouse == 1 && f->live_mouse_move == 1)
	{
		f->mouse.im = y;
		f->mouse.rl = x;
		f->mouse_moved = 1;
		f->fract_func(f);
	}
	return (0);
}

static int			ft_keycatch(int keycode, t_fract *f)
{
	if (keycode == 53)
		ft_exit_x(f);
	ft_key1(keycode, f);
	f->fract_func(f);
	return (0);
}

void		ft_keyhookloop(t_fract *f)
{
	mlx_hook(f->win, 2, 0, ft_keycatch, f);
	mlx_hook(f->win, 4, 5, ft_mouse_hook, f);
	mlx_hook(f->win, 6, 1L << 6, ft_mouse_mov, f);
	mlx_hook(f->win, 17, 1L << 17, ft_exit_x, f);
	mlx_loop(f->mlx);
}
