/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:13:10 by ctasar            #+#    #+#             */
/*   Updated: 2023/08/25 16:56:26 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	*game;

	if (argc != 2)
	{
		ft_printf("Wrong usage\n./so_long <map path>\n");
		return (0);
	}
	ber_control(argv[1]);
	game = (t_data *)calloc(1, sizeof(t_data));
	read_map(game, argv[1]);
	loc_p(game);
	flood_fill(game, 1, 1);
	check_filled_map(game);
	game->mlx = mlx_init();
	get_xpm(game);
	game->mlx_win = mlx_new_window(game->mlx, game->width_map * 64, \
		game->height_map * 64 + 20, "sooooo_long");
	put_text(game);
	mlx_hook(game->mlx_win, 2, 1L << 1, hook_keys, game);
	mlx_hook(game->mlx_win, 17, 0, close_win, game);
	mlx_loop_hook(game->mlx, loop, game);
	mlx_loop(game->mlx);
	return (0);
}
