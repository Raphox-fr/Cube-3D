/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 20:14:13 by rafaria           #+#    #+#             */
/*   Updated: 2025/04/16 12:36:31 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int	check_extension_xpm(char *file_path)
{
	int	i;

	i = 0;
	if (file_path == NULL)
		return (-1);
	while (file_path[i])
	{
		if (i >= 1 && file_path[i] == '.' && file_path[i + 1] == 'x'
			&& file_path[i + 2] == 'p' && file_path[i + 3] == 'm' && file_path[i
				+ 4] == '\0')
		{
			return (1);
		}
		i++;
	}
	return (-1);
}

int	rgb_to_hex(int r, int g, int b)
{
	int	hex_color;

	hex_color = (r << 16) | (g << 8) | b;
	return (hex_color);
}

int	check_end_textures(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != ' ')
		i++;
	while (str[i] != '\0' && (str[i] == ' '))
		i++;
	if (str[i] != '\0')
	{
		return (-1);
	}
	return (1);
}

void	find_player_extension(t_struct *map, int x, int y)
{
	map->x_player = x;
	map->y_player = y - 6;
	map->player_directions = map->map_table[y][x];
	map->map_table[y][x] = '0';
}
