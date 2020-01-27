/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 15:03:15 by vlobunet          #+#    #+#             */
/*   Updated: 2019/10/19 15:03:17 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		init_secpart(t_fractol *f)
{
	f->name.julia = 0;
	f->name.mandelbrot = 0;
	f->name.leaf = 0;
	f->name.rhombus = 0;
	f->e = 0;
	f->rot = 0;
	f->z = 300.0;
	f->padx = 0.;
	f->pady = 0.;
	f->imax = 30.;
	f->coef.x = -1.1380;
	f->coef.y = 0.2403;
	f->motion = 1;
	f->invert = -1;
	f->color_mode = 1;
	f->mod = 2;
}

t_fractol	*struct_init(int c, t_fractol *f)
{
	if (c <= 1)
		return (print_error(M_NUMBER));
	if ((f = (t_fractol *)malloc(sizeof(t_fractol))) == NULL)
		return (print_error(M_MEMORRY));
	f->wsize.win_x = WINX;
	f->wsize.win_y = WINY;
	init_secpart(f);
	return (f);
}
