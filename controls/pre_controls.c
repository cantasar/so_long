/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_controls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:13:02 by ctasar            #+#    #+#             */
/*   Updated: 2023/08/22 11:07:23 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ber_control(char *dest)
{
	int	i;
	int	fd;

	i = 0;
	while (dest[i])
		i++;
	i--;
	if (dest[i] != 'r' || dest[i - 1] != 'e' || \
		dest[i - 2] != 'b' || dest[i - 3] != '.')
	{
		ft_printf("Map is not a '.ber' file\n");
		exit(1);
	}
	fd = open(dest, O_RDONLY);
	if (fd <= 0)
	{
		close(fd);
		ft_printf("map destination is not correct or no file\n");
		exit(1);
	}
	close(fd);
}
