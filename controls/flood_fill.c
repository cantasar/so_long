/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:16:00 by ctasar            #+#    #+#             */
/*   Updated: 2023/08/18 15:27:39 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	top(t_data *game, int x, int y)
{
	if (game->control_map[y - 1][x] && game->control_map[y - 1][x] != '1' && game->control_map[y - 1][x] != '*')
	{
		y--;
		game->control_map[y][x] = '*';
		flood_fill(game, x, y);
		y++;
	}
}
void	bottom(t_data *game, int x, int y)
{
	if (game->control_map[y + 1][x] && game->control_map[y + 1][x] != '1' && game->control_map[y + 1][x] != '*')
	{
		y++;
		game->control_map[y][x] = '*';
		flood_fill(game, x, y);
		y--;
	}
}
void	left(t_data *game, int x, int y)
{
	if (game->control_map[y][x - 1] && game->control_map[y][x - 1] != '1' && game->control_map[y][x - 1] != '*')
	{
		x--;
		game->control_map[y][x] = '*';
		flood_fill(game, x, y);
		x++;
	}
}
void	right(t_data *game, int x, int y)
{
	if (game->control_map[y][x + 1] && game->control_map[y][x + 1] != '1' && game->control_map[y][x + 1] != '*')
	{
		x++;
		game->control_map[y][x] = '*';
		flood_fill(game, x, y);
		x--;
	}
}

void	flood_fill(t_data *game, int x, int y)
{
	top(game, x, y);
	bottom(game, x, y);
	left(game, x, y);
	right(game, x, y);
}