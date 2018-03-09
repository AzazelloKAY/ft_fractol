//
// Created by Antonin KOKOSHKO on 2/25/18.
//

#include "ft_fractol.h"

static void		ft_writhelp(t_fract *f)
{
	int start;
	int i;

	start = 1;
	i = 18;
	mlx_string_put(f->mlx, f->win, 5, start + (i * 0),
				   0xF0F090, "\"+/-\" - scaling");
	mlx_string_put(f->mlx, f->win, 5, start + (i * 1),
				   0xF0F090, "\"Up, Down, Left, Right\" - moving");
	mlx_string_put(f->mlx, f->win, 5, start + (i * 2),
				   0xF0F090, "\"NUM[82]\" - precision");
	mlx_string_put(f->mlx, f->win, 5, start + (i * 3),
				   0xF0F090, "\"NUM[46]\" - color shifting");
	mlx_string_put(f->mlx, f->win, 5, start + (i * 4),
				   0xF0F090, "\"NUM*\" - on/off colors");
	mlx_string_put(f->mlx, f->win, 5, start + (i * 5),
				   0xF0F090, "\"NUM_enter\" - on/off julia mouse move");
	mlx_string_put(f->mlx, f->win, 5, start + (i * 6),
				   0xF0F090, "\"NUM0\" - set to default");
	mlx_string_put(f->mlx, f->win, 5, start + (i * 7),
				   0xF0F090, "\"Esc\" - exit");
}

void			ft_pixtoimg(t_fract *f, t_point *p)
{
	f->img.str[((f->img.w * p->y) + p->x)] = p->colr.val;
}

void			ft_drawimg(t_fract *f)
{
	mlx_clear_window(f->mlx, f->win);
	mlx_put_image_to_window(f->mlx, f->win, f->img.ptr,	0, 0);
	ft_writhelp(f);
}

uint32_t		ft_makecolor(t_fract *f, uint32_t c, long i, t_complex z)
{
	double index;
	double freq;
	t_pcolor res;

	res.val = c;
	if (i == f->maxiter)
	{
		res.val = 0;
		return (res.val);
	}
	if(f->acid_color == 0)
	{
		res.chnl.g = ((double)i / f->maxiter) * 255;
		return (res.val);
	}
	freq = 0.56;
	index = (i + 1 - (log((log(sqrt(z.rl * z.rl + z.im * z.im))
		/ 2) / log(2)) / log(2))) * freq;
	res.chnl.r = cos(index) * 127 + 128;
	res.chnl.g = cos(index + f->colorshift) * 127 + 128;
	res.chnl.b = cos(index + 2 * f->colorshift) * 127 + 128;
	return (res.val);
}

int				ft_exit_x(t_fract *f)
{
	if (f->img.ptr)
		mlx_destroy_image(f->mlx, f->img.ptr);
	mlx_destroy_window(f->mlx, f->win);
	if (f->fract != NULL)
		free(f->fract);
	if (f != NULL)
		free(f);
	exit(0);
}
