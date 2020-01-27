/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 14:53:53 by vlobunet          #+#    #+#             */
/*   Updated: 2019/10/19 14:53:55 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_fractol	*print_error(char *str)
{
	ft_putstr_fd("fractol: ", 2);
	ft_putstr_fd(C_RED, 2);
	ft_putstr_fd("error: ", 2);
	ft_putstr_fd(C_RESET, 2);
	ft_putstr_fd(str, 2);
	return (NULL);
}

int			print_warning(char *str, char *name)
{
	ft_putstr_fd("fractol: ", 2);
	ft_putstr_fd(C_ORANG, 2);
	ft_putstr_fd("warning: ", 2);
	ft_putstr_fd(C_RESET, 2);
	ft_putstr_fd(str, 2);
	ft_putendl_fd(name, 2);
	return (1);
}
