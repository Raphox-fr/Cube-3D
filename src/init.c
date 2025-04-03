/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 19:34:55 by rafaria           #+#    #+#             */
/*   Updated: 2025/04/03 12:14:32 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int init_struct_map(t_struct *map)
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
	map->first_line_after_infos = 0;
	map->first_line_map = 0;
	map->brut_map_only = NULL;
}
