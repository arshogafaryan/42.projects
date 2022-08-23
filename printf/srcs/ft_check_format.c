/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argafary <argafary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 19:05:04 by argafary          #+#    #+#             */
/*   Updated: 2022/03/23 20:03:11 by argafary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_format(const char *format, va_list *args)
{
	int	done;

	done = 0;
	if (*format == 's')
		done += ft_putstr(va_arg(*args, char *));
	else if (*format == 'd')
		done += ft_putnbr(va_arg(*args, int), 10, 0);
	else if (*format == 'u')
		done += ft_putnbr_unsigned(va_arg(*args, unsigned int), 10, 0);
	else if (*format == 'i')
		done += ft_putnbr(va_arg(*args, int), 10, 0);
	else if (*format == 'c')
		done += ft_putchar(va_arg(*args, int));
	else if (*format == 'p')
		done += ft_putptr(va_arg(*args, void *));
	else if (*format == 'x')
			done += ft_putnbr_unsigned(va_arg(*args, unsigned int), 16, 0);
	else if (*format == 'X')
		done += ft_putnbr_unsigned(va_arg(*args, unsigned int), 16, 1);
	else if (*format == '%')
		done += ft_putchar('%');
	return (done);
}
