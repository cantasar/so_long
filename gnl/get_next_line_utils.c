/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:56:56 by ctasar            #+#    #+#             */
/*   Updated: 2023/08/15 14:46:49 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	check_nl(char *all)
{
	int	i;

	i = 0;
	if (!all)
		return (0);
	while (all[i])
	{
		if (all[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*gnl_strjoin(char *all, char *buff)
{
	char	*new_str;
	int		i;
	int		j;

	if (!all)
	{
		all = (char *)malloc(sizeof(char) * 1);
		*all = '\0';
	}
	new_str = malloc(sizeof(char) * (gnl_strlen(all) + gnl_strlen(buff) + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (all[i])
	{
		new_str[i] = all[i];
		i++;
	}
	j = 0;
	while (buff[j])
		new_str[i++] = buff[j++];
	new_str[i] = '\0';
	free(all);
	return (new_str);
}
