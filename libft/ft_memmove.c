/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 12:35:26 by ctasar            #+#    #+#             */
/*   Updated: 2023/07/09 19:54:33 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tmp_dest;
	unsigned char	*tmp_src;

	tmp_dest = (unsigned char *)dst;
	tmp_src = (unsigned char *)src;
	if (!len || dst == src)
		return (dst);
	if (dst < src)
		while (len--)
			*tmp_dest++ = *tmp_src++;
	else
		while (len--)
			tmp_dest[len] = tmp_src[len];
	return (dst);
}
