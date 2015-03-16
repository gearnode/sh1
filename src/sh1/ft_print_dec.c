/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:31:07 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/04 17:36:42 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*ft_itobase_10(unsigned long long arg, t_fmt *arg_fmt)
{
	char	*num;

	if (arg_fmt->converter == 'l' || arg_fmt->specifier == 'U')
		num = ft_itobase((unsigned long)arg, 10);
	else if (arg_fmt->converter == 'L')
		num = ft_itobase((unsigned long long)arg, 10);
	else if (arg_fmt->converter == 'H')
		num = ft_itobase((unsigned char)arg, 10);
	else if (arg_fmt->converter == 'j')
		num = ft_itobase((uintmax_t)arg, 10);
	else if (arg_fmt->converter == 'z')
		num = ft_itobase((size_t)arg, 10);
	else if (arg_fmt->specifier == 'u' && arg_fmt->precision == 0 && arg == 0)
		num = ft_strdup("");
	else
		num = ft_itobase((unsigned int)arg, 10);
	return (num);
}

long long			ft_print_dec(va_list ap, t_fmt *arg_fmt)
{
	char				*num;
	long long			num_len;
	long long			nb_spaces;
	unsigned long long	arg;
	long long			printed;

	arg = va_arg(ap, unsigned long long);
	nb_spaces = 0;
	num = ft_itobase_10(arg, arg_fmt);
	num_len = ft_strlen(num);
	nb_spaces += ft_dec_spaces_before(arg_fmt, num_len, arg);
	ft_putstr(num);
	printed = num_len + nb_spaces;
	nb_spaces += ft_dec_spaces_after(arg_fmt, num_len, printed);
	free(num);
	return (num_len + nb_spaces);
}
