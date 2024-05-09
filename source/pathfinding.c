/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkutun <rkutun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:34:47 by rkutun            #+#    #+#             */
/*   Updated: 2024/02/19 14:16:20 by rkutun           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_pathfinding(t_map *map, int y, int x)
{
	if (map->map[y][x] == '#' || map->map[y][x] == '1')
		return ;
	if (map->map[y][x] == 'C')
		map->cc++;
	if (map->map[y][x] == 'E')
	{
		map->ec = 1;
		return ;
	}
	map->map[y][x] = '#';
	ft_pathfinding(map, y, x + 1);
	ft_pathfinding(map, y, x - 1);
	ft_pathfinding(map, y + 1, x);
	ft_pathfinding(map, y - 1, x);
}
