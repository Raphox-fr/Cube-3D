/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:05:07 by rafaria           #+#    #+#             */
/*   Updated: 2025/04/16 12:14:42 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int	check_map(t_struct *map, char *file_path)
{
	map->file_path = file_path;
	map->map_brut = read_file_into_string(file_path);
	if (map->map_brut == NULL)
		return (display_error("Error reading file\n"), -1);
	map->map_table = ft_split(map->map_brut, '\n');
	if (map->map_table == NULL)
		return (display_error("Memory allocation failed\n"), -1);
	if (find_every_txture_in_map(map, map->map_table) == -1)
		return (free_struct_map(map), -1);
	if (check_floor_ceiling_in_map(map, map->map_table) == -1)
		return (free_struct_map(map), -1);
	map->first_line_after_infos = map->first_line_after_infos + 1;
	if (check_map_layout(map) == -1)
		return (free_struct_map(map), -1);
	return (0);
}

char	*read_file_into_string(char *file_path)
{
	int		fd;
	char	*buffer;
	size_t	size;
	ssize_t	bytes_readed;

	size = 10000;
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	buffer = malloc(sizeof(char) * size + 1);
	if (buffer == NULL)
		return (close(fd), display_error("Memory allocation failed\n"), NULL);
	bytes_readed = read(fd, buffer, size);
	if (bytes_readed < 0)
	{
		close(fd);
		free(buffer);
		display_error("Error reading file\n");
		return (NULL);
	}
	buffer[bytes_readed] = '\0';
	close(fd);
	return (buffer);
}
