/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:31:07 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/04 17:40:51 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strequ(char const *s1, char const *s2)
{
	if (ft_strcmp(s1, s2) != 0)
		return (0);
	return (1);
}
