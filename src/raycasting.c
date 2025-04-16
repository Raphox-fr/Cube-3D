/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:10:58 by aneumann          #+#    #+#             */
/*   Updated: 2025/04/16 13:00:27 by aneumann         ###   ########.fr       */
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
		ray->raydirx = ray->dirx + ray->planex * ray->camerax;
		ray->raydiry = ray->diry + ray->planey * ray->camerax;
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
	ray->mapx = (int)ray->posx;
	ray->mapy = (int)ray->posy;
	if (ray->raydirx < 0)
	{
		ray->stepx = -1;
		ray->sidedistx = (ray->posx - ray->mapx) * ray->deltadistx;
	}
	else
	{
		ray->stepx = 1;
		ray->sidedistx = (ray->mapx + 1.0 - ray->posx) * ray->deltadistx;
	}
	if (ray->raydiry < 0)
	{
		ray->stepy = -1;
		ray->sidedisty = (ray->posy - ray->mapy) * ray->deltadisty;
	}
	else
	{
		ray->stepy = 1;
		ray->sidedisty = (ray->mapy + 1.0 - ray->posy) * ray->deltadisty;
	}
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
