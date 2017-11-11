/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listen_sfd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 20:23:24 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/16 16:34:33 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <struct.h>

void		ft_free_parse_exec(char **parse_exec)
{
	int	i;

	i = 0;
	while (parse_exec[i] != NULL)
	{
		free(parse_exec[i]);
		i++;
	}
}

static void ft_built_in(t_env *e, char **parse_exec, int *error)
{
	int			i;

	i = -1;
	while (++i < NBCMD)
	{
		if (ft_strcmp(parse_exec[0], cmd_table[i].name) == 0)
		{
			cmd_table[i].process(e, parse_exec);
			if (ft_strcmp(parse_exec[0], "env") != 0 && \
				ft_strcmp(parse_exec[0], "-i") != 0)
				*error = 0;
			break ;
		}
	}
}

static void	ft_exec_bin(t_env *e, char **parse_exec, char *command, int *error)
{
	pid_t		father;
	char		*exec;

	if (*error != 0)
	{
		*error = 0;
		if ((exec = get_path(e, parse_exec)) == NULL)
			exec = parse_exec[0];
		father = fork();
		if (father > 0)
			wait(NULL);
		if (father == 0)
		{
			parse_exec = ft_split_command(command);
			execve(exec, parse_exec, e->env);
			if (parse_exec[0])
				ft_printf("ft_minishell1: command not found: %s\n", parse_exec[0]);
			exit(0);
		}
	}
}

void		ft_listen_sfd(t_env *e)
{
	char		**parse_exec;
	char		*command;
	int			error;

	while (42)
	{
		error = -42;
		ft_putstr("minishell>> ");
		get_next_line(1, &command);
		parse_exec = ft_split_command(command);
		ft_built_in(e, parse_exec, &error);
		ft_exec_bin(e, parse_exec, command, &error);
		ft_free_parse_exec(parse_exec);
	}
}
