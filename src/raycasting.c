/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:10:58 by aneumann          #+#    #+#             */
/*   Updated: 2025/04/16 12:49:19 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void	ft_raycast(t_ray *ray)
{
	double	x;

	ray->size_x = ray->width;
	ray->size_y = ray->height;
	x = 0;
	while (x < ray->size_x)
	{
		ray->camerax = 2 * x / (double)ray->size_x - 1;
		ray->raydirx = ray->dirx + ray->planeX * ray->camerax;
		ray->raydiry = ray->diry + ray->planeY * ray->camerax;
		ray->deltadistx = fabs(1 / ray->raydirx);
		ray->deltadisty = fabs(1 / ray->raydiry);
		ft_distance(ray);
		ft_dda(ray);
		ft_height(ray);
		ft_display(ray, x);
		x++;
	}
}

void	ft_distance(t_ray *ray)
{
	ray->mapX = (int)ray->posx;
	ray->mapY = (int)ray->posy;
	if (ray->raydirx < 0)
	{
		ray->stepx = -1;
		ray->sidedistx = (ray->posx - ray->mapX) * ray->deltadistx;
	}
	else
	{
		ray->stepx = 1;
		ray->sidedistx = (ray->mapX + 1.0 - ray->posx) * ray->deltadistx;
	}
	if (ray->raydiry < 0)
	{
		ray->stepy = -1;
		ray->sidedisty = (ray->posy - ray->mapY) * ray->deltadisty;
	}
	else
	{
		ray->stepy = 1;
		ray->sidedisty = (ray->mapY + 1.0 - ray->posy) * ray->deltadisty;
	}
}

void	ft_dda(t_ray *ray)
{
	ray->hit = 0;
	while (ray->hit == 0)
	{
		if (ray->sidedistx < ray->sidedisty)
		{
			ray->sidedistx += ray->deltadistx;
			ray->mapX += ray->stepx;
			ray->side = 0;
		}
		else
		{
			ray->sidedisty += ray->deltadisty;
			ray->mapY += ray->stepy;
			ray->side = 1;
		}
		if (ray->mapX >= 0 && ray->mapX < ray->size_x && ray->mapY >= 0
			&& ray->mapY < ray->size_y
			&& ray->mapp.map_dis[ray->mapY][ray->mapX] == '1')
		{
			if (ray->mapp.map_dis[ray->mapY][ray->mapX] == '1')
				ray->hit = 1;
		}
	}
	if (ray->side == 0)
		ray->perpwalldist = (ray->mapX - ray->posx + (1 - ray->stepx) / 2)
			/ ray->raydirx;
	else
		ray->perpwalldist = (ray->mapY - ray->posy + (1 - ray->stepy) / 2)
			/ ray->raydiry;
}

void	ft_height(t_ray *ray)
{
	ray->h = ray->size_y;
	ray->lineheight = (int)(ray->h / ray->perpwalldist);
	ray->drawstart = -ray->lineheight / 2 + ray->h / 2;
	if (ray->drawstart < 0)
		ray->drawstart = 0;
	ray->drawend = ray->lineheight / 2 + (ray->h / 2);
	if (ray->drawend >= ray->h)
		ray->drawend = ray->h - 1;
}

// void ft_dda(t_ray *ray)
// {
//     ray->hit = 0;
//     while (ray->hit == 0)
//     {
//         if (ray->sidedistx < ray->sidedisty)
//         {
//             ray->sidedistx += ray->deltadistx;
//             ray->mapX += ray->stepx;
//             ray->side = 0;
//         }
//         else
//         {
//             ray->sidedisty += ray->deltadisty;
//             ray->mapY += ray->stepy;
//             ray->side = 1;
//         }
//         if (ray->mapX >= 0 && ray->mapX < ray->size_x
//             && ray->mapY >= 0 && ray->mapY < ray->size_y
//             && ray->map[ray->mapX][ray->mapY] == '1')
//             ray->hit = 1;
//     }
//     if (ray->side == 0)
//         ray->perpwalldist = (ray->mapX - ray->posx + (1 - ray->stepx) / 2)
// ray->raydirx;
//     else
//         ray->perpwalldist = (ray->mapY - ray->posy + (1 - ray->stepy) / 2)
// ray->raydiry;
// }
