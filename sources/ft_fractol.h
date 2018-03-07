
#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# include "../libft/libft.h"
# include <stdio.h>
# include <math.h>
# include </usr/local/include/mlx.h>
//# include <mlx.h>
# include <pthread.h>
//# include <fcntl.h>

//#include <complex.h>

# define FT_ZOOMSTP 1.1
# define FT_ZOOMMAX 5000000000
# define FT_MOVLIM 500000
# define FT_ITERSTP 1.009
# define FT_STEP 0.1




typedef struct		s_complex
{
	double	im;		//y
	double	rl;		//x
}					t_complex;

//typedef struct		s_tcount
//{
//	long	i;
//	long	j;
//}					t_tcount;

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
	double	rl_fact;
	double	im_fact;
}					t_mandel;

//typedef struct 		s_julia
//{
//	double	minrl;
//	double	maxrl;
//	double	minim;
//	double	maxim;
//	double	rl_fact;
//	double	im_fact;
//}					t_julia;

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

typedef	struct		s_fract t_fract;

typedef void		(*t_frfunc)(t_fract*);
typedef int			(*t_init)(t_fract*);

typedef struct		s_fract
{
	void		*mlx;
	void		*win;
	int			win_h;
	int			win_w;
	double		zoom;
	double		step;
	double 		mov_y;
	double 		mov_x;
	double		maxiter;
	t_complex 	mouse;
	t_complex	mouse_alt;
	int 		live_mouse;
	int 		live_mouse_move;
	int 		mmoved;
	int			acid_color;

	t_img		img;

	void		*fract;
	t_frfunc	fract_func;
	t_init		fract_init;

	//long 		thread_linenum; //*******************
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
int					ft_initman(t_fract *f);

/*
*** ft_img.c
*/

void				ft_pixtoimg(t_fract *f, t_point *p);
void				ft_drawimg(t_fract *f);
uint32_t			ft_makecolor(t_fract *f, uint32_t c, long i, t_complex z);

/*
*** ft_mandelbrot.c
*/

int					ft_initman(t_fract *f);
void				ft_calc_man(t_fract *f);
void				ft_mandelbrot(void);

/*
*** ft_keyhook.c
*/

void				ft_keyhookloop(t_fract *f);

/*
*** ft_julia.c
*/

void				ft_calc_jul(t_fract *f);
void				ft_julia(void);

#endif