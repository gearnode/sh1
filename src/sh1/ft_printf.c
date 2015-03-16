/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:31:07 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/04 17:38:00 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_before_print(char **fmt, va_list ap, t_fmt *arg_fmt)
{
	int	outcome;
	int	nb_wild;

	nb_wild = ft_star_here(*fmt);
	outcome = ft_read_till_modulo(fmt);
	if (**fmt && nb_wild)
	{
		while (**fmt && !ft_is_specifier(**fmt) && nb_wild--)
			ft_stock_fmt(fmt, arg_fmt, ap);
	}
	ft_stock_fmt(fmt, arg_fmt, ap);
	ft_stock_specifier(fmt, &(arg_fmt->specifier), arg_fmt->converter);
	if (!arg_fmt->specifier && **fmt)
	{
		outcome += ft_print_fmtchar(**fmt, arg_fmt);
		*fmt = *fmt + 1;
	}
	return (outcome);
}

static int	ft_print_arg(va_list ap, t_fmt *arg_fmt, t_printfunc *printfunction)
{
	int	outcome;

	outcome = 0;
	while (printfunction != NULL)
	{
		if (arg_fmt->specifier == printfunction->specifier)
		{
			outcome += (*(printfunction->function_ptr))(ap, arg_fmt);
			break ;
		}
		printfunction = printfunction->next;
	}
	return (outcome);
}

int			ft_printf(char *fmt, ...)
{
	t_fmt		*arg_fmt;
	va_list		ap;
	int			outcome;
	t_printfunc *printfunction;

	if (!fmt)
		return (0);
	printfunction = ft_lstprintffull();
	outcome = 0;
	va_start(ap, fmt);
	arg_fmt = ft_create_fmt();
	while (*fmt)
	{
		outcome += ft_before_print(&fmt, ap, arg_fmt);
		if (arg_fmt->specifier)
		{
			outcome += ft_print_arg(ap, arg_fmt, printfunction);
			ft_reset_fmt(arg_fmt);
		}
	}
	free(arg_fmt->flags);
	free(arg_fmt);
	ft_lstprintf_del(&printfunction);
	va_end(ap);
	return (outcome);
}
