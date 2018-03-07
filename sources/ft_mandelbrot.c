//
// Created by Antonin KOKOSHKO on 2/25/18.
//

#include "ft_fractol.h"

static void		ft_updscale(t_fract *f)
{
	t_mandel	*m;

	m = (t_mandel*)f->fract;
	m->minrl = -2.0 / f->zoom;
	m->maxrl = 1.0 / f->zoom;
	m->minim = -1.4 / f->zoom;
	m->maxim = 1.4 / f->zoom;
	m->im_fact = (m->maxim - m->minim) / (f->win_h - 1);
	m->rl_fact = (m->maxrl - m->minrl) / (f->win_w - 1);
	if (f->mmoved != 0)
	{
		f->mov_y += (m->im_fact * (f->mouse.im - (f->win_h / 2))) * 0.19;
		f->mov_x += (m->rl_fact * (f->mouse.rl - (f->win_w / 2))) * 0.19;
		f->mmoved = 0;
	}
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
		z = f->fract_calc(z, z2, c);
	}
	if (i == f->maxiter)
		p->colr.val = 0;
	else
		p->colr.val = ft_makecolor(f, p->colr.val, i, z);
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
		pthread_join(tread[y++], NULL);
	ft_drawimg(f);
	ft_bzero(&f->mouse, sizeof(t_complex));
}

void 			ft_mandelbrot(int num)
{
	t_fract *f;

	if (!(f = ft_init_mlx("akokoshk`s mandelbrot")) || ft_init_img(f)
		|| ft_initman(f))
		return ;
	f->fract_init = ft_initman;
	ft_initcalcfunc(num, f);
	f->fract_lonch(f);
	ft_keyhookloop(f);
}
