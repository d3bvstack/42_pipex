/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarba-v <dbarba-v@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 18:08:40 by dbarba-v          #+#    #+#             */
/*   Updated: 2025/04/13 15:21:35 by dbarba-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/* Function declarations */
void	ft_free_all(void *first, ...);

/// @brief Frees multiple memory blocks passed as arguments.
/// @param first The first pointer to free.
/// @param ... Additional pointers to free, terminated by NULL.
void	ft_free_all(void *first, ...)
{
	va_list	args;
	void	*current;

	if (first != NULL)
	{
		free(first);
	}
	va_start(args, first);
	current = va_arg(args, void *);
	while (current != NULL)
	{
		free(current);
		current = va_arg(args, void *);
	}
	va_end(args);
}
