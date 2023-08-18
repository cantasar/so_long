/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_controls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:13:02 by ctasar            #+#    #+#             */
/*   Updated: 2023/08/18 11:13:03 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void ber_control(char *dest)
{
	int i;
	int fd;

	i = 0;
	while (dest[i])
		i++;
	i--;
	if (dest[i] != 'r' || dest[i - 1] != 'e' || dest[i - 2] != 'b' || dest[i - 3] != '.')
	{
		write(1, "Map is not a '.ber' file\n", 25);
		exit(1);
	}
	fd = open(dest, O_RDONLY);
	if (fd <= 0)
	{
		close(fd);
		write(1, "map destination is not correct or no file\n", 42);
		exit(1);
	}
	close(fd);
}
