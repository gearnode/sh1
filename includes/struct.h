/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 15:31:37 by bfrimin           #+#    #+#             */
/*   Updated: 2015/02/27 22:52:15 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "ft_minishell1.h"
# define NBCMD 5

typedef struct		s_proto_cmd
{
	const char		*name;
	void			(*process) (t_env *, char **);
}					t_proto_cmd;

struct s_proto_cmd	cmd_table[NBCMD] = {
	{ "cd", change_dir },
	{ "env", puts_env },
	{ "unsetenv", unset_env	},
	{ "setenv", set_env },
	{ "exit", exit_shell }
};

#endif
