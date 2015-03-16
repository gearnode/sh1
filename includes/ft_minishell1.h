/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell1.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 19:40:51 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/16 16:34:24 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL1_H
# define FT_MINISHELL1_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include "get_next_line.h"
# include "ft_printf.h"
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct	s_env
{
	char		**env;
}				t_env;

void			puts_env(t_env *e, char **args);
void			set_env(t_env *e, char **args);
void			unset_env(t_env *e, char **args);
void			update_env(t_env *e, char **args);
void			exit_shell(t_env *e, char **args);
void			new_env(t_env *e, char **args);
void			restruct_env(t_env *e, int index);
void			save_env(char **envp, t_env *e);
char			*join_env(char const *s1, char const *s2, char const *s3);
char			*get_path(t_env *e, char **parse_exec);
int				get_env(t_env *e, char *get);
int				size_env(char **env);
int				args_is_valid(char *arg);
void			ft_free_parse_exec(char **parse_exec);
char			**ft_split_command(char *command);
void			ft_listen_sfd(t_env *e);
char			*ft_get_post_env_name(char *post_env);
char			*ft_get_post_env_value(char *post_env);
void			change_dir(t_env *e, char **args);
void			display_error(char **args);
int				ft_is_space(char c);

#endif
