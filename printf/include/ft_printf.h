/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argafary <argafary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:31:08 by argafary          #+#    #+#             */
/*   Updated: 2022/03/24 16:42:05 by argafary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>

int	ft_printf(const char *format, ...);
int	ft_check_format(const char *format, va_list *args);

int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_putnbr(int n, unsigned int base, int type);
int	ft_putnbr_unsigned(unsigned long long n, unsigned int base, int type);
int	ft_putptr(void *ptr);
#endif
