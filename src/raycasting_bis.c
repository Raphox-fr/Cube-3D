/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:00:12 by aneumann          #+#    #+#             */
/*   Updated: 2025/04/16 13:01:03 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void	ft_dda(t_ray *ray)
{
	ray->hit = 0;
	while (ray->hit == 0)
	{
		ft_advance_ray(ray);
		ft_check_hit(ray);
	}
	ft_calc_perp_dist(ray);
}

void	ft_advance_ray(t_ray *ray)
{
	if (ray->sidedistx < ray->sidedisty)
	{
		ray->sidedistx += ray->deltadistx;
		ray->mapx += ray->stepx;
		ray->side = 0;
	}
	else
	{
		ray->sidedisty += ray->deltadisty;
		ray->mapy += ray->stepy;
		ray->side = 1;
	}
}

void	ft_check_hit(t_ray *ray)
{
	if (ray->mapx >= 0 && ray->mapx < ray->size_x
		&& ray->mapy >= 0 && ray->mapy < ray->size_y
		&& ray->mapp.map_dis[ray->mapy][ray->mapx] == '1')
		ray->hit = 1;
}

void	ft_calc_perp_dist(t_ray *ray)
{
	if (ray->side == 0)
		ray->perpwalldist = (ray->mapx - ray->posx
				+ (1 - ray->stepx) / 2) / ray->raydirx;
	else
		ray->perpwalldist = (ray->mapy - ray->posy
				+ (1 - ray->stepy) / 2) / ray->raydiry;
}
