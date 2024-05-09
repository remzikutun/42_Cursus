/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkutun <rkutun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:55:41 by rkutun            #+#    #+#             */
/*   Updated: 2024/02/19 14:17:56 by rkutun           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../libft/libft.h"

static int	ft_game_shutdown(t_game *game, int ex_code)
{
	if (ex_code == ESC)
		ft_free2(game);
	if (ex_code == 42)
		ft_free2(game);
	return (0);
}

static void	ft_player_control(t_game *game, int y, int x)
{
	if (game->t_map.map[game->t_chr.py + y][game->t_chr.px + x] == '1')
		return ;
	if (game->t_map.cc == 0 && game->t_map.map
		[game->t_chr.py + y][game->t_chr.px + x] == 'E')
		ft_game_shutdown(game, 42);
	else if (game->t_map.map[game->t_chr.py + y][game->t_chr.px + x] == 'E')
		return ;
	if (game->t_map.map[game->t_chr.py + y][game->t_chr.px + x] == 'C')
		game->t_map.cc--;
	game->t_map.map[game->t_chr.py][game->t_chr.px] = '0';
	game->t_chr.py += y;
	game->t_chr.px += x;
	game->t_map.map[game->t_chr.py][game->t_chr.px] = 'P';
	game->t_map.sc++;
	ft_draw_win(game);
	ft_putstr_fd("Step Count ~> ", 1);
	ft_putnbr_fd(game->t_map.sc, 1);
	ft_putchar_fd('\n', 1);
}

int	ft_motion_control(int key, t_game *game)
{
	if (key == ESC)
		ft_game_shutdown(game, ESC);
	else if (key == W)
		ft_player_control(game, -1, 0);
	else if (key == A)
		ft_player_control(game, 0, -1);
	else if (key == S)
		ft_player_control(game, 1, 0);
	else if (key == D)
		ft_player_control(game, 0, 1);
	else
		return (0);
	return (1);
}
