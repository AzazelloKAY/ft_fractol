//
// Created by Antonin KOKOSHKO on 3/6/18.
//

#include "ft_fractol.h"

int				ft_init_jul(t_fract *f)
{
	f->fract = 0;
	f->zoom = 1;
	f->mov_y = 0.0;
	f->mov_x = 0.0;
	f->fract_func = &ft_calc_jul;
	f->mouse.im = 0.27015;
	f->mouse.rl = -0.7;
	f->live_mouse = 1;
	f->live_mouse_move = 1;
	f->mouse_moved = 0;
	return (0);
}

static t_point	*ft_isjul_point(t_fract *f, t_point *p)
{
	long		i;
	t_complex	z;
	t_complex	zprev;

	z.im = (p->y - f->win_h / 2) / (0.5 * f->zoom * f->win_h) + f->mov_y;
	z.rl = 1.5 * (p->x - f->win_w / 2) / (0.5 * f->zoom * f->win_w) + f->mov_x;
	i = 0;
	while (i++ < f->maxiter)
	{
		zprev.im = z.im;
		zprev.rl = z.rl;
		z.im = 2 * zprev.rl * zprev.im + f->mouse.im;
		z.rl = zprev.rl * zprev.rl - zprev.im * zprev.im + f->mouse.rl;
		if(z.im * z.im + z.rl * z.rl > 4)
			break ;
	}
	p->colr.val = 0;
	if (i == f->maxiter)
		p->colr.val = 0;
	else
//		p->colr.chnl.g = ((double)i / f->maxiter) * 255;
		ft_makecolor(&p->colr, i, z);
	return (p);
}

static void		*ft_treadlonch(void* tf)
{
	t_point		p;
	t_fract		*f;

	f = ((t_threads*)tf)->fr;
	ft_bzero(&p, sizeof(t_point));
	p.y = ((t_threads*)tf)->tnum;
	while (p.x < f->img.w)
	{
		ft_pixtoimg(f, ft_isjul_point(f, &p));
		p.x++;
	}
	return (NULL);
}

void			ft_calc_jul(t_fract *f)
{
	pthread_t	tread[f->img.h];
	t_threads	tf[f->img.h];
	long		y;

	ft_init_img(f);

//	(m->maxim - m->minim) / (f->win_h - 1)

	//f->mov_y += (f->mouse.im != 0) ? ((1/f->win_w) * (f->mouse.im - (f->win_h / 2))) * 0.19 : 0;
	//f->mov_x += (f->mouse.rl != 0) ? ((1/f->win_w) * (f->mouse.rl - (f->win_w / 2))) * 0.19 : 0;
	if (f->mouse_moved)
	{
		f->mouse.im /= f->win_h;
		f->mouse.rl /= f->win_w;
		f->mouse_moved = 0;
	}
	y = 0;
	while (y < f->img.h)
	{
		tf[y].tnum = y;
		tf[y].fr = f;
		pthread_create(&tread[y], NULL, ft_treadlonch, (void*)&(tf[y]));
		y++;
	}
	y = 0;
	while (y < f->img.h)
	{
		pthread_join(tread[y], NULL);
		y++;
	}
	ft_drawimg(f);
}

int 		ft_julia(void)
{
	t_fract *f;

	if (!(f = ft_init_mlx("akokoshk`s julia")) || ft_init_img(f)
		|| ft_init_jul(f))
		return (1);
	f->fract_init = ft_init_jul;
	f->fract_func(f);
	ft_keyhookloop(f);
	return (0);
}