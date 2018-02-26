//
// Created by Antonin KOKOSHKO on 2/25/18.
//

#include "ft_fractol.h"

/*
static int	ft_calc_scale(t_env *mx)
{
	int scale;

	scale = mx->tr.scale;
	if (scale < 50 &&
		((mx->map->lnum * scale) * (mx->map->vnum * scale) < 20000000))
		return (2);
	return (0);
}

static void	ft_key1(int keycode, t_env *mx)
{
	if (keycode == 53)
	{
		if (mx->img.ptr)
			mlx_destroy_image(mx->mlx, mx->img.ptr);
		mlx_destroy_window(mx->mlx, mx->win);
		exit(0);
	}
	else if (keycode == 24 || keycode == 69)
		mx->tr.scale += ft_calc_scale(mx);
	else if (keycode == 27 || keycode == 78)
		mx->tr.scale -= (mx->tr.scale > 1) ? 2 : 0;
	else if (keycode == 126)
		mx->tr.l_start -= (mx->tr.l_start > -500) ? 1 : 0;
	else if (keycode == 125)
		mx->tr.l_start += (mx->tr.l_start < 500) ? 1 : 0;
	else if (keycode == 123)
		mx->tr.v_start -= (mx->tr.v_start > -500) ? 1 : 0;
	else if (keycode == 124)
		mx->tr.v_start += (mx->tr.v_start < 500) ? 1 : 0;
	else if (keycode == 82)
		ft_setmxdefault(mx);
}

static void	ft_key2(int keycode, t_env *mx)
{
	if (keycode == 91)
		mx->tr.x_ang = (mx->tr.x_ang - 2) % 360;
	else if (keycode == 84)
		mx->tr.x_ang = (mx->tr.x_ang + 2) % 360;
	else if (keycode == 86)
		mx->tr.y_ang = (mx->tr.y_ang + 2) % 360;
	else if (keycode == 88)
		mx->tr.y_ang = (mx->tr.y_ang - 2) % 360;
	else if (keycode == 89)
		mx->tr.z_ang = (mx->tr.z_ang + 2) % 360;
	else if (keycode == 92)
		mx->tr.z_ang = (mx->tr.z_ang - 2) % 360;
	else if (keycode == 87)
		mx->needperspect = (mx->needperspect == 0) ? 1 : 0;
}
*/

int			ft_keycatch(int keycode, t_fract *f)
{
	//ft_key1(keycode, mx);
	//ft_key2(keycode, mx);
	//ft_drawimg(mx);
	if (keycode == 53)
	{
		if (f->img.ptr)
			mlx_destroy_image(f->mlx, f->img.ptr);
		mlx_destroy_window(f->mlx, f->win);
		exit(0);
	}
	return (0);
}



int			ft_exit_x(t_fract *f)
{
	if (f->img.ptr)
		mlx_destroy_image(f->mlx, f->img.ptr);
	mlx_destroy_window(f->mlx, f->win);
	exit(0);
}

void		ft_keyhookloop(t_fract *f)
{
	mlx_hook(f->win, 2, 0, ft_keycatch, f);
	mlx_hook(f->win, 17, 1L << 17, ft_exit_x, f);
	mlx_loop(f->mlx);
}
