//
// Created by Antonin KOKOSHKO on 2/25/18.
//

#include "ft_fractol.h"

static int		ft_initman(t_fract *f)
{
	t_img		*i;
	t_mandel	*m;

	if (!(m = ft_memalloc(sizeof(t_mandel))))
		return (1);
	f->maxiter = 50;
	i = &(f->img);
	m->minrl = -2.0;
	m->maxrl = 1.0;
	m->minim = -1.2;
	m->maxim = m->minrl + (m->maxrl - m->minrl) * i->h / i->w;
	m->rl_fact = (m->maxrl - m->minrl) / (i->w - 1);
	m->im_fact = (m->maxim - m->minim) / (i->h - 1);
	m->step = 0.01;
	f->fract = m;
	return (0);
}

static int		ft_isman_point(t_fract *f, t_complex c)
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
		if(z2.im + z2.rl > 4) // sqrt() > 2 // Absolute value of Z
			return (0);
		z.im = 2 * z.rl * z.im + c.im;
		z.rl = z2.rl - z2.im + c.rl;
	}
	return (1);
}

static void		ft_calc_man(t_fract *f)
{
	t_point		p;
	t_complex	c;
	t_mandel	*m;

	ft_bzero(&p, sizeof(t_tcount));
	m = (t_mandel*)f->fract;

	p.colr.val = 0xFFFFFF;


	/*или эту часть вынести в треды , внктрь передавать только диапазон/номер строки*/
	while (p.y < f->img.h)
	{
		p.x = 0;
		c.im = m->maxim - (p.y * m->im_fact);
		while (p.x < f->img.w)
		{
			c.rl = m->minrl + (p.x * m->rl_fact);
			if (ft_isman_point(f, c))
				ft_pixtoimg(f, &p);
			p.x++;
		}
		p.y++;
	}


}

int 		ft_mandelbrot(void)
{
	t_fract *f;

	if (!(f = ft_init_mlx("akokoshk`s mandelbrot")) || ft_init_img(f)
		|| ft_initman(f))
		return (1);
	ft_calc_man(f);

	/*t_point p;
	p.y = 10;
	p.x = 10;
	p.colr.chnl.b = 250;
	ft_pixtoimg(f, &p);
*/
	ft_drawimg(f);
	ft_keyhookloop(f);
	return (0);
}
