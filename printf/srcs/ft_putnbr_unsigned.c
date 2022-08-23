/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argafary <argafary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:04:20 by argafary          #+#    #+#             */
/*   Updated: 2022/03/23 20:14:32 by argafary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned long long n, unsigned int base, int type)
{
	int	count;

	count = 0;
	if (n > base - 1)
		count += ft_putnbr_unsigned(n / base, base, type);
	n = n % base;
	if (n < 10)
		count += ft_putchar(n + 48);
	else if (n >= 10 && type == 0)
		count += ft_putchar(n + 87);
	else if (n >= 10 & type == 1)
		count += ft_putchar(n + 55);
	return (count);
}
