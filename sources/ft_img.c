//
// Created by Antonin KOKOSHKO on 2/25/18.
//

#include "ft_fractol.h"

void		ft_pixtoimg(t_fract *f, t_point *p)
{
	f->img.str[((f->img.w * p->y) + p->x)] = p->colr.val;
}

void		ft_drawimg(t_fract *f)
{
	mlx_clear_window(f->mlx, f->win);
	mlx_put_image_to_window(f->mlx, f->win, f->img.ptr,	0, 0);
	//ft_writhelp(f);
}
