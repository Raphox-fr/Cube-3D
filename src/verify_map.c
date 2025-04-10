/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:32:50 by rafaria           #+#    #+#             */
/*   Updated: 2025/04/10 12:18:48 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int	verify_map(t_struct *map)
{
	if (check_newline_map(map) == -1)
		return (-1);
	map->map_only = ft_split(map->brut_map_only, '\n');
	if (transform_player_to_zero(map) == -1)
		return (-1);
	while (find_zero(map) != -1)
	{
		if (check_udlr(map) == -1)
		{
			free_split(map->map_only);
			return (-1);
		}
	}
	free_split(map->map_only);
	return (1);
}

int	find_zero(t_struct *map)
{
	int	y;
	int	x;

	y = 0;
	while (map->map_only[y])
	{
		x = 0;
		while (map->map_only[y][x])
		{
			if (map->map_only[y][x] == '0')
			{
				map->x_zero = x;
				map->y_zero = y;
				map->map_only[map->y_zero][map->x_zero] = 1;
				return (1);
			}
			x++;
		}
		y++;
	}
	return (-1);
}

int	check_udlr(t_struct *map)
{
	int	x;
	int	y;
	int	size_x;
	int	size_y;

	x = map->x_zero;
	y = map->y_zero;
	size_x = count_size_x(y, map->map_only);
	size_y = count_size_y(x, map->map_only) - 1;
	if (x == 0 || y == 0 || y == size_y || x == size_x)
		return (-1);
	if (ft_strlen(map->map_only[y - 1]) >= ft_strlen(map->map_only[y])
		&& map->map_only[y - 1][x] == '\0' || x >= ft_strlen(map->map_only[y
			- 1]))
		return (-1);
	if (ft_strlen(map->map_only[y + 1]) >= ft_strlen(map->map_only[y])
		&& map->map_only[y + 1][x] == '\0' || x >= ft_strlen(map->map_only[y
			+ 1]))
		return (-1);
	if (map->map_only[y][x - 1] == '\0')
		return (-1);
	if (map->map_only[y][x + 1] == '\0')
		return (-1);
	return (1);
}

int	transform_player_to_zero(t_struct *map)
{
	int	y;
	int	x;
	int	found;

	y = 0;
	x = 0;
	while (map->map_only[y])
	{
		x = 0;
		while (map->map_only[y][x])
		{
			if ((map->map_only[y][x] == 'N') || (map->map_only[y][x] == 'S')
				|| (map->map_only[y][x] == 'E') || (map->map_only[y][x] == 'W'))
			{
				map->map_only[y][x] = '0';
				return (1);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	display_map_simple(char **map)
{
	int	y;
	int	x;

	y = 0;
	printf("MAP = \n");
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			x++;
		}
		printf("%s\n", map[y]);
		y++;
	}
	return (-1);
}

// display_map_simple(map->map_only);