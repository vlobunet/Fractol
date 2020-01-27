/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 14:58:58 by vlobunet          #+#    #+#             */
/*   Updated: 2019/10/19 14:59:01 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		mouse_hook(int button, int x, int y, t_fractol *f)
{
	if (x >= 0 && x < f->wsize.win_x && y >= 0 && y < f->wsize.win_y)
	{
		if (button == 1)
		{
			f->padx = round((D(MINWINX + f->padx) - D(x)) * 1.30);
			f->pady = round((D(MINWINY + f->pady) - D(y)) * 1.30);
		}
		else if (button == 2)
		{
			f->padx = round((D(MINWINX + f->padx) - D(x)) * 0.70);
			f->pady = round((D(MINWINY + f->pady) - D(y)) * 0.70);
		}
		if (button == 1 || button == 5)
			f->z += (f->z * 0.5);
		if ((button == 2 || button == 4) && (f->z > 10 || f->z < -10))
			f->z -= (f->z * 0.5);
		if (button == 3)
			f->invert *= -1;
		mlx_destroy_image(f->m.mlx, f->m.img);
		mlx_clear_window(f->m.mlx, f->m.win);
		expose_func(f);
	}
	return (0);
}

void	check_fractal(t_fractol *f, int key)
{
	f->name.julia = 0;
	f->name.mandelbrot = 0;
	f->name.rhombus = 0;
	f->name.leaf = 0;
	key == 18 ? f->name.julia = 1 : 0;
	key == 19 ? f->name.mandelbrot = 1 : 0;
	key == 20 ? f->name.rhombus = 1 : 0;
	key == 21 ? f->name.leaf = 1 : 0;
}

int		key_hook(int key, t_fractol *f)
{
	if (key == K_ESC)
	{
		mlx_destroy_image(f->m.mlx, f->m.img);
		mlx_destroy_window(f->m.mlx, f->m.win);
		exit(0);
	}
	key == K_D ? f->padx -= 70. : 0;
	key == K_A ? f->padx += 70. : 0;
	key == K_S ? f->pady -= 70. : 0;
	key == K_W ? f->pady += 70. : 0;
	key == K_Q && f->imax > 3 ? f->imax -= 2. : 0;
	key == K_E ? f->imax += 2. : 0;
	key == 48 ? f->color_mode++ : 0;
	key == 15 ? reset_values(f) : 0;
	key == 49 ? f->motion *= -1 : 0;
	key == 10 ? f->mod *= -1 : 0;
	key >= 18 && key <= 21 ? check_fractal(f, key) : 0;
	mlx_destroy_image(f->m.mlx, f->m.img);
	mlx_clear_window(f->m.mlx, f->m.win);
	expose_func(f);
	return (0);
}

int		motion_hook(int x, int y, t_fractol *f)
{
	f->cursor_x = x;
	f->cursor_y = y;
	if ((x >= 0 && x <= f->wsize.win_x) &&
		(y >= 0 && y <= f->wsize.win_y) && f->motion == 1)
	{
		f->coef.x = GET_COEFFICIENT_X(x);
		f->coef.y = GET_COEFFICIENT_Y(y);
		mlx_destroy_image(f->m.mlx, f->m.img);
		mlx_clear_window(f->m.mlx, f->m.win);
	}
	expose_func(f);
	return (0);
}

void	init_window(t_fractol *f)
{
	f->m.mlx = mlx_init();
	f->m.win = mlx_new_window(f->m.mlx, -1, -1, f->wsize.win_x, \
		f->wsize.win_y, "vlobunet's fractol");
	mlx_expose_hook(f->m.win, expose_func, f);
	mlx_hook(f->m.win, 6, 64, motion_hook, f);
	mlx_hook(f->m.win, 2, 0, key_hook, f);
	mlx_mouse_hook(f->m.win, mouse_hook, f);
	mlx_do_key_autorepeaton(f->m.mlx);
	mlx_loop(f->m.mlx);
	exit(0);
}
