//
// Created by Antonin KOKOSHKO on 2/25/18.
//

#include "ft_fractol.h"

t_fract		*ft_init_mlx(int w, int h, char *name)
{
	t_fract	*f;

	if (!(f = ft_memalloc(sizeof(t_fract))))
		return (NULL);
	f->win_h = h;
	f->win_w = w;
	f->mlx = mlx_init();
	if (!(f->win = mlx_new_window(f->mlx,
								   f->win_w, f->win_h, name)))
		return (NULL);
//	ft_setmxdefault(f);
	return (f);
}

int			ft_init_img(t_fract *f)
{
	if (f->img.ptr)
		mlx_destroy_image(f->mlx, f->img.ptr);
	f->img.h = f->win_h;
	f->img.w = f->win_w;
	if (!(f->img.ptr = mlx_new_image(f->mlx, f->img.w, f->img.h)))
		return (0);
	f->img.bitperpix = sizeof(int) * 8;
	f->img.size_line = sizeof(int) * f->img.w; //?????????????? h??
	f->img.endian = 0;
	if (!(f->img.str = (uint32_t*)mlx_get_data_addr(f->img.ptr,
		&(f->img.bitperpix), &(f->img.size_line), &(f->img.endian))))
		return (0);
	return (1);
}
