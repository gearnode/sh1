/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:31:07 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/04 17:39:00 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_is_valid_flag(char c)
{
	if (c == '#' || c == '0' || c == '+' || c == '-' || c == ' ')
		return (1);
	return (0);
}

static int		ft_get_flag(char **format, char *flags)
{
	if (!ft_is_valid_flag(**format))
		return (0);
	if (**format == '#')
		flags[0] = **format;
	if (**format == '-')
		flags[1] = **format;
	if (**format == '+')
		flags[2] = **format;
	if (**format == ' ')
		flags[3] = **format;
	if (**format == '0' && !ft_isdigit(*(*format - 1)))
		flags[4] = **format;
	return (1);
}

int				ft_stock_flags(char **format, t_fmt *arg_fmt)
{
	int	flag_filled;

	flag_filled = 0;
	while (ft_get_flag(format, arg_fmt->flags))
	{
		flag_filled = 1;
		*format = *format + 1;
	}
	return (flag_filled);
}
