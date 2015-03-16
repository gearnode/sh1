/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restruct_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 10:45:37 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/16 10:45:38 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell1.h>

void		restruct_env(t_env *e, int index)
{
	int		len;
	char	**new_env;
	int		j;
	int		i;

	i = 0;
	j = 0;
	len = size_env(e->env) - 1;
	new_env = (char **)malloc(sizeof(char *) * (len + 1));
	while (e->env[i] != NULL)
	{
		if (i != index)
		{
			new_env[j] = ft_strdup(e->env[i]);
			j++;
		}
		free(e->env[i]);
		i++;
	}
	new_env[j] = NULL;
	free(e->env);
	e->env = new_env;
}
