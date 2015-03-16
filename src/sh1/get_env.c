/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 10:46:14 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/16 14:02:58 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell1.h>

int			get_env(t_env *e, char *get)
{
	int		i;
	int		get_len;
	char	*tmp;

	i = 0;
	get_len = ft_strlen(get);
	while (e->env[i])
	{
		tmp = ft_strstr(e->env[i], get);
		if (tmp && ft_memcmp(tmp, e->env[i], get_len) == 0)
			return (i);
		i++;
	}
	return (-1);
}
