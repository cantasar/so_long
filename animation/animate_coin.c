/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_coin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 13:47:21 by ctasar            #+#    #+#             */
/*   Updated: 2023/09/02 14:42:26 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	dead_close(t_data *game)
{
	ft_printf("You Died by Jedi!!\n");
	close_win(game->mlx);
}

void	move_enemy_l(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'J' && (game->map[i][j - 1] == '0' \
			|| game->map[i][j - 1] == 'P'))
			{
				if (game->animate_count == 40)
				{
					if (game->map[i][j - 1] == 'P')
						dead_close(game);
					game->map[i][j - 1] = 'J';
					game->map[i][j] = '0';
					break ;
				}
			}
			j++;
		}
		i++;
	}
}

void	move_enemy_r(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'J' && (game->map[i][j + 1] == '0' \
			|| game->map[i][j + 1] == 'P'))
			{
				if (game->animate_count == 1)
				{
					if (game->map[i][j + 1] == 'P')
						dead_close(game);
					game->map[i][j + 1] = 'J';
					game->map[i][j] = '0';
					break ;
				}
			}
			j++;
		}
		i++;
	}
}

void	coin_loop(t_data *game)
{
	int	w;

	mlx_clear_window(game->mlx, game->mlx_win);
	w = 64;
	if (game->animate_count == 0)
		game->coin_cur = \
			mlx_xpm_file_to_image(game->mlx, "./textures/bb8.xpm", &w, &w);
	else if (game->animate_count == 20)
		game->coin_cur = \
			mlx_xpm_file_to_image(game->mlx, "./textures/soll.xpm", &w, &w);
	else if (game->animate_count == 40)
		game->coin_cur = \
			mlx_xpm_file_to_image(game->mlx, "./textures/bb8.xpm", &w, &w);
	else if (game->animate_count == 60)
		game->coin_cur = \
			mlx_xpm_file_to_image(game->mlx, "./textures/sagg.xpm", &w, &w);
	else if (game->animate_count >= 80)
	{
		game->coin_cur = \
			mlx_xpm_file_to_image(game->mlx, "./textures/bb8.xpm", &w, &w);
		game->animate_count = 0;
	}
	put_textures(game);
	game->animate_count += 1;
}

int	loop(t_data *game)
{
	coin_loop(game);
	move_enemy_l(game);
	move_enemy_r(game);
	put_textures(game);
	return (1);
}
