/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarba-v <dbarba-v@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:21:03 by dbarba-v          #+#    #+#             */
/*   Updated: 2025/05/27 09:27:37 by dbarba-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_pow(int base, int exp)
{
	int	result;

	result = 1;
	while (exp > 0)
	{
		result *= base;
		exp--;
	}
	return (result);
}

void	digit_iterator(const char *nptr, int *i_decimals, int *result)
{
	while (ft_isdigit(*nptr) || (*i_decimals < 0 && *nptr == '.'))
	{
		if (*nptr == '.')
		{
			nptr++;
			*i_decimals = 0;
			continue ;
		}
		*result = *result * 10 + (*nptr - '0');
		if (*i_decimals >= 0)
			*i_decimals = (*i_decimals) + 1;
		nptr++;
	}
}

float	ft_atof(const char *nptr)
{
	int	sign;
	int	i_decimals;
	int	result;

	sign = 1;
	i_decimals = -1;
	result = 0;
	while (ft_isspace(*nptr))
		nptr++;
	if (ft_issign(*nptr))
	{
		if (ft_issign(*nptr) == 2)
			sign = -1;
		nptr++;
	}
	digit_iterator(nptr, &i_decimals, &result);
	if (i_decimals > 0)
		return ((float)(result * sign) / ft_pow(10, i_decimals));
	return ((float)result * sign);
}
