//
// Created by Antonin KOKOSHKO on 2/25/18.
//

#include "ft_fractol.h"

void		ft_initmandel(t_img *i, t_mandel *m)
{
	m->step = 0.01;
	m->minrl = -2.0;
	m->maxrl = 1.0;
	m->minim = -1.2;
	m->dltrl = m->maxrl - m->minrl;
	m->dltim = m->maxim - m->minim;
	m->maxim = m->minrl + m->dltrl * i->h / i->w;
	m->rl_fact = m->dltrl / (i->w - 1);
	m->im_fact = m->dltim / (i->h - 1);
}

void		ft_mandelbrot(t_fract *f)
{
	//t_point		p;
	t_tcount	t;
	t_complex	z;
	t_mandel	*m;

	ft_bzero(&t, sizeof(t_tcount));
	m = (t_mandel*)f->fract;
	while (t.i < f->img.h)
	{
		z.im = m->maxim - (t.i * m->im_fact);
		while (t.j < f->img.w)
		{
			z.rl = m->minrl + (t.j * m->rl_fact);
			t.j++;
		}
		t.i++;
	}


	/*
	double Z_re = c_re, Z_im = c_im; // Set Z = c
        bool isInside = true;
        for(unsigned n=0; n<MaxIterations; ++n)
        {
            if( ZABS > 2) ///* Absolute value of Z
	{
		isInside = false;
		break;
	}
	// Z = Z2 + c
}
if(isInside) { putpixel(x, y); }
*/



}
