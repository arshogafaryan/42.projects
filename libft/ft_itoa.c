/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argafary <argafary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 17:18:38 by argafary          #+#    #+#             */
/*   Updated: 2022/03/14 16:48:09 by argafary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static short int	ft_digits(int num)
{
	short int	count;

	count = 1;
	num /= 10;
	while (num != 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char			*str_number;
	short int		digits;
	unsigned int	number;

	number = n;
	digits = ft_digits(n);
	if (n < 0)
	{
		number = n * (-1);
		digits++;
	}
	else
		number = n;
	str_number = (char *)malloc(digits + 1);
	if (!str_number)
		return (NULL);
	*(str_number + digits) = '\0';
	while (digits--)
	{
		*(str_number + digits) = (number % 10) + 48;
		number /= 10;
	}
	if (n < 0)
		*str_number = '-';
	return (str_number);
}
