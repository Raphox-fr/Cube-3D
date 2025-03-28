/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:05:07 by rafaria           #+#    #+#             */
/*   Updated: 2025/03/28 20:06:32 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int check_map(t_struct *map, char *file_path)
{
	int i;
	int fd;
	char *string_map;

	map->file_path = read_file_into_string(file_path);
	map->map_table = ft_split(map->file_path, '\n');

	if (find_every_txture_in_map(map, map->map_table, "str") == -1 
        || check_access_every_txture(map) == -1)
	{
		display_error("Invalid texture's path or not every textures found in the map\n");
		free_struct_map(map);
		return (-1);
	}
    
    
    

	printf("NO =%s\n", map->no_txture);
	printf("SO =%s\n", map->so_txture);
	printf("WE =%s\n", map->we_txture);
	printf("EA =%s\n", map->ea_txture);
    free_struct_map(map); //FREE FIN DISPLAY
	
	return (0);
}

int check_access_every_txture(t_struct *map)
{
	int i;

	i = 0;
	
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
int check_access_txture(char *path_txture)
{
    int fd;
    
    fd = open(path_txture, O_RDONLY);
    if (fd < 0)
    {
        return (-1);
    }
    close(fd);
    return (1);
}















int find_every_txture_in_map(t_struct *map, char **map_table, char *str)
{
	int i;

	i = 0;
	int count;
	count = 0;
	
	if (find_txture(map, map_table, "NO") == 1)
		count++;
	if (find_txture(map, map_table, "SO") == 1)
		count++;
	if (find_txture(map, map_table, "WE") == 1)
		count++;
	if (find_txture(map, map_table, "EA") == 1)
		count++;
		
	if (count == 4)
		return (1);
	return (-1);
}

int find_txture(t_struct *map, char **map_table, char *directions)
{
	int i;
	i = 0;

	while (map_table[i])
	{
		if (ft_strnstr(map_table[i], directions, ft_strlen_size_t(map_table[i])) != 0)
		{
			if (check_parsing_direction(map, map_table[i], directions) == 1)
				return (1);
		}
		i++;
	}
	return (-1);
	
	
}

int check_parsing_direction(t_struct *map, char *map_string, char *directions)
{
	int i;

	i = 0;
	if (map_string != NULL)
	{
		while(*map_string == ' ' || *map_string == '	')
			map_string++;
		if (*map_string == directions[0] && *(map_string + 1) == directions[1])
		{
			map_string = map_string + 3;
			while((*map_string == ' ' || *map_string == '	') && *map_string != '\0')
				map_string++;
			if (directions[0] == 'N' && directions[1] == 'O')
				map->no_txture = ft_strdup(map_string);
			if (directions[0] == 'S' && directions[1] == 'O')
				map->so_txture = ft_strdup(map_string);
			if (directions[0] == 'W' && directions[1] == 'E')
				map->we_txture  = ft_strdup(map_string);
			if (directions[0] == 'E' && directions[1] == 'A')
				map->ea_txture =  ft_strdup(map_string);
			return (1);		
		}
	}
	
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
	
	