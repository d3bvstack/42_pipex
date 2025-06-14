/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarba-v <dbarba-v@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:06:06 by dbarba-v          #+#    #+#             */
/*   Updated: 2025/04/11 10:34:38 by dbarba-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/* Function declarations */
long	ft_atol(const char *nptr);

/// @brief Converts the initial portion of the string to long representation.
/// @param nptr The string to convert.
/// @return The converted value as a long integer.
long	ft_atol(const char *nptr)
{
	int		sign;
	int		i;
	long	result;

	sign = 1;
	i = 0;
	result = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (ft_issign(nptr[i]))
	{
		if (ft_issign(nptr[i]) == 2)
			sign = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		result *= 10;
		result += (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}
