/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarba-v <dbarba-v@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:24:59 by dbarba-v          #+#    #+#             */
/*   Updated: 2025/04/13 16:22:47 by dbarba-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/// @brief Iterates the list and applies the function 'f' on the content
//         of each node.
/// @param lst The address of a pointer to a node.
/// @param f The address of the function used to iterate on the list.
/// @param del The address of the function used to delete the content of
///            a node if needed.
/// @return The new list. NULL if the allocation fails.
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list_start;
	t_list	*temp;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	new_list_start = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		temp = ft_lstnew(new_content);
		if (!temp)
		{
			del(new_content);
			ft_lstclear(&new_list_start, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list_start, temp);
		lst = lst->next;
	}
	return (new_list_start);
}
