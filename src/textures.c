/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 20:08:03 by rafaria           #+#    #+#             */
/*   Updated: 2025/03/31 11:47:13 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int check_access_txture(char *path_txture)
{
    int fd;

	// if (check_last_part_txture_found(path_txture) == -1)
	// 	return (-1);
    
    fd = open(path_txture, O_RDONLY);
    if (fd < 0)
    {
        return (-1);
    }
    close(fd);
    return (1);
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

int find_every_txture_in_map(t_struct *map, char **map_table, char *str)
{
    int i;
    
	i = 0;
	int count;
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
            if (check_found_txture(map, map_table[i], directions) == 1)
            return (1);
		}
		i++;
	}
	return (-1);
}

int check_found_txture(t_struct *map, char *map_string, char *directions)
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
    
    //     while ((path_txture[i] != ' ' && path_txture[i] != '	') && path_txture[i] != '\0')
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