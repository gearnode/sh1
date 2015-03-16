/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itobase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:31:07 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/04 17:34:49 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			ft_catnbr(char *s, char buf[2], unsigned long long n,
					unsigned long long base)
{
	if (n >= base)
	{
		ft_catnbr(s, buf, (n / base), base);
		ft_catnbr(s, buf, (n % base), base);
	}
	else
	{
		buf[0] = "0123456789abcdef"[n];
		ft_strcat(s, buf);
	}
}

char				*ft_itobase(unsigned long long n, unsigned long long base)
{
	char			*number;
	char			buf[2];

	if ((number = (char *)ft_strnew(66 * sizeof(char))) == NULL)
		return (NULL);
	ft_bzero(number, 66);
	buf[1] = '\0';
	ft_catnbr(number, buf, n, base);
	return (number);
}
