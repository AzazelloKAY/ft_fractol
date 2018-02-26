//
// Created by Antonin KOKOSHKO on 2/25/18.
//

#include "ft_fractol.h"

void		ft_pixtoimg(t_fract *f, t_point *p)
{
	/*
	l -= mx->tr.min_y;
	v -= mx->tr.min_x;
	 */
	f->img.str[((f->img.w * p->y) + p->x)] = p->colr.val;
}

void		ft_drawimg(t_fract *f)
{
	//int scale;

	//scale = f->tr.scale;
	mlx_clear_window(f->mlx, f->win);
	/*
	ft_calc_radians(f);
	ft_fill_res(f);
	if (!(ft_init_img(f)))
		return (0);
	ft_put_res_to_img(f);
	ft_put_lines_to_img(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img.ptr,
		(f->win_w / 2) - (f->img.v / 2) + (f->tr.v_start * scale),
		(f->win_h / 2) - (f->img.l / 2) + (f->tr.l_start * scale));
	 */
	mlx_put_image_to_window(f->mlx, f->win, f->img.ptr,	0, 0);
	//ft_writhelp(f);
	//return (1);
}
