/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_fmt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:31:07 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/04 17:46:16 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_fmt	*ft_create_fmt(void)
{
	t_fmt	*arg_format;

	arg_format = malloc(sizeof(t_fmt));
	arg_format->flags = ft_strnew(5);
	arg_format->width = -1;
	arg_format->precision = -1;
	arg_format->specifier = '\0';
	arg_format->converter = '\0';
	arg_format->star = '\0';
	return (arg_format);
}
