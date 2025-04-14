/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:53:33 by aneumann          #+#    #+#             */
/*   Updated: 2025/04/14 12:38:53 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int init_struct_ray(t_ray *ray)
{
	// return (-1);
	printf("mapp->x_player = %d\n", ray->mapp.x_player);
	printf("mapp->y_player = %d\n", ray->mapp.y_player);
	ray->posX = (double)ray->mapp.x_player+ 0.5; 
	ray->posY = (double)ray->mapp.y_player + 0.5;
	
	printf("posX = %f\n", ray->posX);
	printf("posY = %f\n", ray->posY);
	ray->key_w = 0;
	ray->key_a = 0;
	ray->key_s = 0;
	ray->key_d = 0;
	ray->key_l = 0;
	ray->key_r = 0;
	if (init_player(ray) == -1)
		return (display_error("init_player\n"), -1);
	ray->h = ray->height;
	return (0);
}

int	init_img(t_ray *ray)
{
	ray->img = malloc(sizeof(t_img));
	if (!ray->img)
		return (display_error("malloc img\n"), -1);

	ray->img->img = mlx_new_image(ray->mlx, ray->width, ray->height);
	if (!ray->img->img)
		return (display_error("mlx_new_image\n"), -1);

	ray->img->addr = mlx_get_data_addr(ray->img->img,
		&ray->img->bpp, &ray->img->line_length, &ray->img->endian);
	if (!ray->img->addr)
		return (display_error("mlx_get_data_addr\n"), -1);

	ray->img->width = ray->width;
	ray->img->height = ray->height;
	// printf("img->width = %d\n", ray->img->width);
	// printf("img->height = %d\n", ray->img->height);
	// return (-1);
	return (0);
}


int init_player(t_ray *ray)
{
	ray->axe = ray->mapp.player_directions;
	printf("axe = %c\n", ray->axe);
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