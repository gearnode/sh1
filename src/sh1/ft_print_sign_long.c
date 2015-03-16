/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_sign_long.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:31:07 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/04 17:37:29 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_positive_sign_long(t_fmt *arg_fmt, long long num_len,
				long long i)
{
	if (arg_fmt->flags[2] &&
		arg_fmt->width <= ft_get_max(arg_fmt->precision, num_len) + 1)
		ft_put_sign('+', &i);
	if ((arg_fmt->flags[2] && arg_fmt->flags[4] &&
		ft_get_max(arg_fmt->precision, num_len) + 1 < arg_fmt->width))
		ft_put_sign('+', &i);
}

static void		ft_negative_sign_long(t_fmt *arg_fmt, long long num_len,
				long long i)
{
	if (arg_fmt->flags[4] &&
		ft_get_max(arg_fmt->precision, num_len) < arg_fmt->width)
		ft_put_sign('-', &i);
	else if (arg_fmt->width == -1 && arg_fmt->precision == -1)
		ft_put_sign('-', &i);
	else if (arg_fmt->width <= num_len && arg_fmt->precision == -1)
		ft_put_sign('-', &i);
	else if (arg_fmt->width <= num_len && arg_fmt->precision <= num_len)
		ft_put_sign('-', &i);
	else if (num_len < arg_fmt->precision &&
		arg_fmt->width <= arg_fmt->precision + 1)
		ft_put_sign('-', &i);
	else if (ft_get_max(arg_fmt->precision, num_len) + 1 < arg_fmt->width &&
		arg_fmt->flags[0])
		ft_put_sign('-', &i);
	else if (arg_fmt->flags[1] && (!arg_fmt->flags[0] ||
		arg_fmt->width <= ft_get_max(arg_fmt->precision, num_len) + 1))
		ft_put_sign('-', &i);
}

long long		ft_print_sign_before_long(t_fmt *arg_fmt, long long arg,
				long long num_len)
{
	long long i;

	i = 0;
	if (arg == 0)
	{
		if (arg_fmt->flags[2])
			ft_put_sign('+', &i);
	}
	if (0 <= arg)
		ft_positive_sign_long(arg_fmt, num_len, i);
	if (arg < 0 && arg != LONG_MIN)
		ft_negative_sign_long(arg_fmt, num_len, i);
	return (i);
}

long long		ft_print_sign_after_long(t_fmt *arg_fmt, long long arg,
				long long num_len)
{
	int i;

	i = 0;
	if (arg < 0 && arg != LONG_MIN)
	{
		if (ft_get_max(arg_fmt->precision, num_len) + 1 < arg_fmt->width &&
			!arg_fmt->flags[1] && !arg_fmt->flags[4])
			ft_putchar('-');
	}
	if (0 < arg)
	{
		if (arg_fmt->flags[2] && !arg_fmt->flags[4] &&
			ft_get_max(arg_fmt->precision, num_len) < arg_fmt->width)
			ft_putchar('+');
	}
	return (i);
}
