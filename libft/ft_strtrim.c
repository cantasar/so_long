/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:36:36 by ctasar            #+#    #+#             */
/*   Updated: 2023/07/07 10:00:50 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_s1(char c, char const *set)
{
	size_t	index;

	index = 0;
	while (set[index])
	{
		if (set[index] == c)
			return (1);
		index++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	while (check_s1(*s1, set) && *s1 != '\0')
		s1++;
	end = ft_strlen(s1);
	while (check_s1(s1[end - 1], set) && end != 0)
		end--;
	str = (char *)malloc(sizeof(char) * (end + 1));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, end + 1);
	return (str);
}
