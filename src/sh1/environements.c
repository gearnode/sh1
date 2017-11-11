/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 11:59:08 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/16 16:19:31 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell1.h>

void		puts_env(t_env *e, char **args)
{
	int		i;

	i = -1;
	if (check_all_args(args) == 0)
		return ;
	while (e->env[++i])
		ft_printf("%s\n", e->env[i]);
	i = 1;
	while (args[i])
	{
		if (arg_to_display(args[i]) == 1)
			ft_printf("%s\n", args[i]);
		i++;
	}
	return ;
}

void		set_env(t_env *e, char **args)
{
	if (!args[1])
		puts_env(e, args);
	else if (args_is_valid(args[1]) == 1)
		ft_printf("setenv: Syntax Error.\n");
	else if (args[2] && args[3])
		ft_printf("setenv: Too many arguments.\n");
	else if (get_env(e, args[1]) == -1)
		new_env(e, args);
	else
		update_env(e, args);
}

void		new_env(t_env *e, char **args)
{
	int		len;
	int		i;
	char	**new_env;

	i = -1;
	len = size_env(e->env);
	if (!(new_env = (char **)malloc(sizeof(char *) * (len + 2))))
		return ;
	while (e->env[++i])
	{
		new_env[i] = ft_strdup(e->env[i]);
		free(e->env[i]);
	}
	if (!args[2])
		new_env[len] = ft_strjoin(args[1], "=");
	else
		new_env[len] = join_env(args[1], "=", args[2]);
	new_env[len + 1] = NULL;
	e->env = new_env;
}

void		update_env(t_env *e, char **args)
{
	int i;

	i = get_env(e, args[1]);
	free(e->env[i]);
	e->env[i] = NULL;
	if (!args[2])
		e->env[i] = ft_strjoin(args[1], "=");
	else
		e->env[i] = join_env(args[1], "=", args[2]);
	return ;
}

void		unset_env(t_env *e, char **args)
{
	int index;
	int	i;

	if (!args[1])
	{
		ft_printf("unsetenv: Too few arguments.\n");
		return ;
	}
	i = 1;
	while (args[i])
	{
		index = -1;
		if (args[i])
			index = get_env(e, args[i]);
		if (index != -1)
			restruct_env(e, index);
		i++;
	}
}
