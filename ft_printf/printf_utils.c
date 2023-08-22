/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 11:07:38 by ctasar            #+#    #+#             */
/*   Updated: 2023/07/15 15:13:50 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ptohex(void *p)
{
	int	count;

	count = 0;
	count += ft_putstr("0x");
	count += converter((unsigned long)p, "0123456789abcdef", 16);
	return (count);
}

int	converter(unsigned long p, char *s, unsigned int base)
{
	int	count;

	count = 0;
	if (p >= base)
		count += converter(p / base, s, base);
	ft_putchar(s[p % base]);
	return (count + 1);
}
