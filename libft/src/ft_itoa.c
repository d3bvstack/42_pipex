/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarba-v <dbarba-v@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:20:56 by dbarba-v          #+#    #+#             */
/*   Updated: 2025/06/10 21:40:39 by dbarba-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/* Function declarations */
static int	ft_int_length(int n);
char		*ft_itoa(int n);

static int	ft_int_length(int n)
{
	int		lenght;
	long	num;

	lenght = 0;
	num = n;
	if (num < 0)
	{
		lenght++;
		num = -num;
	}
	while (num >= 10)
	{
		num /= 10;
		lenght++;
	}
	return (lenght);
}

char	*ft_itoa(int n)
{
	long	num;
	char	*result;
	int		i;

	if (n == 0)
	{
		return ("0");
	}
	num = n;
	i = ft_int_length(num);
	result = malloc(sizeof(char) * (i + 1));
	if (!result)
		return (NULL);
	if (num < 0)
	{
		result[0] = '-';
		num = -num;
	}
	result[i] = 0;
	while (--i >= 0 && result[i] != '-')
	{
		result[i] = (num % 10) + '0';
		num /= 10;
	}
	return (result);
}
