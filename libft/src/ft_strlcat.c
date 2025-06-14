/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarba-v <dbarba-v@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:37:31 by dbarba-v          #+#    #+#             */
/*   Updated: 2025/04/13 09:57:11 by dbarba-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/* Function declarations */
size_t	ft_strlcat(char *dst, const char *src, size_t dst_memsize);

size_t	ft_strlcat(char *dst, const char *src, size_t dst_memsize)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dst_memsize <= dst_len)
		return (dst_memsize + src_len);
	i = 0;
	while (src[i] && (dst_len + i) < (dst_memsize - 1))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = 0;
	return (dst_len + src_len);
}
