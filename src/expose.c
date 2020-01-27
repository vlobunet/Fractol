/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 14:54:45 by vlobunet          #+#    #+#             */
/*   Updated: 2019/10/19 14:54:47 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	drav_leftpart(t_fractol *f, int i)
{
	mlx_string_put(f->m.mlx, f->m.win, 37, INTER(i), UI_CLR, "MOVE LEFT    A");
	mlx_string_put(f->m.mlx, f->m.win, 37, INTER(i), UI_CLR, "MOVE RIGHT   D");
	mlx_string_put(f->m.mlx, f->m.win, 37, INTER(i), UI_CLR, "MOVE UP      W");
	mlx_string_put(f->m.mlx, f->m.win, 37, INTER(i), UI_CLR, "MOVE DOWN    S");
	mlx_string_put(f->m.mlx, f->m.win, 37, INTER(i), UI_CLR, "DETAILS(+)   E");
	mlx_string_put(f->m.mlx, f->m.win, 37, INTER(i), UI_CLR, "DETAILS(-)   Q");
	mlx_string_put(f->m.mlx, f->m.win, 37, INTER(i), UI_CLR, "CHANGE COLOR Q");
	mlx_string_put(f->m.mlx, f->m.win, 37, INTER(i), UI_CLR, "RESET        R");
	mlx_string_put(f->m.mlx, f->m.win, 37, INTER(i) + 20,\
		UI_CLR, "EXIT       ESC");
	mlx_string_put(f->m.mlx, f->m.win, 37,\
		f->wsize.win_y - 30, UI_CLR, "@vlobunet");
}

void	drav_text(t_fractol *f, int sum, char *str)
{
	drav_leftpart(f, 0);
	str = ft_itoa(f->cursor_y);
	sum = (3 + ft_strlen(str)) * 10;
	mlx_string_put(f->m.mlx, f->m.win, f->wsize.win_x - sum,
		f->wsize.win_y - 30, UI_CLR, str);
	ft_strdel(&str);
	sum += 10;
	mlx_string_put(f->m.mlx, f->m.win, f->wsize.win_x - sum,
		f->wsize.win_y - 30, UI_CLR, ":");
	str = ft_itoa(f->cursor_x);
	sum += (ft_strlen(str)) * 10;
	mlx_string_put(f->m.mlx, f->m.win, f->wsize.win_x - sum,
		f->wsize.win_y - 30, UI_CLR, str);
	ft_strdel(&str);
}

int		expose_func(t_fractol *f)
{
	f->m.img = mlx_new_image(f->m.mlx, f->wsize.win_x, f->wsize.win_y);
	f->m.data_addr = mlx_get_data_addr(f->m.img, &f->m.bpixel,\
		&f->m.size_line, &f->m.endian);
	draw_fractal(f);
	mlx_put_image_to_window(f->m.mlx, f->m.win, f->m.img, 0, 0);
	drav_text(f, 0, NULL);
	return (0);
}
