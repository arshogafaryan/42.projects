/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argafary <argafary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 18:01:08 by argafary          #+#    #+#             */
/*   Updated: 2022/03/23 20:13:33 by argafary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	int	count;

	write(1, "0x", 2);
	count = 2;
	count += ft_putnbr_unsigned((unsigned long long)ptr, 16, 0);
	return (count);
}
