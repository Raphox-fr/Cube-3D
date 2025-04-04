/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:32:50 by rafaria           #+#    #+#             */
/*   Updated: 2025/04/01 18:39:37 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/cube.h"

int verify_map(t_struct *map)
{
	replace_space_with_wall(map);
	display_map(map);

	
	
	// while (find_zero(map) != -1)
	// {
	// 	if (check_udlr(map) == -1)
	// 		return (-1);
	// }
	return (1);
	
}
// count_size_x
// count_size_y

int check_udlr(t_struct *map)
{
	int x;
	int y;
	int size_x;
	int size_y;
	
	x = map->x_zero;
	y = map->y_zero;
	size_x = 0;
	size_x = 0; 
	
	if (x == 0 || y == 0 ||
		y == count_size_y(x, map->map_table) ||
		x == count_size_x(y, map->map_table))
		return (-1);
	
	if (map->map_table[y - 1][x] != 1) // UP
		return (-1);
	
	if (map->map_table[y + 1][x] != 1) // DOWN
		return (-1);

	if (map->map_table[y][x - 1] != 1) // LEFT
		return (-1);
	
	if (map->map_table[y][x + 1] != 1) // RIGHT
		return (-1);
	return (1);

	
}

void replace_space_with_wall(t_struct *map)
{
	int	y;
	int	x;

	find_first_line_map(map);
	y = map->first_line_map;
	while (map->map_table[y])
	{
		x = 0;
		while (map->map_table[y][x])
		{
			if (map->map_table[y][x] == ' ')
			{
				map->map_table[y][x] = '1';
			}
			x++;
		}
		y++;
	}
}




int find_zero(t_struct *map)
{
	int	y;
	int	x;

	y = map->first_line_after_infos;
	while (map->map_table[y])
	{
		x = 0;
		while (map->map_table[y][x])
		{
			if (map->map_table[y][x] == '0')
			{
				map->x_zero = x;
				map->y_zero = y - 7;
				map->map_table[map->y_zero][map->x_zero] = 1;
				return (1);
			}
			x++;
		}
		y++;
	}
	return (-1);
}

int display_map(t_struct *map)
{
	int	y;
	int	x;

	y = map->first_line_after_infos;
	printf("MAP =\n");

	while (map->map_table[y])
	{
		x = 0;
		while (map->map_table[y][x])
		{
			x++;
		}
		printf("%s\n", map->map_table[y]);
		y++;
	}
	return (-1);
}


	