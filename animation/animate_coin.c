/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_coin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 13:47:21 by ctasar            #+#    #+#             */
/*   Updated: 2023/08/22 00:47:07 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	coin_loop(t_data *game)
{
	int	w;

	mlx_clear_window(game->mlx, game->mlx_win);
	w = 64;
	if (game->animate_count == 0)
		game->coin_cur = \
			mlx_xpm_file_to_image(game->mlx, "./textures/bb8.xpm", &w, &w);
	else if (game->animate_count == 10)
		game->coin_cur = \
			mlx_xpm_file_to_image(game->mlx, "./textures/soll.xpm", &w, &w);
	else if (game->animate_count == 20)
		game->coin_cur = \
			mlx_xpm_file_to_image(game->mlx, "./textures/bb8.xpm", &w, &w);
	else if (game->animate_count == 30)
		game->coin_cur = \
			mlx_xpm_file_to_image(game->mlx, "./textures/sagg.xpm", &w, &w);
	else if (game->animate_count >= 60)
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
	return (1);
}
