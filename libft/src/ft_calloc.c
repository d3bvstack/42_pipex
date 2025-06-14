/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarba-v <dbarba-v@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:13:13 by dbarba-v          #+#    #+#             */
/*   Updated: 2025/04/01 16:11:34 by dbarba-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/* Function declarations */
void	*ft_calloc(size_t nmemb, size_t size);

/// @brief Allocates memory for an array of 'nmemb' elements of 'size' bytes
///        each and initializes all bytes to zero.
/// @param nmemb Number of elements.
/// @param size Size in bytes of each element.
/// @return A pointer to the allocated memory. Returns NULL if allocation fails
///         or if the multiplication of nmemb and size overflows.
/// @note If nmemb or size is 0, it attempts to allocate 1 byte.
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*buffer;

	if (nmemb <= 0 || size <= 0)
	{
		nmemb = 1;
		size = 1;
	}
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	buffer = malloc(nmemb * size);
	if (!buffer)
		return (NULL);
	ft_bzero(buffer, nmemb * size);
	return (buffer);
}
