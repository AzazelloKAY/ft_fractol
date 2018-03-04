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
	m->minim = -1.2;
	m->maxim = 1.2;//m->minrl + (m->maxrl - m->minrl) * i->h / i->w;
	m->imdlt = m->maxim - m->minim;
	m->rldlt = m->maxrl - m->minrl;
	m->im_fact = m->imdlt / (f->win_h - 1);
	m->rl_fact = m->rldlt / (f->win_w - 1);
	m->mb_im_shft = 0;
	m->mb_rl_shft = 0;
	f->fract = m;
	f->zoom = 1;
	f->mov_y = 0.0;
	f->mov_x = 0.0;
	f->fract_func = &ft_tr_calc_man;
	return (0);
}

void		ft_movscale(t_fract *f)
{
	t_mandel	*m;

	m = (t_mandel*)f->fract;
	f->maxiter = 20;
	m->minrl = (-2.0 + f->mov_x) / f->zoom;
	m->maxrl = (1.0 + f->mov_x) / f->zoom;
	m->minim = (-1.2 + f->mov_y) / f->zoom;
	m->maxim = (1.2 + f->mov_y) / f->zoom;//m->minrl + (m->maxrl - m->minrl) * i->h / i->w;

	printf("f->mov_x= %10f\tf->mov_y=%10f f->zoom=%10f\n", f->mov_x, f->mov_y, f->zoom);
	printf("xmin= %10f\txmax=%10f\t ymin=%10f ymax=%10f\n", m->minrl, m->maxrl, m->minim, m->maxim);

	m->imdlt = m->maxim - m->minim;
	m->rldlt = m->maxrl - m->minrl;
	m->im_fact = m->imdlt / (f->win_h - 1);
	m->rl_fact = m->rldlt / (f->win_w - 1);
//	m->mb_im_shft = (m->im_fact * (f->mouse.im - (f->win_h / 2))) / FT_ZOOMSTP;
//	m->mb_rl_shft = (m->rl_fact * (f->mouse.rl - (f->win_w / 2))) / FT_ZOOMSTP;
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
		p->colr.chnl.g = ((double)i/(double)f->maxiter) * 255;
	return (p);
}

static void		*ft_treadlonch(void* tf)
{
	t_point		p;
	t_complex	c;
	t_mandel	*m;
	t_fract		*f;

	f = ((t_threads*)tf)->fr;
	ft_bzero(&p, sizeof(t_tcount));
	m = (t_mandel*)f->fract;
	p.y = ((t_threads*)tf)->tnum;

	ft_movscale(f);


	//c.im = (y - D_HEIGHT / 2) / (0.5 * uk->zoom * D_HEIGHT) + uk->move_y;

//	c.im = m->maxim - ((p.y + (m->mb_im_shft * f->zoom)) * m->im_fact / f->zoom) + (f->mov_y / f->zoom);
//	c.im = m->minim / f->zoom + (p.y * m->im_fact + f->mov_y) / f->zoom + m->mb_im_shft / FT_ZOOMSTP;// - m->mb_im_shft / 100; //- (m->mb_im_shft * 0.9 * f->zoom);

	c.im = m->minim + (p.y * m->im_fact);// + m->mb_im_shft;// - m->mb_im_shft / 100; //- (m->mb_im_shft * 0.9 * f->zoom);

	while (p.x < f->img.w)
	{
	//c.rl = 1.5 * (x - D_WIDTH / 2) / (0.5 * uk->zoom * D_WIDTH) + uk->move_x;

//		c.rl = m->minrl + ((p.x + (m->mb_rl_shft * f->zoom)) * m->rl_fact / f->zoom) + (f->mov_x / f->zoom);
//		c.rl = m->minrl / f->zoom + (p.x * m->rl_fact + f->mov_x) / f->zoom + m->mb_rl_shft / FT_ZOOMSTP;// +  / 100;// + (m->mb_rl_shft * 0.9* f->zoom);
		c.rl = m->minrl + (p.x * m->rl_fact);// + m->mb_rl_shft;// +  / 100;// + (m->mb_rl_shft * 0.9* f->zoom);
		ft_pixtoimg(f, ft_isman_point(f, c, &p));
		p.x++;
	}
	return (NULL);
}

void			ft_tr_calc_man(t_fract *f)
{
	pthread_t	tread[f->img.h];
	t_threads	tf[f->img.h];
	long		y;

	ft_init_img(f);
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

int 		ft_mandelbrot(void)
{
	t_fract *f;

	if (!(f = ft_init_mlx("akokoshk`s mandelbrot")) || ft_init_img(f)
		|| ft_initman(f))
		return (1);
	f->fract_func(f);
	ft_keyhookloop(f);
	return (0);
}
