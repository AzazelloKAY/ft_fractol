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

uint32_t			ft_makecolor(t_fract *f, uint32_t c, long i, t_complex z)
{
	double index;
	double freq;
	double clr;
	t_pcolor res;

	res.val = 0;
	if(f->acid_color == 0)
	{
		res.chnl.g = ((double)i / f->maxiter) * 255;
		return (res.val);
	}
	freq = 0.56;
	clr = 1;
	index = (i + 1 - (log((log(sqrt(z.rl * z.rl + z.im * z.im)) / 2) / log(2)) / log(2))) * freq;
	res.chnl.r = cos(index) * 127 + 128;
	res.chnl.g = cos(index + clr) * 127 + 128;
	res.chnl.b = cos(index + 2 * clr) * 127 + 128;
	return (res.val);
}
