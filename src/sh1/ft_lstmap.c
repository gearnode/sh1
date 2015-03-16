/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:31:07 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/04 17:35:09 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list_ptr;
	t_list	*new_list;
	t_list	*new_list_ptr;
	t_list	*new_list_next;

	if (!lst || !f)
		return (NULL);
	list_ptr = lst;
	new_list = (*f)(list_ptr);
	new_list_ptr = new_list;
	if (new_list == NULL)
		return (NULL);
	while (list_ptr->next != NULL)
	{
		list_ptr = list_ptr->next;
		if (!(new_list_next = (*f)(list_ptr)))
			return (NULL);
		new_list_ptr->next = new_list_next;
		new_list_ptr = new_list_next;
		while (new_list_ptr->next != NULL)
			new_list_ptr = new_list_ptr->next;
	}
	new_list_ptr->next = NULL;
	return (new_list);
}
