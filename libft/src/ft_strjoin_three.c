/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarba-v <dbarba-v@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 12:17:08 by dbarba-v          #+#    #+#             */
/*   Updated: 2025/04/09 09:26:36 by dbarba-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/* Function declarations */
char	*ft_strjoin_three(char *s1, char *s2, char *s3);

char	*ft_strjoin_three(char *s1, char *s2, char *s3)
{
	char	*temp;
	char	*joined;

	temp = ft_strjoin(s1, s2);
	if (!temp)
		return (NULL);
	joined = ft_strjoin(temp, s3);
	if (!joined)
		return (NULL);
	free(temp);
	return (joined);
}
