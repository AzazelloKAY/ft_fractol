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
	f->mmoved = 0;
	f->acid_color = 0;
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
		z.im = 2 * zprev.rl * zprev.im + f->mouse_alt.im;
		z.rl = zprev.rl * zprev.rl - zprev.im * zprev.im + f->mouse_alt.rl;
		if(z.im * z.im + z.rl * z.rl > 4)
			break ;
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

//			printf("f->mouse.im = %10f f->mouse.rl = %10f f->mov_y = %10f f->mov_x = %10f\n",f->mouse.im, f->mouse.rl, f->mov_y, f->mov_x);
void			ft_calc_jul(t_fract *f)
{
	pthread_t	tread[f->img.h];
	t_threads	tf[f->img.h];
	long		y;

	ft_init_img(f);
	if (f->mmoved == 2)
	{
		f->mov_y += ((f->mouse.im - (f->win_h / 2))) * f->step * 0.01;
		f->mov_x += ((f->mouse.rl - (f->win_w / 2))) * f->step * 0.01;
	}
	(f->mmoved == 1) ? (f->mouse_alt.im = f->mouse.im / f->win_h) : 0;
	(f->mmoved == 1) ? (f->mouse_alt.rl = f->mouse.rl / f->win_w) : 0;
	f->mmoved = (f->mmoved != 0) ? 0 : f->mmoved;
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
}

void 		*ft_julia(void)
{
	t_fract *f;

	if (!(f = ft_init_mlx("akokoshk`s julia")) || ft_init_img(f)
		|| ft_init_jul(f))
		return (NULL);
	f->fract_init = ft_init_jul;
	f->fract_func(f);
	ft_keyhookloop(f);
	return (NULL);
}