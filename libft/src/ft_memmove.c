/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarba-v <dbarba-v@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 17:04:23 by dbarba-v          #+#    #+#             */
/*   Updated: 2025/01/27 09:37:08 by dbarba-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/* Function declarations */
void	*ft_memmove(void *dest, const void *src, size_t n);

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*source;
	unsigned char	*target;

	if (dest == 0 && src == 0)
		return (dest);
	source = (unsigned char *)src;
	target = (unsigned char *)dest;
	if (src <= dest)
	{
		source += n - 1;
		target += n - 1;
		while (n--)
			*target-- = *source--;
	}
	else
	{
		while (n--)
			*target++ = *source++;
	}
	return (dest);
}
