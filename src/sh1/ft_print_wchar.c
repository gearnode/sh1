/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_wchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:31:07 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/04 17:37:49 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long		ft_print_wchar(va_list ap, t_fmt *arg_format)
{
	long long	nb_spaces;
	long long	arg;

	nb_spaces = 0;
	arg = va_arg(ap, long long);
	if (!arg_format->flags[1])
		nb_spaces += ft_wchar_spaces(arg, arg_format->width, arg_format->flags);
	nb_spaces += ft_putwchar(arg);
	if (arg_format->flags[1])
		nb_spaces += ft_wchar_spaces(arg, arg_format->width, arg_format->flags);
	return (nb_spaces);
}
