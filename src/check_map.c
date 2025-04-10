/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:05:07 by rafaria           #+#    #+#             */
/*   Updated: 2025/04/10 18:54:20 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int check_map(t_struct *map, char *file_path)
{
	map->file_path = file_path;
	map->map_brut = read_file_into_string(file_path);
	if (map->map_brut == NULL)
		return (display_error("Error reading file\n"), -1);
	map->map_table = ft_split(map->map_brut, '\n');
	if (map->map_table == NULL)
		return (display_error("Memory allocation failed\n"), -1);
	if (find_every_txture_in_map(map, map->map_table) == -1 
        || check_access_every_txture(map) == -1)
		return (free_struct_map(map), -1);
    if (check_floor_ceiling_in_map(map, map->map_table) == -1)
		return (free_struct_map(map), -1);
	map->first_line_after_infos = map->first_line_after_infos + 1;
    if (check_map_layout(map) == -1)
		return (free_struct_map(map), -1);
    // free_struct_map(map); //FREE FIN DISPLAY
	return (0);
}


char *read_file_into_string(char *file_path)
{
	int fd;
	char *buffer;
	size_t size;
	ssize_t bytes_readed;
	
	size = 10000;
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	buffer = malloc(sizeof(char) * size + 1);
	if (buffer == NULL)
	{
		close(fd);
		display_error("Memory allocation failed\n");
		return (NULL);
	}
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

	

// display_error("Invalid texture's path / missing textures / invalid extension in the map's textures\n");

// display_error("Invalid RGB color / missing floor or ceiling\n");
// printf("NO =%s\n", map->no_txture);
// printf("SO =%s\n", map->so_txture);
// printf("WE =%s\n", map->we_txture);
// printf("EA =%s\n", map->ea_txture);

// printf("Check Map Layout ---------------------------------------------\n");
// printf("first_line_after_infos =%d\n", map->first_line_after_infos);
// printf("String of first_line_after_infos =%s\n", map->map_table[map->first_line_after_infos]);
// printf("---------------------------------------------\n");
// display_error("Invalid map / not surrounded with walls / not last element \n");
	