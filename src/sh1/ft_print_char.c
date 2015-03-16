/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:31:07 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/04 17:36:38 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long		ft_print_char(va_list ap, t_fmt *arg_format)
{
	long long	nb_spaces;

	nb_spaces = 0;
	if (!arg_format->flags[1])
		nb_spaces += ft_char_spaces(arg_format->width, arg_format->flags);
	nb_spaces += ft_putchar((unsigned char)va_arg(ap, long long));
	if (arg_format->flags[1])
		nb_spaces += ft_char_spaces(arg_format->width, arg_format->flags);
	return (nb_spaces);
}
