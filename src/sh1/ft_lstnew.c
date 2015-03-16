/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:31:07 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/04 17:35:11 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_list;

	new_list = (t_list *)malloc(sizeof(t_list));
	if (!new_list)
		return (NULL);
	new_list->next = (t_list *)NULL;
	new_list->content = (void *)NULL;
	new_list->content_size = 0;
	if ((content == NULL) || (content_size <= 0))
		return (new_list);
	if (!(new_list->content = ft_memalloc(content_size + 1)))
		return ((t_list*)(NULL));
	ft_memcpy(new_list->content, content, content_size);
	new_list->content_size = content_size;
	return (new_list);
}
