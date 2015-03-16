/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:31:07 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/04 17:36:45 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static float		ft_round(float *arg, int precision)
{
	if (precision == 0)
	{
		if (*arg - (long long)(*arg) > 0.5)
			return ((long long)(*arg) + 1);
		else if (*arg - (long long)(*arg) <= 0.5)
			return ((long long)(*arg));
	}
	return (*arg);
}

static char			*ft_itof(long long coma_index, char *dec_src, int precision)
{
	char	*dec_part;
	char	*rest_part;
	char	*dest;
	char	*transition;

	if (!coma_index)
		return (dec_src);
	dec_part = ft_strsub(dec_src, 0, coma_index);
	if (precision > 0)
	{
		transition = ft_strjoin(dec_part, ".");
		rest_part = ft_strsub(dec_src, coma_index, precision);
		dest = ft_strjoin(transition, rest_part);
		free(transition);
		free(rest_part);
		free(dec_part);
		return (dest);
	}
	else
		return (dec_part);
}

static long long	ft_print_float_spaces(long long precision)
{
	if (precision <= 0)
		return (0);
	while (precision--)
		ft_putchar('0');
	return (1);
}

static void			ft_set_to_zero(char **dest, long long *a, long long *b)
{
	*a = 0;
	*b = 0;
	*dest = NULL;
}

long long			ft_print_float(va_list ap, t_fmt *arg_fmt)
{
	char		*dec_src;
	long long	coma_index;
	char		*dest;
	long long	rest_size;
	float		arg;

	arg = va_arg(ap, double);
	arg = ft_round(&arg, arg_fmt->precision);
	ft_set_to_zero(&dest, &coma_index, &rest_size);
	while ((long long)(arg) != arg)
	{
		arg *= 10;
		rest_size++;
	}
	dec_src = ft_itoa(arg);
	coma_index = ft_strlen(dec_src) - rest_size;
	if (arg_fmt->precision == -1)
		arg_fmt->precision = 6;
	if (coma_index > -1)
		dest = ft_itof(coma_index, dec_src, arg_fmt->precision);
	free(dec_src);
	ft_putstr(dest);
	ft_print_float_spaces(arg_fmt->precision - rest_size);
	return (ft_strlen(dest) + arg_fmt->precision - rest_size);
}
