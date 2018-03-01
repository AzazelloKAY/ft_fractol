//
// Created by Antonin KOKOSHKO on 2/25/18.
//

#include "ft_fractol.h"

static int		ft_initman(t_fract *f)
{
	t_mandel	*m;

	if (!(m = ft_memalloc(sizeof(t_mandel))))
		return (1);
	f->maxiter = 20;
	m->minrl = -2.0;
	m->maxrl = 1.0;
	m->minim = -1.2;
	m->maxim = 1.2;//m->minrl + (m->maxrl - m->minrl) * i->h / i->w;
	m->im_fact = (m->maxim - m->minim) / (f->win_h - 1);
	m->rl_fact = (m->maxrl - m->minrl) / (f->win_w- 1);
	f->fract = m;
	f->fract_func = &ft_tr_calc_man; // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	return (0);
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
		p->colr.chnl.r = ((double)i/(double)f->maxiter) * 255;
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

	c.im = m->maxim - (p.y * m->im_fact) + (f->mov_y / f->zoom);
	//printf(">>thread =%ld\n", p.y);

	while (p.x < f->img.w)
	{
		c.rl = m->minrl + (p.x * m->rl_fact) + (f->mov_x / f->zoom);
		ft_pixtoimg(f, ft_isman_point(f, c, &p));
		p.x++;
	}
	return (NULL);
}

void			ft_tr_calc_man(t_fract *f)
{
	pthread_t tread[f->img.h];
	t_threads tf[f->img.h];
	long y;

	//c.rl = 1.5 * (x - D_WIDTH / 2) / (0.5 * uk->zoom * D_WIDTH) + uk->move_x;
	//c.im = (y - D_HEIGHT / 2) / (0.5 * uk->zoom * D_HEIGHT) + uk->move_y;
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

//static void		ft_calc_man(t_fract *f)
//{
//	t_point		p;
//	t_complex	c;
//	t_mandel	*m;
//
//	ft_bzero(&p, sizeof(t_tcount));
//	m = (t_mandel*)f->fract;
//
//	/*или эту часть вынести в треды , внктрь передавать только диапазон/номер строки*/
//	//c.rl = 1.5 * (x - D_WIDTH / 2) / (0.5 * uk->zoom * D_WIDTH) + uk->move_x;
//	//c.im = (y - D_HEIGHT / 2) / (0.5 * uk->zoom * D_HEIGHT) + uk->move_y;
//
//	while (p.y < f->img.h)
//	{
//		p.x = 0;
//		c.im = m->maxim - (p.y * m->im_fact);
//		while (p.x < f->img.w)
//		{
//			c.rl = m->minrl + (p.x * m->rl_fact);
//			//if ((n = ft_isman_point(f, c)) != f->maxiter)
//			{
//				/*n = ft_isman_point(f, c);
//				n /= (double)f->maxiter;
//				if (n != 0)
//					printf(">%2.4f ", n);
//				p.colr.chnl.r = (n == 0) ? n * 250 : 0; //(n / (double)f->maxiter) //n * 255;*/
//				//printf(">>%u\t", p.colr.chnl.r);
//				ft_pixtoimg(f, ft_isman_point(f, c, &p));
//			}
//			p.x++;
//		}
//		p.y++;
//	}
//}


int 		ft_mandelbrot(void)
{
	t_fract *f;

	if (!(f = ft_init_mlx("akokoshk`s mandelbrot")) || ft_init_img(f)
		|| ft_initman(f))
		return (1);
	//ft_calc_man(f);

	ft_tr_calc_man(f);

	//ft_drawimg(f);
	ft_keyhookloop(f);
	return (0);
}
