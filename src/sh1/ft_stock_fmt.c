/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_fmt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:31:07 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/04 17:39:03 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_stock(char **fmt, t_fmt *arg_fmt)
{
	int		still_stocking;

	still_stocking = 0;
	still_stocking += ft_stock_width(fmt, arg_fmt);
	still_stocking += ft_stock_flags(fmt, arg_fmt);
	still_stocking += ft_stock_precision(fmt, arg_fmt);
	still_stocking += ft_stock_converter(fmt, arg_fmt);
	still_stocking += ft_stock_star(fmt, arg_fmt);
	return (still_stocking);
}

static int	ft_stock_wild(t_fmt *arg_fmt, int nbr, char *star_pos)
{
	if (*(star_pos - 1) == '.')
		arg_fmt->precision = ft_get_absolute(nbr);
	else if (*(star_pos - 1) != '.')
		arg_fmt->width = ft_get_absolute(nbr);
	if (*(star_pos - 1) == '.' && nbr < 0)
		arg_fmt->precision = -1;
	if (*(star_pos - 1) != '.' && nbr < 0)
		arg_fmt->flags[1] = '-';
	return (0);
}

int			ft_stock_fmt(char **fmt, t_fmt *arg_fmt, va_list ap)
{
	int		stocking;
	int		stocked_sth;
	char	*fmt_cpy;
	char	*star_pos;

	stocking = 1;
	fmt_cpy = *fmt;
	while (**fmt != '\0' && stocking != 0 && !ft_is_specifier(**fmt))
	{
		stocking = 0;
		stocking += ft_stock(fmt, arg_fmt);
		if (stocking)
			stocked_sth = 1;
		if (arg_fmt->star == '*')
			break ;
	}
	star_pos = ft_strchr(fmt_cpy, '*');
	if (arg_fmt->star == '*')
		ft_stock_wild(arg_fmt, va_arg(ap, int), star_pos);
	arg_fmt->star = '\0';
	return (stocked_sth);
}
