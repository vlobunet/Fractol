/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 14:51:20 by vlobunet          #+#    #+#             */
/*   Updated: 2019/10/19 14:51:23 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	set_gradient(t_fractol *f)
{
	float	p;

	p = f->i * 1.0 / f->imax;
	if (p > 0 && p < P_1)
		f->clr = (int)(COLOR_BLUE + (int)(KOSTIL(p, 0, COLOR_LIME)) /
			0x1000 * 0x1000);
	else if (p >= P_1 && p < P_2)
		f->clr = (int)(COLOR_AQUA - (int)(KOSTIL(p, P_1, COLOR_BLUE)) /
			0x10 * 0x10);
	else if (p >= P_2 && p < P_3)
		f->clr = (int)(COLOR_LIME + (int)(KOSTIL(p, P_2, COLOR_YELLOW)) /
			0x10000 * 0x10000);
	else if (p >= P_3 && p < P_4)
		f->clr = (int)(COLOR_YELLOW + (int)(KOSTIL(p, P_3, COLOR_BLUE)) /
			0x1000 * 0x1000);
	else if (p >= P_4)
		f->clr = (int)(COLOR_RED - (int)(KOSTIL(p, P_4, COLOR_LIME)) /
			0x100 * 0x100);
	if (f->i == f->imax)
		f->clr = (f->invert ? GRAY_00 : COLOR_RED);
}

void	set_inverse_gradient(t_fractol *f)
{
	float	p;

	p = f->i * 1.0 / f->imax;
	if (p > 0 && p < 0.25)
		f->clr = (int)(COLOR_RED + (int)(KOSTIL(p, 0, COLOR_LIME)) /
			0x100 * 0x100);
	else if (p >= 0.25 && p < 0.5)
		f->clr = (int)(COLOR_YELLOW - (int)(KOSTIL(p, 0.25, COLOR_RED)) /
			0x10000 * 0x10000);
	else if (p >= 0.5 && p < 0.75)
		f->clr = (int)(COLOR_LIME + (int)(KOSTIL(p, 0.5, COLOR_BLUE)));
	else if (p >= 0.75)
		f->clr = (int)(COLOR_AQUA - (int)(KOSTIL(p, 0.75, COLOR_LIME)) /
			0x100 * 0x100);
	if (f->i == f->imax)
		f->clr = 0;
}

void	set_withoutgrad(t_fractol *f)
{
	float	p;

	p = f->i * 1.0 / f->imax;
	if (p > 0 && p < P_1)
		f->clr = (int)0x202020;
	else if (p >= P_1 && p < P_2)
		f->clr = (int)COLOR_YELLOW;
	else if (p >= P_2 && p < P_3)
		f->clr = (int)COLOR_BLUE;
	else if (p >= P_3 && p < P_4)
		f->clr = (int)COLOR_YELLOW;
	else if (p >= P_4)
		f->clr = (int)0xf5f5f5;
	if (f->i == f->imax)
		f->clr = (f->invert ? GRAY_00 : COLOR_RED);
}

void	set_gray_color(t_fractol *f)
{
	float	p;

	p = f->i * 1.0 / f->imax;
	p > 0 && p <= G_1 ? f->clr = (int)GRAY_00 : 0;
	p > G_1 && p <= G_2 ? f->clr = (int)GRAY_19 : 0;
	p > G_2 && p <= G_3 ? f->clr = (int)GRAY_32 : 0;
	p > G_3 && p <= G_4 ? f->clr = (int)GRAY_4B : 0;
	p > G_4 && p <= G_5 ? f->clr = (int)GRAY_64 : 0;
	p > G_6 && p <= G_7 ? f->clr = (int)GRAY_7D : 0;
	p > G_7 && p <= G_8 ? f->clr = (int)GRAY_96 : 0;
	p > G_8 && p <= G_9 ? f->clr = (int)GRAY_AF : 0;
	p > G_9 ? f->clr = (int)GRAY_C8 : 0;
	if (f->i == f->imax)
		f->clr = (f->invert ? GRAY_FA : COLOR_RED);
}

void	set_color(t_fractol *f)
{
	f->color_mode == 5 ? f->color_mode = 1 : 0;
	f->color_mode == 1 ? set_gray_color(f) : 0;
	f->color_mode == 2 ? set_gradient(f) : 0;
	f->color_mode == 3 ? set_inverse_gradient(f) : 0;
	f->color_mode == 4 ? set_withoutgrad(f) : 0;
}
