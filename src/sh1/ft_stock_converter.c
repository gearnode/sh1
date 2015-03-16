/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_converter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:31:07 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/04 17:38:56 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_is_converter(char c)
{
	if (c == 'h' || c == 'l' || c == 'j' || c == 'z')
		return (1);
	return (0);
}

static void ft_stock_increment(char **format, char *converter, char c)
{
	if (c == 'H')
	{
		if (*converter != 'z' && *converter != 'j')
			*converter = c;
		*format = *format + 2;
	}
	else if (c == 'L')
	{
		if (*converter != 'z' && *converter != 'j')
			*converter = c;
		*format = *format + 2;
	}
	else if (c == 'l' || c == 'h')
	{
		if (*converter != 'z' && *converter != 'j' && *converter != 'L')
			*converter = c;
		*format = *format + 1;
	}
	if (c == 'z' || c == 'j')
	{
		*converter = c;
		*format = *format + 1;
	}
}

static int	ft_get_converter(char **format, char *converter)
{
	if (!ft_is_converter(**format))
		return (0);
	if (**format == 'h' && *(*format + 1) == 'h' && *converter != 'L')
	{
		ft_stock_increment(format, converter, 'H');
		return (1);
	}
	else if (**format == 'l' && *(*format + 1) == 'l')
	{
		ft_stock_increment(format, converter, 'L');
		return (1);
	}
	else if ((**format == 'l' || **format == 'h'))
	{
		ft_stock_increment(format, converter, **format);
		return (1);
	}
	if (**format == 'z' || **format == 'j')
	{
		ft_stock_increment(format, converter, **format);
		return (1);
	}
	return (0);
}

int			ft_stock_converter(char **format, t_fmt *arg_fmt)
{
	return (ft_get_converter(format, &(arg_fmt->converter)));
}
