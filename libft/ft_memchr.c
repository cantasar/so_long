/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:51:20 by ctasar            #+#    #+#             */
/*   Updated: 2023/07/04 12:01:13 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char	*str;
	unsigned char		chr;

	str = (unsigned const char *)s;
	chr = (unsigned char)c;
	while (n--)
	{
		if (*(str) == chr)
		{
			return ((void *)str);
		}
		str++;
	}
	return (NULL);
}
