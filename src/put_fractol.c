/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_fractol.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 15:05:23 by vlobunet          #+#    #+#             */
/*   Updated: 2019/10/19 15:05:25 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	mandelbrot(t_fractol *f)
{
	f->i = 2.0;
	f->zr = 0.0;
	f->zi = 0.0;
	f->mr = (f->e == 0 || f->e == 2) ? (D(f->x) / f->z) + f->minx :
	(D(f->y) / f->z) + f->miny;
	f->mi = (f->e == 0 || f->e == 2) ? (D(f->y) / f->z) + f->miny :
	(D(f->x) / f->z) + f->minx;
	while (++f->i < f->imax && (f->zr * f->zr + f->zi * f->zi) < 4)
	{
		f->tmp = f->zr;
		f->zr = (f->zr * f->zr) - (f->zi * f->zi) + f->mr;
		f->zi = f->mod * f->zi * f->tmp + f->mi;
	}
	set_color(f);
	put_pixel(f, 0, 0, NULL);
}

void	julia(t_fractol *f)
{
	f->i = 0.0;
	f->mod = 2;
	f->zr = (f->e == 0 || f->e == 2) ? (D(f->x) / f->z) + f->minx :
	(D(f->y) / f->z) + f->miny;
	f->zi = (f->e == 0 || f->e == 2) ? (D(f->y) / f->z) + f->miny :
	(D(f->x) / f->z) + f->minx;
	while (++f->i < f->imax && (f->zr * f->zr + f->zi * f->zi) < 4)
	{
		f->tmp = f->zr;
		f->zr = (f->zr * f->zr) - (f->zi * f->zi) + f->coef.x;
		f->zi = f->mod * f->zi * f->tmp + f->coef.y;
	}
	set_color(f);
	put_pixel(f, 0, 0, NULL);
}

void	rhombus(t_fractol *f)
{
	f->zr = 0.0;
	f->zi = 0.0;
	f->i = 11;
	f->mod = 2;
	f->zr = (f->e == 0 || f->e == 2) ? (D(f->x) / f->z) + f->minx :
	(D(f->y) / f->z) + f->miny;
	f->zi = (f->e == 0 || f->e == 2) ? (D(f->y) / f->z) + f->miny :
	(D(f->x) / f->z) + f->minx;
	while (++f->i < f->imax && (f->zr * f->zr + f->zi * f->zi) < 100)
	{
		f->tmp = f->zr * f->zr + f->zi * f->zi + GET_COEFFICIENT_X(382);
		f->zi = f->mod * f->zr * f->zi + GET_COEFFICIENT_Y(352);
		f->zr = f->tmp;
	}
	set_color(f);
	put_pixel(f, 0, 0, NULL);
}

void	leaf(t_fractol *f)
{
	f->zr = 0.0;
	f->zi = 0.0;
	f->i = 10.0;
	f->mod = 2;
	f->zr = (f->e == 0 || f->e == 2) ? (D(f->x) / f->z) + f->minx :
	(D(f->y) / f->z) + f->miny;
	f->zi = (f->e == 0 || f->e == 2) ? (D(f->y) / f->z) + f->miny :
	(D(f->x) / f->z) + f->minx;
	while (++f->i < f->imax && (f->zr * f->zr + f->zi * f->zi) < 4)
	{
		f->zi = fabsl(f->zi);
		f->tmp = f->zr * f->zr - f->zi * f->zi + GET_COEFFICIENT_X(844);
		f->zi = f->mod * f->zr * f->zi + GET_COEFFICIENT_Y(417);
		f->zr = f->tmp;
	}
	set_color(f);
	put_pixel(f, 0, 0, NULL);
}

void	draw_fractal(t_fractol *f)
{
	f->y = -1;
	rotate_fractal(f, f->rot);
	while (++f->y < g_h && (f->x = -1) == -1)
	{
		while (++f->x < g_w)
		{
			if (f->name.julia)
				julia(f);
			else if (f->name.mandelbrot)
				mandelbrot(f);
			else if (f->name.leaf)
				leaf(f);
			else if (f->name.rhombus)
				rhombus(f);
		}
	}
}
