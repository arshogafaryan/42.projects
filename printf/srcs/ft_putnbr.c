/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argafary <argafary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:32:11 by argafary          #+#    #+#             */
/*   Updated: 2022/04/30 16:36:39 by argafary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n, unsigned int base, int type)
{
	unsigned int	number;
	int				count;

	count = 0;
	if (n < 0)
	{
		count += ft_putchar('-');
		number = n * (-1);
	}
	else
		number = n;
	if (number > base - 1)
		count += ft_putnbr(number / base, base, type);
	number = number % base;
	if (number < 10)
		count += ft_putchar(number + 48);
	else if (number >= 10 && type == 0)
		count += ft_putchar(number + 87);
	else if (number >= 10 & type == 1)
		count += ft_putchar(number + 55);
	return (count);
}
