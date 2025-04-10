/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 19:34:55 by rafaria           #+#    #+#             */
/*   Updated: 2025/04/10 15:27:09 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int	init_struct_map(t_struct *map)
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
	map->x_zero = 0;
	map->y_zero = 0;
	map->brut_map_only = NULL;
	map->hex_floor = 0;
	map->hex_ceiling = 0;
}
