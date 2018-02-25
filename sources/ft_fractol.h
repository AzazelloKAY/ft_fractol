
#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# include "../libft/libft.h"
#include <stdio.h>
# include <math.h>
# include <mlx.h>
//# include <fcntl.h>

typedef struct		s_complex
{
	double	rl;	//x
	double	im;		//y
}					t_complex;

typedef struct		s_tcount
{
	long int	i;
	long int	j;
}					t_tcount;

typedef struct		s_color
{
	unsigned int	a : 8;
	unsigned int	r : 8;
	unsigned int	g : 8;
	unsigned int	b : 8;
}					t_color;

typedef union		u_pcolor
{
	uint32_t		val;
	t_color			chnl;
}					t_pcolor;

typedef struct		s_point
{
	int 		y;
	int 		x;
	t_pcolor	colr;
}					t_point;

typedef struct 		s_mandel
{
	double	minrl;
	double	maxrl;
	double	minim;
	double	maxim;
	double	step;
	double	dltrl;
	double	dltim;
	double	cimgw;
	double	cimgh;
	double	rl_fact;
	double	im_fact;
}					t_mandel;

typedef struct 		s_img
{
	void		*ptr;
	uint32_t	*str;
	int			bitperpix;
	int			size_line;
	int			endian;
	int			h;
	int			w;
}					t_img;

typedef struct		s_fract
{
	void		*mlx;
	void		*win;
	int			win_h;
	int			win_w;
	int			zoom;
	int 		precis;

	t_img		img;

	void		*fract;
}					t_fract;

#endif