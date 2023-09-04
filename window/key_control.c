/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:09:17 by ctasar            #+#    #+#             */
/*   Updated: 2023/09/02 14:48:44 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	player_move(t_data *game, int x, int y);

int	hook_keys(int keycode, t_data *game)
{
	if (keycode == 2)
		player_move(game, game->p_x + 1, game->p_y);
	if (keycode == 0)
		player_move(game, game->p_x - 1, game->p_y);
	if (keycode == 1)
		player_move(game, game->p_x, game->p_y + 1);
	if (keycode == 13)
		player_move(game, game->p_x, game->p_y - 1);
	if (keycode == 53)
		close_win(game);
	return (1);
}

void	move(t_data *game, int y, int x)
{
	game->map[game->p_y][game->p_x] = '0';
	game->map[game->e_y][game->e_x] = 'E';
	game->map[y][x] = 'P';
	game->p_x = x;
	game->p_y = y;
	game->score++;
	ft_printf("step: %d\n", game->score);
}

void	player_move(t_data *game, int x, int y)
{
	if (game->map[y][x] != '1' && game->map[y][x] != 'E' && \
		game->map[y][x] != 'C' && game->map[y][x] != 'J')
		move(game, y, x);
	if (game->map[y][x] == 'C')
	{
		game->count_col--;
		move(game, y, x);
	}
	if (game->map[y][x] == 'J')
	{
		game->score++;
		ft_printf("step: %d\n", game->score);
		ft_printf("You Died\n");
		close_win(game);
	}
	if (game->count_col == 0)
	{
		if (game->map[y][x] == 'E')
		{
			game->score++;
			ft_printf("step: %d\n", game->score);
			ft_printf("You Win\n");
			close_win(game);
		}
	}
}
