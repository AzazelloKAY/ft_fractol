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
		ft_initman(f);
	else if (keycode == 91)
		f->maxiter += (f->maxiter < 500) ? 1 : 0;
	else if (keycode == 84)
		f->maxiter -= (f->maxiter > 20) ? 1 : 0;

//	printf("mov_y= %10f\tmov_x=%10f\t zoom=%f f->maxiter=%f\n", f->mov_y, f->mov_x, f->zoom, f->maxiter);
	//printf("zoom = %f\n", f->zoom);
//	printf("keycode = %d\n", keycode);
}

static int			ft_mouse_hook(int mb, int x, int y, t_fract *f)
{
	t_mandel	*m;

	m = (t_mandel*)f->fract;
	//mb == 5 UP
	((mb == 5) ?	ft_key1(69, f) : 0);
	//mb == 4 DOWN
	((mb == 4) ?	ft_key1(78, f) : 0);

	if (mb == 5 || mb == 4)
	{
		f->mouse.im = y;
		f->mouse.rl = x;
	}

	//printf("y dlt= %10f\tx dlt=%10f\tzoom = %10f\n", m->mb_im_shft, m->mb_rl_shft, f->zoom);
	//printf("y= %d\t x=%d\t scrol=%d\t f=%p\n", y, x, mb, f);

	f->fract_func(f);

	ft_bzero(&f->mouse, sizeof(t_complex));
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
	mlx_hook(f->win, 17, 1L << 17, ft_exit_x, f);
	mlx_loop(f->mlx);
}
