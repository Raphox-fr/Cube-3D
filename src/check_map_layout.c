/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_layout.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:28:52 by rafaria           #+#    #+#             */
/*   Updated: 2025/04/16 12:35:38 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

// line map valid = '1', '0', 'N', 'S', 'E', 'W', ' '

int	check_map_layout(t_struct *map)
{
	if (map->first_line_after_infos != 6)
	{
		display_error("Undefined elements in the map informations\n");
		return (-1);
	}
	if (check_invalid_char_after_first_line_after_infos(map) == -1)
	{
		display_error("Invalid character in the map description\n");
		return (-1);
	}
	if (find_player(map) == -1)
	{
		display_error("Player not found in map\n");
		return (-1);
	}
	if (verify_map(map) == -1)
	{
		display_error("Invalid map description\n");
		return (-1);
	}
	return (1);
}

int	check_invalid_char_after_first_line_after_infos(t_struct *map)
{
	int	i;
	int	j;

	j = 0;
	i = map->first_line_after_infos;
	while (map->map_table[i])
	{
		j = 0;
		while (map->map_table[i][j] != '\0')
		{
			if (map->map_table[i][j] != '1' && map->map_table[i][j] != '0'
				&& map->map_table[i][j] != 'N' && map->map_table[i][j] != 'S'
				&& map->map_table[i][j] != 'E' && map->map_table[i][j] != 'W'
				&& map->map_table[i][j] != ' ' && map->map_table[i][j] != '\0')
			{
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	find_first_line_map(t_struct *map)
{
	int	i;
	int	j;

	j = 0;
	i = map->first_line_after_infos;
	while (map->map_table[i])
	{
		j = 0;
		while (map->map_table[i][j] != '\0')
		{
			if (map->map_table[i][j] == '1' || map->map_table[i][j] == '0'
				|| map->map_table[i][j] == 'N' || map->map_table[i][j] == 'S'
				|| map->map_table[i][j] == 'E' || map->map_table[i][j] == 'W'
				|| map->map_table[i][j] == ' ' || map->map_table[i][j] == '\0')
			{
				map->first_line_map = i;
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	find_player(t_struct *map)
{
	int	y;
	int	x;
	int	found;

	found = 0;
	y = map->first_line_after_infos;
	while (map->map_table[y])
	{
		x = 0;
		while (map->map_table[y][x])
		{
			if ((map->map_table[y][x] == 'N') || (map->map_table[y][x] == 'S')
				|| (map->map_table[y][x] == 'E')
				|| (map->map_table[y][x] == 'W'))
			{
				found++;
				find_player_extension(map, x, y);
			}
			x++;
		}
		y++;
	}
	if (found != 1)
		return (-1);
	return (1);
}
