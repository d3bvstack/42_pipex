/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarba-v <dbarba-v@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 12:49:52 by dbarba-v          #+#    #+#             */
/*   Updated: 2025/04/09 09:24:48 by dbarba-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/* Function declarations */
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

/// @brief Copy a src string up to size to a dst, the dst needs enough space.
/// @param dst Destination at which the src will be copied.
/// @param src Source string to copy.
/// @param size Number of characters to copy from src (-1 for null termination).
/// @return On success: Returns amount of characters copied.
///			On failure: Returns the amount of characters dst should have.
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;

	src_len = ft_strlen((char *)src);
	if (size != 0)
	{
		while (size-- > 1 && *src != 0)
			*dst++ = *src++;
		*dst = '\0';
	}
	return (src_len);
}
