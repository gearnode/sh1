/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itobase_signed.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:31:07 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/04 17:34:52 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_catnbr_signed(char *s, char buf[2], long long n,
				long long base)
{
	if (n >= base)
	{
		ft_catnbr_signed(s, buf, (n / base), base);
		ft_catnbr_signed(s, buf, (n % base), base);
	}
	else
	{
		buf[0] = "0123456789abcdef"[n];
		ft_strcat(s, buf);
	}
}

char			*ft_itobase_signed(long long n, long long base)
{
	char		*number;
	char		buf[2];
	long long	n_cpy;

	n_cpy = n;
	if (n < 0)
		n *= -1;
	if ((number = (char *)ft_strnew(66 * sizeof(char))) == NULL)
		return (NULL);
	ft_bzero(number, 66);
	buf[1] = '\0';
	ft_catnbr_signed(number, buf, n, base);
	if (n_cpy < 0)
		strcat("-", number);
	return (number);
}
