/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 19:34:55 by rafaria           #+#    #+#             */
/*   Updated: 2025/04/16 14:28:53 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void	init_struct_map(t_struct *map)
{
	map->file_path = NULL;
	map->map = NULL;
	map->map_table = NULL;
	map->x_player = -1;
	map->y_player = -1;
	map->no_txture = NULL;
	map->so_txture = NULL;
	map->we_txture = NULL;
	map->ea_txture = NULL;
	map->floor[0] = 0;
	map->floor[1] = 0;
	map->floor[2] = 0;
	map->ceiling[0] = 0;
	map->ceiling[1] = 0;
	map->ceiling[2] = 0;
	init_v2(map);
}

void	init_v2(t_struct *map)
{
	map->err_malloc = 0;
	map->map_dis = NULL;
	map->first_line_after_infos = 0;
	map->x_zero = 0;
	map->y_zero = 0;
	map->brut_map_only = NULL;
	map->hex_floor = 0;
	map->hex_ceiling = 0;
	map->error = 0;
	map->map_only = NULL;
	map->map_brut = NULL;
}
