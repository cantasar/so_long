/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_controls_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:37:14 by ctasar            #+#    #+#             */
/*   Updated: 2023/08/18 16:57:46 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void check_filled_map(t_data *game)
{
	int i;
	int j;

	i = 0;
	while (game->control_map[i])
	{
		j = 0;
		while (game->control_map[i][j])
		{
			if (game->control_map[i][j] == 'C' || game->control_map[i][j] == 'E')
			{
				if (game->control_map[i][j] == 'C')
					write(1, "Collectible blocked\n", 21);
				if (game->control_map[i][j] == 'E')
					write(1, "Exit blocked\n", 14);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void is_rectangular(t_data *game)
{
	wall_control(game);
	int i;

	i = 1;
	game->width_map = ft_strlen(game->map[0]);
	while (game->map[i])
	{
		if ((int)ft_strlen(game->map[i]) != game->width_map)
		{
			write(1, "Map is not rectangular\n", 24);
			exit(1);
		}
		i++;
	}
}

void wall_control(t_data *game)
{
	int	i;

	i = 0;
	game->width_map = ft_strlen(game->map[0]);
	while (game->map[0][i])
	{
		if (game->map[0][i] != '1' || game->map[game->height_map - 1][i] != '1')
		{
			write(1, "Map wall error\n", 16);
			exit(1);
		}
		i++;
	}
	i = 0;
	while (game->map[i])
	{
		if (game->map[i][0] != '1' || game->map[i][game->width_map - 1] != '1')
		{
			write(1, "Map wall error\n", 16);
			exit(1);
		}
		i++;
	}
}
