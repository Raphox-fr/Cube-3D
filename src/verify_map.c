/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:32:50 by rafaria           #+#    #+#             */
/*   Updated: 2025/04/03 18:34:18 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/cube.h"

int verify_map(t_struct *map)
{
	// map->map_brut = read_file_into_string(map->file_path);
	// printf("////////////////////////////////////////\n");
	// printf("%s", map->map_brut);
	// printf("CEILING BRUT %s\n", map->ceiling_brut);

	if (check_newline_map(map) == -1)
		return (-1);
	map->map_only = ft_split(map->brut_map_only, '\n');
	display_map_simple(map->map_only);

	
	while (find_zero(map) != -1)
	{
		printf("y-zero=%d\n", map->y_zero);
		printf("x-zero=%d\n", map->x_zero);
		printf("--------\n");
		if (check_udlr(map) == -1)
		{
			free_split(map->map_only);
			return (-1);
		}
	}
	free_split(map->map_only);
	return (1);
	
}
// count_size_x
// count_size_y
int find_zero(t_struct *map)
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

int check_udlr(t_struct *map)
{
	int x;
	int y;
	int size_x;
	int size_y;

	x = map->x_zero;
	y = map->y_zero;

	size_y = count_size_y(x, map->map_only);
	size_x = count_size_x(y, map->map_only);
	

	
	if (x == 0 || y == 0 || y == size_y || x == size_y)
		return (-1);
	
	if (y > 0 && map->map_only[y - 1][x] == ) // UP
		return (-1);
	
	if (y > 0 && map->map_only[y + 1][x] != 1) // DOWN
		return (-1);

	if (x > 0 && map->map_only[y][x - 1] != 1) // LEFT
		return (-1);
	
	if (x > 0 && map->map_only[y][x + 1] != 1) // RIGHT
		return (-1);
	return (1);

	
}




// int display_map(t_struct *map)
// {
// 	int	y;
// 	int	x;

// 	y = map->first_line_after_infos;
// 	printf("MAP =\n");

// 	while (map->map_table[y])
// 	{
// 		x = 0;
// 		while (map->map_table[y][x])
// 		{
// 			x++;
// 		}
// 		printf("%s\n", map->map_table[y]);
// 		y++;
// 	}
// 	return (-1);
// }

int display_map_simple(char **map)
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


	