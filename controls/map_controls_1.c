/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_controls_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:37:14 by ctasar            #+#    #+#             */
/*   Updated: 2023/08/25 11:57:31 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_filled_map(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->control_map[i])
	{
		j = 0;
		while (game->control_map[i][j])
		{
			if (game->control_map[i][j++] == 'C' )
			{
				ft_printf("Collectible blocked\n");
				exit(1);
			}
		}
		i++;
	}
	if (!(game->control_map[game->e_y - 1][game->e_x] == '*' || \
		game->control_map[game->e_y + 1][game->e_x] == '*' || \
		game->control_map[game->e_y][game->e_x - 1] == '*' || \
		game->control_map[game->e_y][game->e_x + 1] == '*'))
	{
		ft_printf("Exit blocked\n");
		exit(1);
	}
}

void	is_rectangular(t_data *game)
{
	int	i;

	i = 1;
	game->width_map = ft_strlen(game->map[0]);
	while (game->map[i])
	{
		if ((int)ft_strlen(game->map[i]) != game->width_map)
		{
			ft_printf("Map is not rectangular\n");
			exit(1);
		}
		i++;
	}
	wall_control(game);
}

void	wall_control(t_data *game)
{
	int	i;

	i = 0;
	game->width_map = ft_strlen(game->map[0]);
	while (game->map[0][i])
	{
		if (game->map[0][i] != '1' || game->map[game->height_map - 1][i] != '1')
		{
			ft_printf("Map wall error\n");
			exit(1);
		}
		i++;
	}
	i = 0;
	while (game->map[i])
	{
		if (game->map[i][0] != '1' || game->map[i][game->width_map - 1] != '1')
		{
			ft_printf("Map wall error\n");
			exit(1);
		}
		i++;
	}
}
