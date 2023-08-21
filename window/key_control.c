/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:09:17 by ctasar            #+#    #+#             */
/*   Updated: 2023/08/20 23:13:39 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	player_move(t_data *game, int x, int y);

int hook_keys(int keycode, t_data *game)
{
	mlx_clear_window(game->mlx, game->mlx_win);
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
	put_textures(game);
	return (1);
}

void	player_move(t_data *game, int x, int y)
{
	if (game->map[y][x] != '1' && game->map[y][x] != 'E' && game->map[y][x] != 'C' && game->map[y][x] != 'J')
	{
		game->map[game->p_y][game->p_x] = '0';
		game->map[game->e_y][game->e_x] = 'E';
		game->map[y][x] = 'P';
		game->p_x = x;
		game->p_y = y;
		game->score++;
		printf("score: %d\n", game->score);
		
	}
	if (game->map[y][x] == 'C')
	{
		game->count_col--;
		game->map[game->p_y][game->p_x] = '0';
		game->map[game->e_y][game->e_x] = 'E';
		game->map[y][x] = 'P';
		game->p_x = x;
		game->p_y = y;
		game->score++;

		printf("score: %d\n", game->score);
	}
	if (game->map[y][x] == 'J')
	{
		printf("You Died\n");
		game->score++;
		printf("score: %d\n", game->score);
		close_win(game);
	}
	if (game->count_col == 0)
	{
		if (game->map[y][x] == 'E')
		{
			game->score++;
			printf("You Win\n");
			printf("score: %d\n", game->score);
			close_win(game);
		}
	}
}
