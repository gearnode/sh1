/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:31:07 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/04 17:41:33 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (ft_memcmp(s1, s2, n) != 0)
		return (0);
	return (1);
}
