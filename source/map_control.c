/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkutun <rkutun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:17:16 by rkutun            #+#    #+#             */
/*   Updated: 2024/02/19 14:09:44 by rkutun           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../libft/libft.h"

static bool	ft_char_control(char c)
{
	if (c == 'E' || c == 'P' || c == 'C' || c == '1' || c == '0' || c == '\n')
		return (1);
	return (0);
}

static bool	ft_map_external_control(t_map *map, size_t y, size_t x)
{
	if (x == 0 || x == map->width - 1 || y == 0 || y == map->height)
	{
		if (map->map[y][x] != '1' && map->map[y][x] != '\n')
			return (0);
	}
	return (1);
}

static bool	ft_inaccessibility(t_game *game, size_t y, size_t x)
{
	if (game->t_map.map[y][x] == 'P')
	{
		game->t_map.pc++;
		if (game->t_map.pc > 1)
			return (ft_putendl_fd("Player cannot be more than 1.", 2), 0);
		game->t_chr.px = x;
		game->t_chr.py = y;
	}
	if (game->t_map.map[y][x] == 'C')
		game->t_map.cc++;
	if (game->t_map.map[y][x] == 'E')
	{
		game->t_map.ec++;
		if (game->t_map.ec > 1)
			return (ft_putendl_fd("Exit cannot be more than 1.", 2), 0);
		game->t_map.ex = x;
		game->t_map.ey = y;
	}
	return (1);
}

static t_map	map_copy(t_map map)
{
	t_map	map_cpy;
	size_t	y;

	map_cpy.map = (char **)malloc(sizeof(char *) * map.height);
	if (!map_cpy.map)
		return (map_cpy);
	y = 0;
	while (y < map.height)
	{
		map_cpy.map[y] = ft_strdup(map.map[y]);
		if (!map_cpy.map[y])
			return (map_cpy);
		y++;
	}
	map_cpy.height = map.height;
	map_cpy.width = map.width;
	map_cpy.cc = 0;
	map_cpy.ec = 0;
	map_cpy.pc = map.pc;
	map_cpy.ex = map.ex;
	map_cpy.ey = map.ey;
	return (map_cpy);
}

bool	ft_map_control(t_game *game, size_t y, size_t x)
{
	y = 0;
	while (y < game->t_map.height)
	{
		x = 0;
		while (x < game->t_map.width)
		{
			if (ft_char_control(game->t_map.map[y][x]) == 0)
				return (ft_putendl_fd("Wrong character entered on map.", 2), 0);
			if (ft_map_external_control(&game->t_map, y, x) == 0)
				return (ft_putendl_fd("The map is not walled off.", 2), 0);
			if (ft_inaccessibility(game, y, x) == 0)
				return (0);
			x++;
		}
		y++;
	}
	if (game->t_map.cc == 0 || game->t_map.ec == 0 || game->t_map.pc == 0)
		return (ft_putendl_fd("Map is missing player, coins or exit.", 2), 0);
	game->c_map = map_copy(game->t_map);
	ft_pathfinding(&game->c_map, game->t_chr.py, game->t_chr.px);
	if (game->c_map.cc != game->t_map.cc || game->c_map.ec != 1)
		return (ft_putendl_fd("Map is not solvable.", 2), 0);
	return (1);
}
