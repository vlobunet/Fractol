/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_src.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 14:56:57 by vlobunet          #+#    #+#             */
/*   Updated: 2019/10/19 14:57:00 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	rotate_fractal(t_fractol *f, int rot)
{
	if (rot >= 0)
		while (rot >= 360)
			rot -= 360;
	else
		while (rot < 0)
			rot += 360;
	if (rot == 0 && (f->e = 0) == 0)
		while (f->z < 0)
			f->z = f->z * -1;
	else if (rot == 90 && (f->e = 1) == 1)
		while (f->z < 0)
			f->z = f->z * -1;
	else if (rot == 180 && (f->e = 2) == 2)
		while (f->z > 0)
			f->z = f->z * -1;
	else if (rot == 270 && (f->e = 3) == 3)
		while (f->z > 0)
			f->z = f->z * -1;
	f->minx = ((MINWINX + f->padx) / (f->z / 2)) / -2;
	f->miny = ((MINWINY + f->pady) / (f->z / 2)) / -2;
}

int		put_pixel(t_fractol *f, int type, int i, char *rgb)
{
	if (((type == 1 && f->x > 213) || (type != 1 && f->x >= 0))
		&& f->x < f->wsize.win_x && f->y >= 0 && f->y < f->wsize.win_x)
	{
		i = ((int)f->x * (f->m.bpixel / 8)) + ((int)f->y * f->m.size_line);
		rgb = (char *)&f->clr;
		f->m.data_addr[i] = rgb[0];
		f->m.data_addr[++i] = rgb[1];
		f->m.data_addr[++i] = rgb[2];
	}
	return (0);
}

void	reset_values(t_fractol *f)
{
	f->e = 0;
	f->rot = 0;
	f->z = 287.0;
	f->padx = 0.;
	f->pady = 0.;
	f->imax = 21.;
	f->coef.x = -1.1380;
	f->coef.y = 0.2403;
	f->motion *= -1;
	f->invert = -1;
}

void	set_zum(t_fractol *f, int key)
{
	if (key == 24)
		f->z += (f->z * 0.30);
	else if (key == 27 && (f->z > 10 || f->z < -10) && f->z > 200.9)
		f->z -= (f->z * 0.30);
}
