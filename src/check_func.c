/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 14:50:22 by vlobunet          #+#    #+#             */
/*   Updated: 2019/10/19 14:50:24 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	check_name_fractol(char *name, t_fractol *f)
{
	char	*tmp;

	tmp = ft_settolower(name);
	if (!ft_strcmp(tmp, "julia"))
		f->name.julia = 1;
	else if (!ft_strcmp(tmp, "mandelbrot"))
		f->name.mandelbrot = 1;
	else if (!ft_strcmp(tmp, "leaf"))
		f->name.leaf = 1;
	else if (!ft_strcmp(tmp, "rhombus"))
		f->name.rhombus = 1;
	else
		print_warning(M_OPTION_SHORT, name);
	ft_strdel(&tmp);
}

int		attribute_check(char **v, char *tmp, t_fractol *f)
{
	while (*v)
	{
		tmp = ft_settolower(*v);
		if (*(v + 1) && !ft_strcmp(tmp, "-x") && if_isallnum(*(v + 1)))
			f->wsize.win_x = ft_atoi(*(v + 1));
		else if (*(v + 1) && !ft_strcmp(tmp, "-y") && if_isallnum(*(v + 1)))
			f->wsize.win_y = ft_atoi(*(v + 1));
		else if (*(v + 1) && !ft_strcmp(tmp, "-n"))
		{
			while (*(v + 1) && ft_isalpha(*(v + 1)[0]))
			{
				check_name_fractol(*(v + 1), f);
				v++;
			}
		}
		ft_strdel(&tmp);
		v++;
	}
	g_w = f->wsize.win_x;
	g_h = f->wsize.win_y;
	return (0);
}

uint8_t	check_data(uint8_t res, t_fractol *f)
{
	if (f->wsize.win_x < MINWINX || f->wsize.win_y < MINWINY ||
		f->wsize.win_x > MAXW || f->wsize.win_y > MAXH)
	{
		res = 1;
		print_error(M_SIZE);
		ft_putstr_fd(M_UN, 2);
	}
	if (!f->name.julia && !f->name.mandelbrot &&
		!f->name.rhombus && !f->name.leaf)
	{
		res = 1;
		print_error(M_NOF);
		ft_putstr_fd(M_UN, 2);
	}
	return (res);
}
