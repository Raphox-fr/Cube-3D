/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 19:34:55 by rafaria           #+#    #+#             */
/*   Updated: 2025/03/28 19:35:05 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int init_struct_map(t_struct *map)
{
	map->file_path = NULL;
	map->map = NULL;
	map->map_table = NULL;
	map->player = '0';
	map->no_txture = NULL;
	map->so_txture = NULL;
	map->we_txture = NULL;
	map->ea_txture = NULL;
	map->floor_color[0] = 0;
	map->floor_color[1] = 0;
	map->floor_color[2] = 0;
	map->ceiling_color[0] = 0;
	map->ceiling_color[1] = 0;
	map->ceiling_color[2] = 0;
	return (0);
}