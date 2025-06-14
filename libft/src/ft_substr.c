/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarba-v <dbarba-v@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 09:31:53 by dbarba-v          #+#    #+#             */
/*   Updated: 2025/05/13 09:14:44 by dbarba-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/* Function declarations */
char	*ft_substr(char const *source, unsigned int start, size_t len);

/// @brief Allocates and returns a substring from the string 'source'.
/// @param source The string from which to create the substring.
/// @param start The start index of the substring in 'source'.
/// @param len The maximum length of the substring.
/// @return The substring, or NULL if allocation fails.
char	*ft_substr(char const *source, unsigned int start, size_t len)
{
	char	*substring;
	size_t	source_len;

	if (!source)
		return (NULL);
	source_len = ft_strlen(source);
	if (start >= source_len || len == 0)
		return (ft_strdup(""));
	if (len > source_len - start)
		len = source_len - start;
	substring = malloc(sizeof(char) * (len + 1));
	if (!substring)
		return (NULL);
	ft_strlcpy(substring, source + start, len + 1);
	return (substring);
}
