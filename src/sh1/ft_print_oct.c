/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_oct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:31:07 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/04 17:37:22 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*ft_itobase_8(unsigned long long arg, t_fmt *arg_fmt)
{
	char	*num;

	if (arg_fmt->specifier == 'o' && arg_fmt->converter == 'H')
		num = ft_itobase((unsigned char)arg, 8);
	else if (arg_fmt->specifier == 'o' && arg_fmt->converter == 'h')
		num = ft_itobase((unsigned short)arg, 8);
	else if ((arg_fmt->specifier == 'o' || arg_fmt->specifier == 'O') &&
		arg_fmt->precision == 0 && arg == 0 && !arg_fmt->flags[0])
		num = ft_strdup("");
	else if (arg_fmt->specifier == 'o' && !arg_fmt->converter)
		num = ft_itobase((unsigned int)arg, 8);
	else
		num = ft_itobase(arg, 8);
	return (num);
}

static long long	ft_print_nbr(unsigned long long arg, char *num,
					t_fmt *arg_fmt)
{
	long long len;

	len = (long long)ft_strlen(num);
	if (arg == 0 && arg_fmt->precision == 0)
		return (0);
	ft_putstr(num);
	return (len);
}

static long long	ft_nbr_len(unsigned long long arg, char *num,
					t_fmt *arg_fmt)
{
	long long len;

	len = (long long)ft_strlen(num);
	if (arg == 0 && arg_fmt->precision == 0)
		return (0);
	return (len);
}

long long			ft_print_oct(va_list ap, t_fmt *arg_fmt)
{
	char				*num;
	long long			num_len;
	long long			nb_spaces;
	unsigned long long	arg;
	long long			printed;

	arg = va_arg(ap, unsigned long long);
	nb_spaces = 0;
	num = ft_itobase_8(arg, arg_fmt);
	num_len = ft_nbr_len(arg, num, arg_fmt);
	nb_spaces += ft_oct_spaces_before(arg_fmt, num_len, arg);
	ft_print_nbr(arg, num, arg_fmt);
	printed = num_len + nb_spaces;
	nb_spaces += ft_oct_spaces_after(arg_fmt, num_len, arg, printed);
	free(num);
	return (num_len + nb_spaces);
}
