/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 10:02:07 by ctasar            #+#    #+#             */
/*   Updated: 2023/07/15 13:46:31 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	type_check(va_list list, char a)
{
	int	len;

	len = 0;
	if (a == 'c')
		len += ft_putchar(va_arg(list, int));
	else if (a == 's')
		len += ft_putstr(va_arg(list, char *));
	else if (a == 'p')
		len += ptohex(va_arg(list, void *));
	else if (a == 'd')
		len += ft_putnbr(va_arg(list, int));
	else if (a == 'i')
		len += ft_putnbr(va_arg(list, int));
	else if (a == 'u')
		len += ft_putunbr(va_arg(list, unsigned int));
	else if (a == 'x')
		len += converter(va_arg(list, unsigned int), "0123456789abcdef", 16);
	else if (a == 'X')
		len += converter(va_arg(list, unsigned int), "0123456789ABCDEF", 16);
	else if (a == '%')
		len += ft_putchar('%');
	return (len);
}
