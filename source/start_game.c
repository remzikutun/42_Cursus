/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkutun <rkutun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:58:20 by rkutun            #+#    #+#             */
/*   Updated: 2024/02/19 12:54:19 by rkutun           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../mlx/mlx.h"
#include "../libft/libft.h"

static bool	ft_init_image(t_game *game, int y, int x)
{
	game->p_image = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/player.xpm", &y, &x);
	if (!game->p_image)
		return (ft_putendl_fd("Player.xpm not found\n", 2), 0);
	game->c_image = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/coin.xpm", &y, &x);
	if (!game->c_image)
		return (ft_putendl_fd("Coin.xpm not found\n", 2), 0);
	game->ex_image = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/exit.xpm", &y, &x);
	if (!game->ex_image)
		return (ft_putendl_fd("Exit.xpm not found\n", 2), 0);
	game->f_image = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/floor.xpm", &y, &x);
	if (!game->f_image)
		return (ft_putendl_fd("Floor.xpm not found\n", 2), 0);
	game->w_image = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/wall.xpm", &y, &x);
	if (!game->w_image)
		return (ft_putendl_fd("Wall.xpm not found\n", 2), 0);
	return (1);
}

static void	ft_put_image(t_game *game, size_t y, size_t x)
{
	if (game->t_map.map[y][x] == '1')
	{
		if (mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->w_image, x * 64, y * 64) == -1)
			ft_free2(game);
	}
	else
	{
		if (mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->f_image, x * 64, y * 64) == -1)
			ft_free2(game);
	}
	if ((game->t_map.map[y][x] == 'E') && (mlx_put_image_to_window
		(game->mlx_ptr, game->win_ptr, game->ex_image, x * 64, y * 64) == -1))
		ft_free2(game);
	else if ((game->t_map.map[y][x] == 'P') && (mlx_put_image_to_window
		(game->mlx_ptr, game->win_ptr, game->p_image, x * 64, y * 64) == -1))
		ft_free2(game);
	else if ((game->t_map.map[y][x] == 'C') && (mlx_put_image_to_window
		(game->mlx_ptr, game->win_ptr, game->c_image, x * 64, y * 64) == -1))
		ft_free2(game);
}

void	ft_draw_win(t_game *game)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < game->t_map.height)
	{
		x = 0;
		while (x < game->t_map.width)
		{
			ft_put_image(game, y, x);
			x++;
		}
		y++;
	}
}

void	ft_start_game(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		ft_free2(game);
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->t_map.width * 64,
			game->t_map.height * 64, "Tembel Reis");
	if (!game->win_ptr)
		ft_free2(game);
	if (ft_init_image(game, 0, 0) == 0)
	{
		ft_free2(game);
		return ;
	}
	ft_draw_win(game);
	mlx_hook(game->win_ptr, 2, 0, ft_motion_control, game);
	mlx_hook(game->win_ptr, 17, 0, ft_free2, game);
	mlx_loop(game->mlx_ptr);
}
