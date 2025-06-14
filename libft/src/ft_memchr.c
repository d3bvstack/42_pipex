/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarba-v <dbarba-v@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:23:11 by dbarba-v          #+#    #+#             */
/*   Updated: 2025/01/27 09:35:55 by dbarba-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/* Function declarations */
void	*ft_memchr(const void *s, int c, size_t n);

/// @brief Locate first occurrence of byte c in memory area s within n bytes
/// @param s Memory area to search
/// @param c Byte to find (converted to unsigned char)
/// @param n Maximum bytes to examine
/// @return Pointer to matching byte or NULL if not found
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	search_char;

	ptr = (unsigned char *)s;
	search_char = (unsigned char)c;
	while (n)
	{
		if (*ptr == search_char)
			return ((void *)ptr);
		ptr++;
		n--;
	}
	return (NULL);
}
