//
// Created by Antonin KOKOSHKO on 2/25/18.
//

#include "ft_fractol.h"

int				ft_initman(t_fract *f)
{
	t_mandel	*m;

	if (!(m = ft_memalloc(sizeof(t_mandel))))
		return (1);
	f->maxiter = 20;
	m->minrl = -2.0;
	m->maxrl = 1.0;
	m->minim = -1.3;
	m->maxim = 1.3;
	m->im_fact = (m->maxim - m->minim) / (f->win_h - 1);
	m->rl_fact = (m->maxrl - m->minrl) / (f->win_w - 1);
	f->fract = m;
	f->zoom = 1;
	f->mov_y = 0.0;
	f->mov_x = 0.0;
	f->fract_func = &ft_calc_man;
	f->live_mouse = 1;
	f->live_mouse_move = 0;
	return (0);
}

static void		ft_updscale(t_fract *f)
{
	t_mandel	*m;

	m = (t_mandel*)f->fract;
	m->minrl = -2.0 / f->zoom;
	m->maxrl = 1.0 / f->zoom;
	m->minim = -1.3 / f->zoom;
	m->maxim = 1.3 / f->zoom;
	m->im_fact = (m->maxim - m->minim) / (f->win_h - 1);
	m->rl_fact = (m->maxrl - m->minrl) / (f->win_w - 1);
	f->mov_y += (f->mouse.im != 0) ? (m->im_fact * (f->mouse.im - (f->win_h / 2))) * 0.19 : 0;
	f->mov_x += (f->mouse.rl != 0) ? (m->rl_fact * (f->mouse.rl - (f->win_w / 2))) * 0.19 : 0;
}

static t_point	*ft_isman_point(t_fract *f, t_complex c, t_point *p)
{
	long		i;
	t_complex	z;
	t_complex	z2;

	i = 0;
	z.im = c.im;
	z.rl = c.rl;
	while (i++ < f->maxiter)
	{
		z2.im = z.im * z.im;
		z2.rl = z.rl * z.rl;
		if(z2.im + z2.rl > 4)
			break ;
		z.im = 2 * z.rl * z.im + c.im;
		z.rl = z2.rl - z2.im + c.rl;
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
	t_complex	c;
	t_mandel	*m;
	t_fract		*f;

	f = ((t_threads*)tf)->fr;
	ft_bzero(&p, sizeof(t_point));
	m = (t_mandel*)f->fract;
	p.y = ((t_threads*)tf)->tnum;
	c.im = m->minim + (p.y * m->im_fact) + f->mov_y;
	while (p.x < f->img.w)
	{
		c.rl = m->minrl + (p.x * m->rl_fact) + f->mov_x;
		ft_pixtoimg(f, ft_isman_point(f, c, &p));
		p.x++;
	}
	return (NULL);
}

void			ft_calc_man(t_fract *f)
{
	pthread_t	tread[f->img.h];
	t_threads	tf[f->img.h];
	long		y;

	ft_init_img(f);
	ft_updscale(f);
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
	ft_bzero(&f->mouse, sizeof(t_complex));
}

int 		ft_mandelbrot(void)
{
	t_fract *f;

	if (!(f = ft_init_mlx("akokoshk`s mandelbrot")) || ft_init_img(f)
		|| ft_initman(f))
		return (1);
	f->fract_init = ft_initman;
	f->fract_func(f);
	ft_keyhookloop(f);
	return (0);
}
