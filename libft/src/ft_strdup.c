/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarba-v <dbarba-v@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:23:52 by dbarba-v          #+#    #+#             */
/*   Updated: 2025/04/01 16:11:55 by dbarba-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/* Function declarations */
char	*ft_strdup(const char *s);

/// @brief Duplicates a string with allocated memory.
/// @param s String to be duplicated.
/// @return On success: Pointer to the first char of the new string.
///			On failure: NULL.
char	*ft_strdup(const char *s)
{
	char	*new_str;
	size_t	i;

	if (!s)
		return (malloc(1));
	new_str = (char *)malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new_str[i] = s[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
