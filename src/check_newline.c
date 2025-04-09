/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_newline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:43:44 by rafaria           #+#    #+#             */
/*   Updated: 2025/04/09 17:29:49 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int	check_newline_map(t_struct *map)
{
	if (find_last_elements(map) == -1)
		return (-1);
	replace_space_with_wall(map);
	if (check_no_newline(map) == -1)
		return (-1);
	// map_for_display
	return (1);
}

int	check_no_newline(t_struct *map)
{
	int	i;

	i = 0;
	while (map->brut_map_only[i] != '1' && map->brut_map_only[i] != '\0')
	{
		i++;
	}
	while ((map->brut_map_only[i] == '1' || map->brut_map_only[i] == '0'
			|| map->brut_map_only[i] == 'N' || map->brut_map_only[i] == 'S'
			|| map->brut_map_only[i] == 'E' || map->brut_map_only[i] == 'W'
			|| map->brut_map_only[i] == '\n') && map->brut_map_only[i] != '\0')
	{
		i++;
		if (map->brut_map_only[i] == '\n' && map->brut_map_only[i - 1] == '\n')
			break ;
	}
	while (map->brut_map_only[i])
	{
		if (map->brut_map_only[i] != '\n')
		{
			display_error("Invalid characters inside map\n");
			return (-1);
		}
		i++;
	}
	return (1);
}

int	find_last_elements(t_struct *map)
{
	int		i;
	char	*start;

	i = 0;
	start = "";
	if (ft_strnstr(map->map_brut, map->map_table[5],
			ft_strlen_size_t(map->map_brut)) != 0)
	{
		start = ft_strnstr(map->map_brut, map->map_table[5],
				ft_strlen_size_t(map->map_brut));
		map->brut_map_only = start + ft_strlen(map->map_table[5]);
		return (1);
	}
	return (-1);
}

void	replace_space_with_wall(t_struct *map)
{
	int	i;

	i = 0;
	while (map->brut_map_only[i])
	{
		if (map->brut_map_only[i] == ' ')
		{
			map->brut_map_only[i] = '1';
		}
		i++;
	}
}
