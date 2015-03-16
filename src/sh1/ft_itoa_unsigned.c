/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:31:07 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/04 17:34:46 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned long long	ft_power_nbr(unsigned long long nbr)
{
	unsigned long long power;

	power = 0;
	if (!nbr)
		return (1);
	while (nbr)
	{
		power++;
		nbr /= 10;
	}
	return (power);
}

char						*ft_itoa_unsigned(unsigned long long nbr)
{
	char					*str_prov;
	unsigned long long		power;

	power = ft_power_nbr(nbr);
	str_prov = ft_strnew(power);
	while (power)
	{
		str_prov[power - 1] = ((char)((nbr % 10) + 48));
		power--;
		nbr /= 10;
	}
	return (str_prov);
}
