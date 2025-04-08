/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 19:34:55 by rafaria           #+#    #+#             */
/*   Updated: 2025/04/08 19:51:26 by aneumann         ###   ########.fr       */
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
	map->floor[0] = 0;
	map->floor[1] = 0;
	map->floor[2] = 0;
	map->ceiling[0] = 0;
	map->ceiling[1] = 0;
	map->ceiling[2] = 0;

	return (0);
}

int init_struct_ray(t_ray *ray)
{
	ray->mlx = mlx_init();
	mlx_get_screen_size(ray->mlx, &ray->width, &ray->height);
	ray->win = mlx_new_window(ray->mlx, ray->width, ray->height, "Cub3D");
	ray->key_w = 0;
	ray->key_a = 0;	
	ray->key_s = 0;
	ray->key_d = 0;	
	ray->key_l = 0;
	ray->key_r = 0;
	if (!init_player(ray))
		return (printf("Error\ninit_player\n"), -1);
	return (0);
}

int init_player(t_ray *ray)
{
	if (ray->axe == 'N')
	{
		ray->dirX = 0;
		ray->dirY = -1;
		ray->planeX = 0.66;
		ray->planeY = 0;
	}
	else if (ray->axe == 'S')
	{
		ray->dirX = 0;
		ray->dirY = 1;
		ray->planeX = -0.66;
		ray->planeY = 0;
	}
	else if (ray->axe == 'E')
	{
		ray->dirX = 1;
		ray->dirY = 0;
		ray->planeX = 0;
		ray->planeY = -0.66;
	}
	else if (ray->axe == 'W')
	{
		ray->dirX = -1;
		ray->dirY = 0;
		ray->planeX = 0;
		ray->planeY = 0.66;
	}
	else
    	return (printf("Error\ninvalid orientation '%c'\n", ray->axe), -1);
	
	//ray->posX = ray->data->x + 0.5; 
	//ray->posY = ray->data->y + 0.5;
		
	// ray->size_x = ray->size_x / 2;
	// ray->size_y = ray->size_y / 2;
	return (0);
}

