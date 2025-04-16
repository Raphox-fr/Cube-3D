/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:32:57 by rafaria           #+#    #+#             */
/*   Updated: 2025/04/16 14:24:18 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int	check_floor_ceiling_in_map(t_struct *map, char **map_table)
{
	int	count;

	count = 0;
	if (find_floor_ceiling(map, map_table, "F ") == 1)
	{
		map->hex_floor = rgb_to_hex(map->floor[0], map->floor[1],
				map->floor[2]);
		count++;
	}
	if (find_floor_ceiling(map, map_table, "C ") == 1)
	{
		map->hex_ceiling = rgb_to_hex(map->ceiling[0], map->ceiling[1],
				map->ceiling[2]);
		count++;
	}
	if (count != 2)
	{
		display_error("Invalid RGB color or missing floor or ceiling\n");
		return (-1);
	}
	return (1);
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
// || ft_strlen(split_result[j]) >= 4

int	verify_rgb(t_struct *map, char *map_string, char *letter)
{
	int		j;
	char	**split_result;
	int		*target;

	j = -1;
	split_result = ft_split(map_string, ',');
	if (split_result == NULL)
		return (-1);
	while (split_result[++j])
	{
		if (check_value_syntax_rgb(split_result[j]) == -1
			|| count_characters(map_string, ',') == -1)
			return (free_split(split_result), -1);
	}
	if (j != 3)
		return (free_split(split_result), -1);
	if (letter[0] == 'F')
		target = map->floor;
	else if (letter[0] == 'C')
		target = map->ceiling;
	target[0] = ft_atoi(split_result[0]);
	target[1] = ft_atoi(split_result[1]);
	target[2] = ft_atoi(split_result[2]);
	free_split(split_result);
	return (1);
}

int	check_value_syntax_rgb(char *str)
{
	int	i;

	i = 0;
	if (str[i] == 0)
		return (-1);
	if (count_number(str) == -1)
		return (-1);
	while (str[i])
	{
		if (((str[i]) < '0' || str[i] > '9') && (str[i] != ' '))
			return (-1);
		if (atoi(str) < 0 || atoi(str) > 255)
			return (-1);
		i++;
	}
	if (verify_syntax_rgb(str) == -1)
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