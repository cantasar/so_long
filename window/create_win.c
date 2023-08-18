/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:09:17 by ctasar            #+#    #+#             */
/*   Updated: 2023/08/18 23:41:37 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int		hook_keys(int keycode, t_data *game);
void	player_move(t_data *game, int x, int y);

//bunu taşı
void	get_xpm(t_data *game)
{
	game->bg = mlx_xpm_file_to_image(game->mlx, "textures/bg.xpm", 0, 0);
	game->chr = mlx_xpm_file_to_image(game->mlx, "textures/front_char.xpm", 0, 0);
	game->block = mlx_xpm_file_to_image(game->mlx, "textures/block.xpm", 0, 0);
	game->coin = mlx_xpm_file_to_image(game->mlx, "textures/coin.xpm", 0, 0);
	game->exit = mlx_xpm_file_to_image(game->mlx, "textures/endgate.xpm", 0, 0);
}

void	create_win(t_data *game)
{
	game->mlx = mlx_init();
	game->mlx = mlx_new_window(game->mlx, game->width_map * 64, game->height_map * 64, "soooo_long");
	mlx_key_hook(game->mlx_win, hook_keys, game);
	mlx_loop(game->mlx);
}

int hook_keys(int keycode, t_data *game)
{
	printf("%d", keycode);
	(void)game;
	//mlx_clear_window(game->mlx, game->mlx_win);
	// if (keycode == 2)
	// 	printf("basss");
	// 	player_move(game, game->p_x + 64, game->p_y);
	// if (keycode == 0)
	// 	player_move(game, game->p_x - 64, game->p_y);
	// if (keycode == 1)
	// 	player_move(game, game->p_x, game->p_y + 64);
	// if (keycode == 13)
	// 	player_move(game, game->p_x, game->p_y - 64);
	// if (keycode == 53)
	// 	close_win(game);
	//replace_game();
	return (1);
}

void	player_move(t_data *game, int x, int y)
{
	if (game->count_col == 0 && game->map[y / 64][x / 64] == 'E')
	{
		game->score++;
		write(1, "cong!!\n", 7);
		//close_win();
	}
	if (game->map[y / 64][x / 64] != '1' && game->map[y / 64][x / 64] != 'E')
	{
		game->score++;
		if (game->map[y / 64][x / 64] == 'C')
		{
			game->map[game->p_y / 64][game->p_x / 64] = '0';
			game->map[game->e_y / 64][game->e_x / 64] = 'E';
			game->map[y / 64][x / 64] = 'P';
		}
	}
	int i = 0;
	while (game->map[i])
	{
		printf("%s\n", game->map[i++]);
	}
	
}
