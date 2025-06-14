/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarba-v <dbarba-v@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 13:17:22 by dbarba-v          #+#    #+#             */
/*   Updated: 2025/01/28 12:12:33 by dbarba-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/* Function declarations */
void	*ft_memset(void *dest, int c, size_t n);

void	*ft_memset(void *dest, int c, size_t n)
{
	unsigned char	*target;

	target = (unsigned char *)dest;
	while (n--)
		*target++ = (unsigned char)c;
	return (dest);
}
