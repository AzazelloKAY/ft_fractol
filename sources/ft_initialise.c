//
// Created by Antonin KOKOSHKO on 2/25/18.
//

#include "ft_fractol.h"

static void		ft_setfractdefault(t_fract *f)
{
	f->win_h = 900;
	f->win_w = 900;
	f->maxiter = 50;
	f->zoom = 1;
	f->mov_y = 0.0;
	f->mov_x = 0.0;
	f->step = FT_STEP;
}

t_fract			*ft_init_mlx(char *name)
{
	t_fract	*f;

	if (!(f = ft_memalloc(sizeof(t_fract))))
		return (NULL);
	ft_setfractdefault(f);
	if(!(f->mlx = mlx_init()))
		return (NULL);
	if (!(f->win = mlx_new_window(f->mlx, f->win_w, f->win_h, name)))
		return (NULL);
	return (f);
}

int				ft_init_img(t_fract *f)
{
	if (f->img.ptr)
		mlx_destroy_image(f->mlx, f->img.ptr);
	f->img.h = f->win_h;
	f->img.w = f->win_w;
	if (!(f->img.ptr = mlx_new_image(f->mlx, f->img.w, f->img.h)))
		return (1);
	f->img.bitperpix = sizeof(int) * 8;
	f->img.size_line = sizeof(int) * f->img.w;
	f->img.endian = 0;
	if (!(f->img.str = (uint32_t*)mlx_get_data_addr(f->img.ptr,
		&(f->img.bitperpix), &(f->img.size_line), &(f->img.endian))))
		return (1);
	return (0);
}

int				ft_initman(t_fract *f)
{
	t_mandel	*m;

	if (!(m = ft_memalloc(sizeof(t_mandel))))
		return (1);
	f->maxiter = 20;
	m->minrl = -2.0;
	m->maxrl = 1.0;
	m->minim = -1.4;
	m->maxim = 1.4;
	m->im_fact = (m->maxim - m->minim) / (f->win_h - 1);
	m->rl_fact = (m->maxrl - m->minrl) / (f->win_w - 1);
	f->fract = m;
	f->zoom = 1;
	f->mov_y = 0.0;
	f->mov_x = 0.0;
	f->fract_lonch = &ft_calc_man;
	f->live_mouse = 1;
	f->live_mouse_move = 0;
	f->acid_color = 0;
	f->colorshift = 1;
	return (0);
}

void		ft_initcalcfunc(int n, t_fract *f)
{
	if (n == 2)
		f->fract_calc = ft_m_2;
	else if (n == 3)
		f->fract_calc = ft_m_3;
	else if (n == 4)
		f->fract_calc = ft_m_4;
	else if (n == 5)
		f->fract_calc = ft_m_5;
	else if (n == 6)
		f->fract_calc = ft_m_6;
	else if (n == 7)
		f->fract_calc = ft_m_7;
	else if (n == 8)
		f->fract_calc = ft_m_8;
	else
		f->fract_calc = ft_m_1;
}

