/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_spaces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:31:07 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/04 17:29:53 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_int_spaces(t_fmt *arg_fmt, int num_len)
{
	int	nb_spaces;
	int	nb_spaces_cpy;

	if (arg_fmt->width <= num_len || arg_fmt->width <= -1)
		return (0);
	else if (arg_fmt->flags[3] == ' ' && !arg_fmt->flags[2])
		nb_spaces = arg_fmt->width - num_len - 1;
	else
		nb_spaces = arg_fmt->width - num_len;
	nb_spaces_cpy = nb_spaces;
	while (nb_spaces && -1 < nb_spaces)
	{
		if (!arg_fmt->flags[1] && arg_fmt->flags[4] && arg_fmt->precision == -1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		nb_spaces--;
	}
	return (nb_spaces_cpy);
}
