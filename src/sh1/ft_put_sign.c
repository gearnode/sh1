/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_sign.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:31:07 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/04 17:38:03 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_sign(char c, long long *i)
{
	ft_putchar(c);
	*i = *i + 1;
}