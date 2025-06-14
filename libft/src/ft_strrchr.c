/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarba-v <dbarba-v@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:36:26 by dbarba-v          #+#    #+#             */
/*   Updated: 2025/06/10 22:25:17 by dbarba-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/* Function declarations */
char	*ft_strrchr(const char *str, int c);

char	*ft_strrchr(const char *str, int c)
{
    const char	*found = NULL;

    while (1)
    {
        if (*str == (unsigned char)c)
            found = str;
        if (*str == '\0')
            break;
        str++;
    }
    return (char *)found;
}
