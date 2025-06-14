/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarba-v <dbarba-v@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 12:25:20 by dbarba-v          #+#    #+#             */
/*   Updated: 2025/04/13 15:21:48 by dbarba-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/* Function declarations */
void	ft_free(void **old_mem, void *new_mem);

/// @brief Frees memory pointed to by old_mem and replaces it with new_mem
/// @param old_mem Pointer to a pointer to be freed and reassigned
/// @param new_mem New memory address to assign to *old_mem
void	ft_free(void **old_mem, void *new_mem)
{
	free(*old_mem);
	*old_mem = new_mem;
}
