/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 10:42:36 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/16 10:42:42 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

void	save_env(char **envp, t_env *e)
{
	int i;

	i = 0;
	if (!(e->env = (char **)malloc(sizeof(char *) * (size_env(envp) + 1))))
		exit(-1);
	while (envp[i])
	{
		e->env[i] = strdup(envp[i]);
		i++;
	}
	e->env[i] = NULL;
}
