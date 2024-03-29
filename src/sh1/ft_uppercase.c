/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uppercase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:31:07 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/04 17:42:13 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_uppercase(char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		src[i] = ft_toupper(src[i]);
		i++;
	}
	return (1);
}
