/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 15:04:37 by vlobunet          #+#    #+#             */
/*   Updated: 2019/10/19 15:04:39 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		main(int argc, char **argv)
{
	t_fractol	*f;

	if (!(f = struct_init(argc, NULL)) ||
		attribute_check(argv + 1, NULL, f) || check_data(0, f))
		exit(1);
	init_window(f);
	return (0);
}
