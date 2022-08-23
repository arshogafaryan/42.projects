/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argafary <argafary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:42:51 by argafary          #+#    #+#             */
/*   Updated: 2022/03/10 19:03:41 by argafary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	n;

	if (!b)
		return (NULL);
	n = 0;
	while (n < len)
	{
		*(unsigned char *)(b + n) = (unsigned char)c;
		n++;
	}
	return (b);
}
