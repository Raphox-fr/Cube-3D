/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 20:08:03 by rafaria           #+#    #+#             */
/*   Updated: 2025/04/10 15:14:24 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int	check_access_txture(char *path_txture)
{
	int	fd;

	fd = open(path_txture, O_RDONLY);
	if (fd < 0)
	{
		return (-1);
	}
	close(fd);
	return (1);
}

int	find_every_txture_in_map(t_struct *map, char **map_table)
{
	int	count;

	count = 0;
	if ((find_txture(map, map_table, "NO") == 1)
		&& check_extension_xpm(map->no_txture) == 1)
		count++;
	if (find_txture(map, map_table, "SO") == 1
		&& check_extension_xpm(map->so_txture) == 1)
		count++;
	if (find_txture(map, map_table, "WE") == 1
		&& check_extension_xpm(map->we_txture) == 1)
		count++;
	if (find_txture(map, map_table, "EA") == 1
		&& check_extension_xpm(map->ea_txture) == 1)
		count++;
	if (map->no_txture == NULL || map->so_txture == NULL
		|| map->we_txture == NULL || map->ea_txture == NULL)
	{
		display_error("Invalid textures or missing textures\n");
		return (-1);
	}
	if (count != 4)
	{
		display_error("Invalid textures or missing textures\n");
		return (-1);
	}
	return (1);
}

int	check_access_every_txture(t_struct *map)
{
	if (check_access_txture(map->no_txture) == -1)
		return (-1);
	if (check_access_txture(map->so_txture) == -1)
		return (-1);
	if (check_access_txture(map->we_txture) == -1)
		return (-1);
	if (check_access_txture(map->ea_txture) == -1)
		return (-1);
	return (1);
}

int	find_txture(t_struct *map, char **map_table, char *directions)
{
	int	i;

	i = 0;
	while (map_table[i])
	{
		if (ft_strnstr(map_table[i], directions,
				ft_strlen_size_t(map_table[i])) != 0)
		{
			if (i >= map->first_line_after_infos)
				map->first_line_after_infos = i;
			if (check_found_txture(map, map_table[i], directions) == 1)
				return (1);
		}
		i++;
	}
	return (-1);
}

int	check_found_txture(t_struct *map, char *map_string, char *directions)
{
	while ((*map_string == ' ' || *map_string == '	') && *map_string != '\0')
		map_string++;
	if (ft_strlen_cub(map_string) <= 2)
		return (-1);
	if (*map_string == directions[0] && *(map_string + 1) == directions[1])
	{
		map_string = map_string + 3;
		while ((*map_string == ' ' || *map_string == '	')
			&& *map_string != '\0')
			map_string++;
		if (check_end_textures(map_string) == -1)
			return (-1);
		if (directions[0] == 'N' && directions[1] == 'O')
			return (map->no_txture = ft_strdup_pimp(map_string), 1);
		if (directions[0] == 'S' && directions[1] == 'O')
			return (map->so_txture = ft_strdup_pimp(map_string), 1);
		if (directions[0] == 'W' && directions[1] == 'E')
			return (map->we_txture = ft_strdup_pimp(map_string), 1);
		if (directions[0] == 'E' && directions[1] == 'A')
			return (map->ea_txture = ft_strdup_pimp(map_string), 1);
	}
	return (-1);
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
		return (-1);
	return (1);
}

// char **get_type_texture_from_structure(t_struct *map, char *directions)
// {
// 	if (directions[0] == 'N' && directions[0] == 'O')
// 		return (&map->no_txture);
// 	if (directions[0] == 'S' && directions[0] == 'O')
// 		return (&map->so_txture);
// 	if (directions[0] == 'W' && directions[0] == 'E')
// 		return (&map->we_txture);
// 	if (directions[0] == 'E' && directions[0] == 'A')
// 		return (&map->ea_txture);
// 	return ("0");
// }

// int check_last_part_txture_found(char *path_txture)
// {
//     int i;
//     i = 0;

// 	int start;
// 	start = 0;

//     while ((path_txture[i] != ' ' && path_txture[i] != '	')
// && path_txture[i] != '\0')
// 	{
// 		i++;
// 	}
// 	start = i;
// 	while (path_txture[start] != '\0')
//     {
// 		if (path_txture[start] != ' ' || path_txture[start] != '	')
// 			return (-1);
//         start++;
//     }
// 	return (1);
// }
// }