/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:31:07 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/04 17:37:14 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			ft_is_x(char specifier)
{
	if (specifier == 'x' || specifier == 'X')
		return (1);
	return (0);
}

static char			*ft_itobase_16(unsigned long long arg, t_fmt *arg_fmt)
{
	char	*num;

	if (arg_fmt->converter == 'H' && arg_fmt->specifier != 'p')
		num = ft_itobase((unsigned char)arg, 16);
	else if (arg_fmt->converter == 'h' && arg_fmt->specifier != 'p')
		num = ft_itobase((unsigned short)arg, 16);
	else if (ft_is_x(arg_fmt->specifier) && !(arg_fmt->converter == 'l' ||
		arg_fmt->converter == 'L' || arg_fmt->converter == 'z' ||
		arg_fmt->converter == 'j'))
	{
		num = ft_itobase((unsigned int)arg, 16);
	}
	else if (arg_fmt->precision == 0 && arg == 0)
		num = ft_strdup("");
	else
		num = ft_itobase(arg, 16);
	return (num);
}

long long			ft_print_hexa(va_list ap, t_fmt *arg_fmt)
{
	char				*num;
	long long			num_len;
	long long			nb_spaces;
	unsigned long long	arg;
	long long			printed;

	arg = va_arg(ap, unsigned long long);
	nb_spaces = 0;
	if (arg_fmt->precision == 0 && arg == 0)
		num = ft_strdup("");
	else
		num = ft_itobase_16(arg, arg_fmt);
	if (arg_fmt->specifier == 'X')
		ft_uppercase(num);
	num_len = (long long)ft_strlen(num);
	nb_spaces += ft_hexa_spaces_before(arg_fmt, num_len, arg);
	ft_putstr(num);
	printed = num_len + nb_spaces;
	nb_spaces += ft_hexa_spaces_after(arg_fmt, num_len, arg, printed);
	free(num);
	return (num_len + nb_spaces);
}
