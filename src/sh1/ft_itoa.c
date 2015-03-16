/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:31:07 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/04 17:34:42 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long	ft_power_nbr(long long nbr, long long index)
{
	if (!nbr)
		return (1);
	while (nbr)
	{
		index++;
		nbr /= 10;
	}
	return (index);
}

char				*ft_itoa(long long n)
{
	char		*str_prov;
	long long	sign;
	long long	nbr;
	long long	power;

	sign = (n < 0) ? 1 : 0;
	nbr = n;
	power = ft_power_nbr(n, sign);
	str_prov = ft_strnew(power);
	while (power)
	{
		if (n >= 0)
			str_prov[power - 1] = ((char)((nbr % 10) + 48));
		if (n < 0 && power >= 2)
			str_prov[power - 2] = ((char)(48 - (nbr % 10)));
		power--;
		nbr /= 10;
	}
	if (n < 0)
		return (ft_strjoin("-", str_prov));
	else
		return (str_prov);
}
