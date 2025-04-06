/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:32:57 by rafaria           #+#    #+#             */
/*   Updated: 2025/04/06 18:07:02 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int	check_floor_ceiling_in_map(t_struct *map, char **map_table)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (find_floor_ceiling(map, map_table, "F ") == 1)
	{
		printf("map_floor=%d\n", map->floor[0]);
		printf("map_floor=%d\n", map->floor[1]);
		printf("map_floor=%d\n", map->floor[2]);
		map->hex_floor = rgb_to_hex(map->floor[0], map->floor[1],
				map->floor[2]);
		count++;
	}
	if (find_floor_ceiling(map, map_table, "C ") == 1)
	{
		printf("map_ceiling=%d\n", map->ceiling[0]);
		printf("map_ceiling=%d\n", map->ceiling[1]);
		printf("map_ceiling=%d\n", map->ceiling[2]);
		map->hex_ceiling = rgb_to_hex(map->ceiling[0], map->ceiling[1],
				map->ceiling[2]);
		count++;
	}
	if (count == 2)
		return (1);
	return (-1);
}
int	rgb_to_hex(int r, int g, int b)
{
	int	hex_color;

	hex_color = (r << 16) | (g << 8) | b;
	return (hex_color);
}

int	find_floor_ceiling(t_struct *map, char **map_table, char *letter)
{
	int	i;

	i = 0;
	while (map_table[i])
	{
		if (ft_strnstr(map_table[i], letter,
				ft_strlen_size_t(map_table[i])) != 0)
		{
			if (i >= map->first_line_after_infos)
				map->first_line_after_infos = i;
			if (letter[0] == 'C')
				map->ceiling_brut = map_table[i];
			if (save_rgb(map, map_table[i], letter) == 1)
			{
				return (1);
			}
		}
		i++;
	}
	return (-1);
}

int	save_rgb(t_struct *map, char *map_string, char *letter)
{
	int	i;

	i = 0;
	printf("%sFOUND :\n", letter);
	if (map_string != NULL)
	{
		while (*map_string == ' ' || *map_string == '	')
			map_string++;
		if (*map_string == letter[0])
		{
			map_string = map_string + 2;
			while ((*map_string == ' ' || *map_string == '	')
					&& *map_string != '\0')
				map_string++;
			if (verify_rgb(map, map_string, letter) == -1)
				return (-1);
			else
			{
				return (1);
			}
		}
	}
	return (-1);
}

int	verify_rgb(t_struct *map, char *map_string, char *letter)
{
	int		j;
	char	**split_result;

	j = 0;
	split_result = ft_split(map_string, ',');
	while (split_result[j])
	{
		printf("value=%s\n", split_result[j]);
		if (ft_isalnum_inferior_255(split_result[j]) == -1
			|| count_characters(map_string) == -1)
		{
			free_split(split_result);
			return (-1);
		}
		j++;
	}
	if (j != 3)
	{
		free_split(split_result);
		return (-1);
	}
	if (letter[0] == 'F')
	{
		map->floor[0] = ft_atoi(split_result[0]);
		map->floor[1] = ft_atoi(split_result[1]);
		map->floor[2] = ft_atoi(split_result[2]);
	}
	if (letter[0] == 'C')
	{
		map->ceiling[0] = ft_atoi(split_result[0]);
		map->ceiling[1] = ft_atoi(split_result[1]);
		map->ceiling[2] = ft_atoi(split_result[2]);
	}
	free_split(split_result);
	return (1);
}

int	ft_isalnum_inferior_255(char *str)
{
	int	i;

	i = 0;
	if (str[i] == 0)
		return (-1);
	while (str[i])
	{
		if (((str[i]) < '0' || str[i] > '9') && (str[i] != ' '
				&& str[i] != '\t'))
			return (-1);
		if (atoi(str) < 0 || atoi(str) > 255)
			return (-1);
		i++;
	}
	return (1);
}
int	count_characters(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if ((str[i]) == ',')
			count++;
		i++;
	}
	if (count != 2)
		return (-1);
	return (1);
}

// if (letter[0] == 'F')
// 	map->no_txture = ft_strdup(map_string);
// if (letter[0] == 'C')
// 	map->so_txture = ft_strdup(map_string);

// faire un flood fill dans la map pour voir si la map est close
// verifier si le joueur est present dans la map
// et ensuite verifier s il y a des 0 autour de la map et si oui,
	// s il sont entourer par des murs,
// remplacer les espaces vides par un mur.

// verifier il ya des murs
// verifier si ya un seul joueur
// retour a la ligne non auttorisers
// verifier si la map est le dernier carateres du fichier