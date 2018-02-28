
#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# include "../libft/libft.h"
#include <stdio.h>
# include <math.h>
# include <mlx.h>
# include <pthread.h>
//# include <fcntl.h>

typedef void		(*t_frfunc)(void*);




typedef struct		s_complex
{
	double	rl;		//x
	double	im;		//y
}					t_complex;

typedef struct		s_tcount
{
	long	i;
	long	j;
}					t_tcount;

typedef struct		s_color
{
	unsigned int	b : 8;
	unsigned int	g : 8;
	unsigned int	r : 8;
	unsigned int	a : 8;
}					t_color;

typedef union		u_pcolor
{
	uint32_t		val;
	t_color			chnl;
}					t_pcolor;

typedef struct		s_point
{
	long 		y;
	long 		x;
	t_pcolor	colr;
}					t_point;

typedef struct 		s_mandel
{
	double	minrl;
	double	maxrl;
	double	minim;
	double	maxim;
	double	step;
//	double	cimgw;
//	double	cimgh;
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
	long		h;
	long		w;
}					t_img;

typedef struct		s_fract
{
	void		*mlx;
	void		*win;
	int			win_h;
	int			win_w;
	int			zoom;
	int 		mov_y;
	int 		mov_x;
	long		maxiter;

	t_img		img;

	void		*fract;
	t_frfunc	fr_func;

	long 		thread_linenum; //*******************
}					t_fract;


typedef struct		s_threads
{
	long	tnum;
	t_fract *fr;
}					t_threads;




/*
*** ft_initialise.c
*/

t_fract				*ft_init_mlx(char *name);
int					ft_init_img(t_fract *f);

/*
*** ft_img.c
*/

void				ft_pixtoimg(t_fract *f, t_point *p);
void				ft_drawimg(t_fract *f);

/*
*** ft_mandelbrot.c
*/

int					ft_mandelbrot(void);

/*
*** ft_keyhook.c
*/

void				ft_keyhookloop(t_fract *f);

#endif