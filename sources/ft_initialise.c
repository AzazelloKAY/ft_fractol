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

void			ft_makecolor(t_pcolor *c, long i, t_complex z)
{
	double index;
	double freq;
	double clr;

	freq = 0.56;
	clr = 1;
	index = (i + 1 - (log((log(sqrt(z.rl * z.rl + z.im * z.im)) / 2) / log(2)) / log(2))) * freq;
	c->chnl.r = cos(index) * 127 + 128;
	c->chnl.g = cos(index + clr) * 127 + 128;
	c->chnl.b = cos(index + 2 * clr) * 127 + 128;
	c->chnl.a = 0;
}
