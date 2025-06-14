/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarba-v <dbarba-v@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:40:16 by dbarba-v          #+#    #+#             */
/*   Updated: 2025/06/13 12:49:25 by dbarba-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/* Function declarations */
char	*ft_strjoin(char const *s1, char const *s2);

/// @brief Creates a new string with allocated memory that joins 2 strings.
/// @param s1 First string
/// @param s2 Second string
/// @return On success: A new allocated string with s1 + s2
///			On failure: Pointer to NULL
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*newstr;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	newstr = malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (!newstr)
		return (NULL);
	while (s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		newstr[i + j] = s2[j];
		j++;
	}
	newstr[i + j] = '\0';
	return (newstr);
}
