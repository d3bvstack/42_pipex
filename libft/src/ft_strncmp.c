/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarba-v <dbarba-v@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:51:36 by dbarba-v          #+#    #+#             */
/*   Updated: 2025/04/01 16:12:05 by dbarba-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/* Function declarations */
int	ft_strncmp(const char *s1, const char *s2, size_t n);

/// @brief Compares two given strings up to n characters.
/// @param s1 First string passed.
/// @param s2 Second string passed.
/// @param n Number of characters to compare.
/// @return 0 if the compared strings are exactly the same.
///			Non-zero if the compared strings are different.
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2 || n <= 0)
		return (-1);
	while (n)
	{
		if (s1[i] != s2[i] || !s1[i] || !s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
		n--;
	}
	return (0);
}
