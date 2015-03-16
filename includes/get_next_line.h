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

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 8
# include "ft_printf.h"

typedef struct			s_read
{
	int					fd;
	char				*content;
	struct s_read		*next;
}						t_read;

int						get_next_line(int const fd, char **line);

#endif
