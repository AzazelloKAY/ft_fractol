
#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# include "../libft/libft.h"
#include <stdio.h>

typedef struct		s_complex
{
	double	rl;
	double	im;
}					t_complex;

typedef struct		s_color
{
	unsigned int	a : 8;
	unsigned int	r : 8;
	unsigned int	g : 8;
	unsigned int	b : 8;
}					t_color;

typedef union		u_point
{
	unsigned int	colr;
	t_color			chnl;
}					t_point;

typedef struct		s_fract
{
	void	*mlx;
	void	*win;
	int		win_h;
	int		win_w;
	int		zoom;
	int 	precis;
	/*
	t_map	*map;
	t_ver	*res;
	t_img	img;
	t_mod	tr;
	 */
}					t_fract;

#endif