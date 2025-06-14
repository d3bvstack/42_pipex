/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarba-v <dbarba-v@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 09:23:19 by dbarba-v          #+#    #+#             */
/*   Updated: 2025/04/01 16:11:31 by dbarba-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/* Function declarations */
void	ft_bzero(void *s, size_t n);

/// @brief Sets n bytes of memory to zero starting from *s.
/// @param s Pointer to the starting point from which to set the memory.
/// @param n Number of bytes to set to 0.
void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*s1;

	if (!s)
		return ;
	s1 = (char *)s;
	i = 0;
	while (i < n)
	{
		s1[i++] = 0;
	}
	return ;
}
