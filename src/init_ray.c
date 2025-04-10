/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:53:33 by aneumann          #+#    #+#             */
/*   Updated: 2025/04/10 18:12:44 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int init_struct_ray(t_ray *ray)
{
	ray->posX = ray->mapp->x_player + 0.5; 
	ray->posY = ray->mapp->y_player + 0.5;	
	ray->key_w = 0;
	ray->key_a = 0;	
	ray->key_s = 0;
	ray->key_d = 0;	
	ray->key_l = 0;
	ray->key_r = 0;
	if (!init_player(ray))
		return (printf("Error\ninit_player\n"), -1);
	ray->h = ray->height;
	return (0);
}

int init_player(t_ray *ray)
{
	if (ray->axe == 'N')
		ft_init_player_N(ray);
	else if (ray->axe == 'S')
		ft_init_player_S(ray);
	else if (ray->axe == 'E')
	{
		ray->dirX = 1;
		ray->dirY = 0;
		ray->planeX = 0;
		ray->planeY = -0.66;
	}
	else if (ray->axe ==  'W')
	{
		ray->dirX = -1;
		ray->dirY = 0;
		ray->planeX = 0;
		ray->planeY = 0.66;
	}
	else
    	return (printf("Error\ninvalid orientation '%c'\n", ray->axe), -1);

	ray->size_x = ray->size_x / 2;
	ray->size_y = ray->size_y / 2;
	return (0);
}

void ft_init_player_N(t_ray *ray)
{
	ray->dirX = 0;
	ray->dirY = -1;
	ray->planeX = 0.66;
	ray->planeY = 0;
}

void ft_init_player_S(t_ray *ray)
{
	ray->dirX = 0;
	ray->dirY = 1;
	ray->planeX = -0.66;
	ray->planeY = 0;
}